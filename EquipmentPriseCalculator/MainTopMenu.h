#pragma once
#include "EquipmentPriceCalculator.h"
#include "GlobalList.h"
#include "DetailAddingWindow.h"


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_OpenExtraFileDialog(System::Object^ sender, System::EventArgs^ e)
{
    if (this->OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        String^ filePath = OpenFileDialog->FileName;
        //MessageBox::Show("Selected file: " + filePath);

        // Преобразование пути к файлу из String^ в std::string
        msclr::interop::marshal_context context;
        std::string stdFilePath = context.marshal_as<std::string>(filePath);
        this->GlobalStorage.readExternalFile(stdFilePath);
        ShowDetailsListInDetailsGrid();
        ShowEquipmentListInEquipmentGrid();
    }
	return System::Void();
}