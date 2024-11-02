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
    this->EquipmentListPage_DataGrid->ColumnCount = 2 + maxDetailsCount;
    this->EquipmentListPage_DataGrid->Columns[0]->HeaderText = "Id оборудования";
    this->EquipmentListPage_DataGrid->Columns[1]->HeaderText = "Название оборудования";

    DataGridView^ EquipmentGrid = this->EquipmentListPage_DataGrid;
    for (int i = 0; i < maxDetailsCount; i++)
    {
        this->EquipmentListPage_DataGrid->Columns[2 + i]->HeaderText = 
            "Деталь" + " " + (i + 1).ToString();
        this->EquipmentListPage_DataGrid->Columns[2 + i]->HeaderText =
            "Кол-во детали" + " " + (i + 1).ToString();
    }

    String^ selectedItem = dynamic_cast<String^>(this->DetailsListPage_SortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        this->GlobalStorage.SortDetailsList(selectedItem);
    }

    
    std::vector<Equipment> EquipmentList = Storage.getEquipmentList();

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