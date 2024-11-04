#pragma once
#include "EquipmentPriceCalculator.h"
#include <msclr\auto_gcroot.h>
#include <msclr\marshal.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list> // Add this line

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic; // Add this line
inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowEquipmentListInEquipmentGrid()
{
    GlobalList Storage = this->GlobalStorage;
    int maxDetailsCount = Storage.getMaxEquipmentsDetailsCount();

    this->EquipmentListPage_DataGrid->Rows->Clear();

    this->EquipmentListPage_DataGrid->Columns->Clear();

    this->EquipmentListPage_DataGrid->ColumnCount = 2 + (maxDetailsCount * 2);
    this->EquipmentListPage_DataGrid->Columns[0]->HeaderText = "Id";
    this->EquipmentListPage_DataGrid->Columns[1]->HeaderText = "Название оборудования";

    DataGridView^ EquipmentGrid = this->EquipmentListPage_DataGrid;


    for (int i = 0; i < maxDetailsCount; i++)
    {
        this->EquipmentListPage_DataGrid->Columns[2 + 2*i]->HeaderText = 
            "Деталь" + " " + (i + 1).ToString();
        this->EquipmentListPage_DataGrid->Columns[3 + 2*i]->HeaderText =
            "Кол-во детали" + " " + (i + 1).ToString();
    }

    
    std::vector<Equipment> EquipmentList;

    String^ selectedItem = dynamic_cast<String^>(this->EquipmentListPage__SortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        EquipmentList = this->GlobalStorage.SortEquipmentList(selectedItem);
    }
    else
    {
        EquipmentList = Storage.getEquipmentList();
    }

    for (int i = 0; i < EquipmentList.size(); i++)
    {
        String^ DetailId = EquipmentList.at(i).id.ToString();
        String^ DetailName = gcnew String(EquipmentList.at(i).Name.c_str());
        

        //array<String^>^ EquipmentInfoRow = { DetailId, DetailName };
        //for (auto curDetail : EquipmentList.at(i).DetailsCount) {
        //    EquipmentInfoRow->Add(gcnew String(curDetail.first.c_str()));
        //}
        List<String^>^ EquipmentInfoRow = gcnew List<String^>();
        EquipmentInfoRow->Add(DetailId);
        EquipmentInfoRow->Add(DetailName);
        for (auto curDetail : EquipmentList.at(i).DetailsCount) {
            EquipmentInfoRow->Add(gcnew String(curDetail.first.c_str()));
            EquipmentInfoRow->Add(gcnew String(curDetail.second.ToString()));
        }

        array<String^>^ EquipmentInfoArray = EquipmentInfoRow->ToArray();
        EquipmentGrid->Rows->Add(EquipmentInfoArray);
    }

    EquipmentGrid->Refresh();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OnLoad_EquipmentListPage(System::Object^ sender, System::EventArgs^ e)
{
    this->ShowEquipmentListInEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::goBackToMainMenuFromEquipmentListPage(System::Object^ sender, System::EventArgs^ e)
{
    EquipmentListPage->Hide();
    HomePage->Show();
    return System::Void();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ EquipmentGrid = this->EquipmentListPage_DataGrid;
        System::Windows::Forms::DataGridView::HitTestInfo^ hit = EquipmentGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;

            // Создаем новое контекстное меню
            System::Windows::Forms::ContextMenuStrip^ menu = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Удалить");
            deleteDetail->Tag = rowIndex; // Сохраняем индекс строки в Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::deleteEquipment_onClick);
            menu->Items->Add(deleteDetail);

            // Обработчик события Opening для обновления Tag
            menu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::EquipmentList_deletingContextMenu_Opening);

            // Присваиваем новое контекстное меню
            EquipmentGrid->ContextMenuStrip = menu;
            menu->Show(EquipmentGrid, e->Location); // Показываем контекстное меню
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // Обновляем Tag элемента меню
            DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;
            }
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::deleteEquipment_onClick(System::Object^ sender, System::EventArgs^ e)
{
    ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
    if (menuItem != nullptr) {
        int rowIndex = safe_cast<int>(menuItem->Tag);
        // Ваш код для удаления детали по rowIndex
        //MessageBox::Show("Удаление строки: " + rowIndex.ToString());


        this->GlobalStorage.removeEquipmentById(rowIndex);
        ShowEquipmentListInEquipmentGrid();



        // Отписываемся от события
        //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::onSelectEquipmentsListSortType(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInEquipmentGrid();
    return System::Void();
}