#pragma once
#include "EquipmentPriceCalculator.h"
#include "GlobalList.h"
#include "DetailAddingWindow.h"

using namespace System;
using namespace System::Windows::Forms;

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OnLoad_DetailsListPage(System::Object^ sender, System::EventArgs^ e)
{
    this->ShowDetailsListInDetailsGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::onSelectDetailsListSortType(System::Object^ sender, System::EventArgs^ e)
{
    this->ShowDetailsListInDetailsGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowDetailsListInDetailsGrid()
{
    this->DetailsListPage_DataGrid->Rows->Clear();

    DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;

    GlobalList Storage = this->GlobalStorage;
    std::vector<Detail> DetailList;

    String^ selectedItem = dynamic_cast<String^>(this->DetailsListPage_SortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        DetailList = this->GlobalStorage.SortDetailsList(selectedItem);
    }
    else
    {
        DetailList = Storage.getDetailList();
    }


    if (this->DetailsListPage_SearchInput->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->DetailsListPage_SearchInput->Text);
        DetailList = Storage.getFilteredDetailsListBySubStr(filterDetailsStr, DetailList);
    }
    //std::string filterDetailsStr = msclr::interop::marshal_as<std::string>(this->detailsNameFilterString->ToString());



    for (int i = 0; i < DetailList.size(); i++)
    {
        String^ DetailId = DetailList.at(i).id.ToString();
        String^ DetailName = gcnew String(DetailList.at(i).Name.c_str());
        String^ DetailCost = DetailList.at(i).costs.ToString();

        array<String^>^ DetailInfoRow = { DetailId,  DetailName , DetailCost };
        DetailsGrid->Rows->Add(DetailInfoRow);
    }

    DetailsGrid->Refresh();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;

        System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;

            SelectRow(DetailsGrid, rowIndex);

            // ������� ����� ����������� ����
            System::Windows::Forms::ContextMenuStrip^ menu = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("�������");
            deleteDetail->Tag = rowIndex; // ��������� ������ ������ � Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
            menu->Items->Add(deleteDetail);

            // ���������� ������� Opening ��� ���������� Tag
            menu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::DetailsList_deletingContextMenu_Opening);

            // ����������� ����� ����������� ����
            DetailsGrid->ContextMenuStrip = menu;
            menu->Show(DetailsGrid, e->Location); // ���������� ����������� ����
        }
    }
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // ��������� Tag �������� ����
            DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;

                if (hit->RowIndex >= 0 && hit->RowIndex < DetailsGrid->Rows->Count) {
                    DetailsGrid->ClearSelection();
                    DetailsGrid->Rows[hit->RowIndex]->Selected = true;
                    DetailsGrid->CurrentCell = DetailsGrid->Rows[hit->RowIndex]->Cells[0];
                }
            }
        }
    }
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::deleteDetail_onClick(System::Object^ sender, System::EventArgs^ e)
{


    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show(
        "�� ������� ��� ������ ������� ��� ������?\n������ �������� �������� � �������� ����� ������������ �������� ������ ������ � ����� �������!", 
        "Confirmation", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
        if (menuItem != nullptr) {
            DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
            int rowIndex = safe_cast<int>(menuItem->Tag);
            String^ name = DetailsGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
            msclr::interop::marshal_context context;
            std::string DetailNameStr = context.marshal_as<std::string>(name);
            // ��� ��� ��� �������� ������ �� rowIndex
            //MessageBox::Show("�������� ������: " + rowIndex.ToString());
            this->GlobalStorage.removeDetailByName(DetailNameStr);
            ShowDetailsListInDetailsGrid();
            // ������������ �� �������
            //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
        }
    }
    else {

    }
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;

    int curColumnIndex = e->ColumnIndex;
    int curRowIndex = e->RowIndex;

    if (DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value != nullptr)
    {
        String^ newValue = DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString();
        std::string newValueStd = msclr::interop::marshal_as<std::string>(newValue);

        boolean isCorrect = true;

        if (curColumnIndex == 2 && !this->GlobalStorage.is_number(newValueStd))
        {
            isCorrect = false;
            string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
            System::String^ oldValueCs = msclr::interop::marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
            string errorMessage = "���� ������� ���� ������";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (newValueStd.size() >= 30) {
            isCorrect = false;
            string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
            System::String^ oldValueCs = msclr::interop::marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
            string errorMessage = "��������� �������� ������� ������";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }


        if (isCorrect)
        {
            this->GlobalStorage.editDetailsInfoByOldName(curColumnIndex, curRowIndex, newValueStd);
        }
    }
    else
    {
        string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
        System::String^ oldValueCs = msclr::interop::marshal_as<System::String^>(oldValue);
        DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
        string errorMessage = "�������� � ������ �� ����� ���� ������!\n ���� �� ������ ������� �����-���� ������� - ������� �� ���� ������ ������� ���� � �������� ����� \"�������\"";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
    }


    return System::Void();
}


//inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsGrid_AddingDetail(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e)
//{
//    DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
//    DetailsGrid->Rows->Add();
//    string errorMessage = "�������� � ������ �� ����� ���� ������!\n ���� �� ������ ������� �����-���� ������� - ������� �� ���� ������ ������� ���� � �������� ����� \"�������\"";
//    MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
//
//    return System::Void();
//}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsAddingWindow(System::Object^ sender, System::EventArgs^ e)
{
    DetailAddingWindow^ AddingDetailForm = gcnew DetailAddingWindow();
    AddingDetailForm->GivingNewDetailsInfoEvent += gcnew System::EventHandler<GivingNewDetailsInfoEventArgs^>(this, &EquipmentPriceCalculator::OnGivingNewDetailsInfoEvent);
    AddingDetailForm->Show();
    DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
    return System::Void();
}

inline void EquipmentPriseCalculator::EquipmentPriceCalculator::OnGivingNewDetailsInfoEvent(Object^ sender, GivingNewDetailsInfoEventArgs^ e)
{
    std::string newDetailsNameStr = msclr::interop::marshal_as<std::string>(e->Name);
    double newDetailsCost = e->Cost;

    this->GlobalStorage.addDetailByNameAndCost(newDetailsNameStr, newDetailsCost);

    ShowDetailsListInDetailsGrid();
    //string errorMessage = newDetailsNameStr;
    //MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::DetailsListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    ShowDetailsListInDetailsGrid();
    //this->detailsNameFilterString = this->DetailsListPage_SearchInput->Text;

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::goBackToMainMenuFromDetailsList(System::Object^ sender, System::EventArgs^ e)
{
    DetailsListPage->Hide();
    HomePage->Show();
    return System::Void();
}