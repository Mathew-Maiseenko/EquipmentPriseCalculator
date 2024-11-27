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


    if (this->EquipmentListPage_SearchInput->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->EquipmentListPage_SearchInput->Text);
        EquipmentList = Storage.getFilteredEquipmentListBySubStr(filterDetailsStr, EquipmentList);
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

            SelectRow(EquipmentGrid, rowIndex);

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
            DataGridView^ DetailsGrid = this->EquipmentListPage_DataGrid;
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

    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show("Вы уверены что хотите удалить объект?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
        if (menuItem != nullptr) {
            DataGridView^ DetailsGrid = this->EquipmentListPage_DataGrid;
            int rowIndex = safe_cast<int>(menuItem->Tag);
            String^ name = DetailsGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
            msclr::interop::marshal_context context;
            std::string EquipmentNameStr = context.marshal_as<std::string>(name);
            // Ваш код для удаления детали по rowIndex
            //MessageBox::Show("Удаление строки: " + rowIndex.ToString());


            this->GlobalStorage.removeEquipmentByName(EquipmentNameStr);
            ShowEquipmentListInEquipmentGrid();



            // Отписываемся от события
            //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
        }
    }
    else {

    }

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::onSelectEquipmentsListSortType(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    ShowEquipmentListInEquipmentGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentListPage_DataGrid_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e)
{
    DataGridView^ EquipmentsGrid = this->EquipmentListPage_DataGrid;

    int curColumnIndex = e->ColumnIndex;
    int curRowIndex = e->RowIndex;

    ValueBeforeEdit_EquipmentListPage_DataGrid = EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString();

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentListPage_DataGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ EquipmentsGrid = this->EquipmentListPage_DataGrid;

    int curColumnIndex = e->ColumnIndex;
    int curRowIndex = e->RowIndex;

    if (EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value != nullptr)
    {
        std::string oldValueStd = msclr::interop::marshal_as<std::string>(ValueBeforeEdit_EquipmentListPage_DataGrid->ToString());

        String^ newValue = EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString();
        std::string newValueStd = msclr::interop::marshal_as<std::string>(newValue);

        boolean isCorrect = true;

        if (curColumnIndex >= 3 && (curColumnIndex - 2) % 2 == 1 && !this->GlobalStorage.is_number(newValueStd)) {
            isCorrect = false;
            EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_EquipmentListPage_DataGrid;
            string errorMessage = "Количество обязано быть числом";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (newValueStd.size() >= 30) {
            isCorrect = false;
            EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_EquipmentListPage_DataGrid;
            string errorMessage = "Введенное значение слишком велико";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }


        
        if (curColumnIndex >= 2 && (curColumnIndex-2) % 2 == 0)
        {
            System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите измененить название детали?", "Изменение детали", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
            if (result == System::Windows::Forms::DialogResult::OK)
            {
                isCorrect = false;

            }
            else if (result == System::Windows::Forms::DialogResult::Cancel)
            {
                isCorrect = false;
                EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_EquipmentListPage_DataGrid;
            }
        }
        //else if (curColumnIndex >= 3 && (curColumnIndex - 2) % 2 == 1) {
        //    System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите измененить название детали?", "Изменение детали", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
        //    if (result == System::Windows::Forms::DialogResult::OK)
        //    {
        //        isCorrect = false;
        //        string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
        //    }
        //    else if (result == System::Windows::Forms::DialogResult::Cancel)
        //    {
        //        isCorrect = false;
        //        EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_EquipmentListPage_DataGrid;
        //    }
        //}



        if (isCorrect)
        {
            this->GlobalStorage.setNewComponentsValue(curColumnIndex, curRowIndex,oldValueStd, newValueStd);
            string errorMessage = "Значение в ячейке изменено " + oldValueStd + newValueStd ;
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
    }
    else
    {
        string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
        System::String^ oldValueCs = msclr::interop::marshal_as<System::String^>(oldValue);
        EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
        string errorMessage = "Значение в ячейке не может быть пустым!\n Есди вы хотите удалить какой-либо элемент - нажмите по нему правой кнопкой мыши и выберите пункт \"Удалить\"";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
    }


    return System::Void();
}