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

            // Создаем новое контекстное меню
            System::Windows::Forms::ContextMenuStrip^ menu = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Заказать");
            deleteDetail->Tag = rowIndex; // Сохраняем индекс строки в Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderEquipment_onClick);
            menu->Items->Add(deleteDetail);

            // Обработчик события Opening для обновления Tag
            menu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentList_deletingContextMenu_Opening);

            // Присваиваем новое контекстное меню
            EquipmentGrid->ContextMenuStrip = menu;
            menu->Show(EquipmentGrid, e->Location); // Показываем контекстное меню
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
            // Обновляем Tag элемента меню
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
        // Ваш код для удаления детали по rowIndex
        //MessageBox::Show("Удаление строки: " + rowIndex.ToString());


        this->GlobalStorage.addEquipmentToOrderListByName(EquipmentNameStr);
        ShowEquipmentListInOrderPageEquipmentGrid();



        // Отписываемся от события
        //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
    }
    return System::Void();
}

//////////////////////////////////////////////////////////////////////////////

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_ShowEquipmentListInOrderedEquipmentGrid()
{
    this->AddingEquipmentPage_ComponentsListDataGrid->Rows->Clear();

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
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}