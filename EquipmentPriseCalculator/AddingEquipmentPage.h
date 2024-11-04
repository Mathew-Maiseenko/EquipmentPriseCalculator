#pragma once
inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ShowDetailsListInDetailsGrid()
{
    this->AddingEquipmentPage_DetailsListDataGrid->Rows->Clear();

    DataGridView^ DetailsGrid = this->AddingEquipmentPage_DetailsListDataGrid;

    GlobalList Storage = this->GlobalStorage;
    std::vector<Detail> DetailList;

    String^ selectedItem = dynamic_cast<String^>(this->AddingEquipmentPage_DetailsListSortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        DetailList = this->GlobalStorage.SortDetailsList(selectedItem);
    }
    else
    {
        DetailList = Storage.getDetailList();
    }


    if (this->AddingEquipmentPage_DetailsListSearchInput->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->AddingEquipmentPage_DetailsListSearchInput->Text);
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
