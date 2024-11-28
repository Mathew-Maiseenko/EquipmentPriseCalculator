#pragma once
#include "EquipmentPriceCalculator.h"
#include "GlobalList.h"
#include "DetailAddingWindow.h"


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_OpenExtraFileDialog(System::Object^ sender, System::EventArgs^ e)
{
    OpenExtraFileDialog();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OpenExtraFileDialog()
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

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_SaveFile(System::Object^ sender, System::EventArgs^ e)
{
    this->GlobalStorage.SaveAllInFile();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_SaveFileAs(System::Object^ sender, System::EventArgs^ e)
{
    if (saveFileAsDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Получение пути к выбранному файлу
        String^ filePath = saveFileAsDialog->FileName;

        // Преобразование пути к файлу из String^ в std::string
        msclr::interop::marshal_context context;
        std::string stdFilePath = context.marshal_as<std::string>(filePath);

        this->GlobalStorage.SaveAllInFileAs(stdFilePath);
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::CreateNewProject(System::Object^ sender, System::EventArgs^ e)
{
    HideStartPage();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::MainTopMenu_CreateNewProjectButton(System::Object^ sender, System::EventArgs^ e)
{


    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show("Вы хотите сохранить текущий проект?", "Сохранить?", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        if (this->GlobalStorage.getIsFilePathEmpty())
        {
            if (saveFileAsDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                // Получение пути к выбранному файлу
                String^ filePath = saveFileAsDialog->FileName;

                // Преобразование пути к файлу из String^ в std::string
                msclr::interop::marshal_context context;
                std::string stdFilePath = context.marshal_as<std::string>(filePath);

                this->GlobalStorage.SaveAllInFileAs(stdFilePath);
            }
        }
        else
        {
            this->GlobalStorage.SaveAllInFile();
        }
    }

    this->GlobalStorage.createNewProject();
    return System::Void();
}