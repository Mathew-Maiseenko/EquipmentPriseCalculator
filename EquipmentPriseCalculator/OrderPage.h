#pragma once
#include "EquipmentPriceCalculator.h"
#include <msclr\auto_gcroot.h>
#include <msclr\marshal.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowEquipmentListInOrderPageEquipmentGrid()
{
    GlobalList Storage = this->GlobalStorage;

    this->OrderPage_EquipmentDataGrid->Rows->Clear();

    DataGridView^ EquipmentGrid = this->OrderPage_EquipmentDataGrid;


    std::vector<Equipment> EquipmentList;

    String^ selectedItem = dynamic_cast<String^>(this->OrderPage_EquipmentSortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        EquipmentList = this->GlobalStorage.SortEquipmentList(selectedItem);
    }
    else
    {
        EquipmentList = Storage.getEquipmentList();
    }


    if (this->OrderPage_EquipmentSearchTextBox->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->OrderPage_EquipmentSearchTextBox->Text);
        EquipmentList = Storage.getFilteredEquipmentListBySubStr(filterDetailsStr, EquipmentList);
    }

    for (int i = 0; i < EquipmentList.size(); i++)
    {
        String^ DetailId = EquipmentList.at(i).id.ToString();
        String^ DetailName = gcnew String(EquipmentList.at(i).Name.c_str());
        String^ DetailPrice = Storage.getTotalEquipmentPrice(EquipmentList.at(i), &Storage).ToString();

        List<String^>^ EquipmentInfoRow = gcnew List<String^>();
        EquipmentInfoRow->Add(DetailId);
        EquipmentInfoRow->Add(DetailName);
        EquipmentInfoRow->Add(DetailPrice);

        array<String^>^ EquipmentInfoArray = EquipmentInfoRow->ToArray();
        EquipmentGrid->Rows->Add(EquipmentInfoArray);
    }

    EquipmentGrid->Refresh();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_EquipmentSearchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInOrderPageEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_EquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInOrderPageEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_VisibleChanged(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInOrderPageEquipmentGrid();
    return System::Void();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_EquipmentGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ EquipmentGrid = this->OrderPage_EquipmentDataGrid;
        System::Windows::Forms::DataGridView::HitTestInfo^ hit = EquipmentGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;

            // ������� ����� ����������� ����
            System::Windows::Forms::ContextMenuStrip^ menu = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("��������");
            deleteDetail->Tag = rowIndex; // ��������� ������ ������ � Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderEquipment_onClick);
            menu->Items->Add(deleteDetail);

            // ���������� ������� Opening ��� ���������� Tag
            menu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentList_deletingContextMenu_Opening);

            // ����������� ����� ����������� ����
            EquipmentGrid->ContextMenuStrip = menu;
            menu->Show(EquipmentGrid, e->Location); // ���������� ����������� ����
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_EquipmentList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // ��������� Tag �������� ����
            DataGridView^ DetailsGrid = this->EquipmentListPage_DataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;
            }
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderEquipment_onClick(System::Object^ sender, System::EventArgs^ e)
{
    ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
    if (menuItem != nullptr) {
        DataGridView^ DetailsGrid = this->EquipmentListPage_DataGrid;
        int rowIndex = safe_cast<int>(menuItem->Tag);
        String^ name = DetailsGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
        msclr::interop::marshal_context context;
        std::string EquipmentNameStr = context.marshal_as<std::string>(name);
        // ��� ��� ��� �������� ������ �� rowIndex
        //MessageBox::Show("�������� ������: " + rowIndex.ToString());


        this->GlobalStorage.addEquipmentToOrderListByName(EquipmentNameStr);
        ShowEquipmentListInOrderPageEquipmentGrid();



        // ������������ �� �������
        //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
    }
    return System::Void();
}

//////////////////////////////////////////////////////////////////////////////

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_ShowEquipmentListInOrderedEquipmentGrid()
{
    this->OrderPage_OrderedEquipmentDataGrid->Rows->Clear();

    DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;

    GlobalList Storage = this->GlobalStorage;
    std::vector<OrderedEquipment> ComponentsList;

    String^ selectedItem = dynamic_cast<String^>(this->OrderPage_OrderedEquipmentSortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        ComponentsList = this->GlobalStorage.getSortedOrderedEquipmentList(selectedItem);
    }
    else
    {
        ComponentsList = Storage.getOrderedEquipmentList();
    }


    if (this->AddingEquipmentPage_ComponentsListSearchInput->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->OrderPage_OrderedEquipmentSearchTextBox->Text);
        ComponentsList = Storage.getFilteredOrderedEquipmentListBySubStr(filterDetailsStr, ComponentsList);
    }
    //std::string filterDetailsStr = msclr::interop::marshal_as<std::string>(this->detailsNameFilterString->ToString());



    for (int i = 0; i < ComponentsList.size(); i++)
    {
        String^ DetailId = ComponentsList.at(i).equip.id.ToString();
        String^ DetailName = gcnew String(ComponentsList.at(i).equip.Name.c_str());
        String^ DetailCost = Storage.getTotalEquipmentPrice(ComponentsList.at(i).equip, &Storage).ToString();
        String^ DetailCount = ComponentsList.at(i).equipmentsCount.ToString();
        String^ DetailTotalPrice = (Storage.getTotalEquipmentPrice(ComponentsList.at(i).equip, &Storage) * ComponentsList.at(i).equipmentsCount).ToString();

        array<String^>^ DetailInfoRow = { "-", "+" ,DetailId,  DetailName , DetailCount, DetailCost, DetailTotalPrice };
        DetailsGrid->Rows->Add(DetailInfoRow);
    }

    DetailsGrid->Refresh();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentSearchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;

    if (e->ColumnIndex == 0)
    {
        int curComponentsCount = Convert::ToInt64(DetailsGrid->Rows[e->RowIndex]->Cells[4]->Value);
        String^ ComponentsNameSTRING = safe_cast<String^>(DetailsGrid->Rows[e->RowIndex]->Cells[3]->Value);
        std::string ComponentsName = msclr::interop::marshal_as<std::string>(ComponentsNameSTRING);
        if (curComponentsCount > 1)
        {
            this->GlobalStorage.decrementCountOfOrderedEquipmentByName(ComponentsName);
            OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
        }
        else {
            this->GlobalStorage.removeOrderedEquipmentByName(ComponentsName);
            OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
        }

    }
    if (e->ColumnIndex == 1)
    {
        String^ ComponentsNameSTRING = safe_cast<String^>(DetailsGrid->Rows[e->RowIndex]->Cells[3]->Value);
        std::string ComponentsName = msclr::interop::marshal_as<std::string>(ComponentsNameSTRING);
        this->GlobalStorage.incrementCountOfOrderedEquipmentByName(ComponentsName);
        OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
    }

    return System::Void();
}



inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;

    int curColumnIndex = e->ColumnIndex;
    int curRowIndex = e->RowIndex;

    if (DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value != nullptr)
    {
        String^ newValue = DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString();

        msclr::interop::marshal_context context;

        std::string newValueStd = context.marshal_as<std::string>(newValue);
        String^ newComponentsName = safe_cast<String^>(DetailsGrid->Rows[curRowIndex]->Cells[3]->Value);
        std::string newComponentsNameStd = msclr::interop::marshal_as<std::string>(newComponentsName);
        //std::string newValueStd = msclr::interop::marshal_as<std::string>(newValue);
        //std::string newComponentsNameStd = msclr::interop::marshal_as<std::string>(DetailsGrid->Rows[curRowIndex]->Cells[3]->Value);
        //int newComponentsCount = context.marshal_as<int>(DetailsGrid->Rows[curRowIndex]->Cells[4]->Value);

        String^ ComponentsCountSTRING = safe_cast<String^>(DetailsGrid->Rows[curRowIndex]->Cells[4]->Value);
        std::string ComponentsCountStd = msclr::interop::marshal_as<std::string>(ComponentsCountSTRING);

        boolean isCorrect = true; ///��������

        if (curColumnIndex != 4)
        {
            isCorrect = false;
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;

            string errorMessage = "����� �������� ������ ����������� ���������� �����������!";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (!this->GlobalStorage.is_number(ComponentsCountStd))
        {
            isCorrect = false;
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;

            string errorMessage = "���������� ������� ���� ������";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (newValueStd.size() >= 15) {
            isCorrect = false;
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
            string errorMessage = "��������� �������� ������� ������";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }


        if (isCorrect)
        {
            //MessageBox::Show(gcnew String(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString()));
            int newComponentsCount = Convert::ToInt64(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value);
            this->GlobalStorage.editCountOfTheEquipmentsComponentByName(newComponentsNameStd, newComponentsCount);
            AddingEquipmentPage_ShowComponentsListInGrid();
        }
    }
    else
    {
        msclr::interop::marshal_context context;
        string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
        System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
        DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
        string errorMessage = "�������� � ������ �� ����� ���� ������!\n ���� �� ������ ������� �����-���� ������� - ������� �� ���� ������ ������� ���� � �������� ����� \"�������\"";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
    }

    return System::Void();
}
