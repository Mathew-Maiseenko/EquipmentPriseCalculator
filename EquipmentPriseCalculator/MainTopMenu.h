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

        // �������������� ���� � ����� �� String^ � std::string
        msclr::interop::marshal_context context;
        std::string stdFilePath = context.marshal_as<std::string>(filePath);
        this->GlobalStorage.readExternalFile(stdFilePath);
        ShowDetailsListInDetailsGrid();
        ShowEquipmentListInEquipmentGrid();
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_SaveFile(System::Object^ sender, System::EventArgs^ e)
{
    this->GlobalStorage.SaveAllInFile();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_SaveFileAs(System::Object^ sender, System::EventArgs^ e)
{
    if (saveFileAsDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // ��������� ���� � ���������� �����
        String^ filePath = saveFileAsDialog->FileName;

        // �������������� ���� � ����� �� String^ � std::string
        msclr::interop::marshal_context context;
        std::string stdFilePath = context.marshal_as<std::string>(filePath);

        this->GlobalStorage.SaveAllInFileAs(stdFilePath);
    }
    return System::Void();
}