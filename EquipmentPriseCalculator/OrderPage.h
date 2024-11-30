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

        double DetailCostDouble = Storage.getTotalEquipmentPrice(EquipmentList.at(i), &Storage);
        double Nacenka = Storage.getNacenkaOnPrice();
        double NDS = Storage.getNDS();
        double DetailCostWithNdsAndNacenka = (DetailCostDouble + DetailCostDouble * Nacenka + DetailCostDouble * NDS);
        String^ DetailCost = DetailCostWithNdsAndNacenka.ToString();

        //String^ DetailPrice = Storage.getTotalEquipmentPrice(EquipmentList.at(i), &Storage).ToString();

        List<String^>^ EquipmentInfoRow = gcnew List<String^>();
        EquipmentInfoRow->Add(DetailId);
        EquipmentInfoRow->Add(DetailName);
        EquipmentInfoRow->Add(DetailCost);

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
            DataGridView^ DetailsGrid = this->OrderPage_EquipmentDataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;
                DataGridView^ EquipmentGrid = this->OrderPage_EquipmentDataGrid;
                if (hit->RowIndex >= 0 && hit->RowIndex < EquipmentGrid->Rows->Count) {
                    EquipmentGrid->ClearSelection();
                    EquipmentGrid->Rows[hit->RowIndex]->Selected = true;
                    EquipmentGrid->CurrentCell = EquipmentGrid->Rows[hit->RowIndex]->Cells[0];
                }
            }
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderEquipment_onClick(System::Object^ sender, System::EventArgs^ e)
{
    ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
    if (menuItem != nullptr) {
        DataGridView^ DetailsGrid = this->OrderPage_EquipmentDataGrid;
        int rowIndex = safe_cast<int>(menuItem->Tag);
        String^ name = DetailsGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
        msclr::interop::marshal_context context;
        std::string EquipmentNameStr = context.marshal_as<std::string>(name);
        // Ваш код для удаления детали по rowIndex
        //MessageBox::Show("Удаление строки: " + rowIndex.ToString());


        this->GlobalStorage.addEquipmentToOrderListByName(EquipmentNameStr);
        ShowEquipmentListInOrderPageEquipmentGrid();
        OrderPage_ShowEquipmentListInOrderedEquipmentGrid();


        // Отписываемся от события
        //menuItem->Click -= gcnew EventHandler(this, &EquipmentPriceCalculator::deleteDetail_onClick);
    }
    return System::Void();
}

//////////////////////////////////////////////////////////////////////////////

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_CalculateTotalOrdersPrice()
{
    GlobalList Storage = this->GlobalStorage;
    std::vector<OrderedEquipment> ComponentsList = Storage.getOrderedEquipmentList();

    double totalPrice = 0;

    for (int i = 0; i < ComponentsList.size(); i++)
    {
        double DetailCostDouble = Storage.getTotalEquipmentPrice(ComponentsList.at(i).equip, &Storage);
        double Nacenka = Storage.getNacenkaOnPrice();
        double NDS = Storage.getNDS();
        int count = ComponentsList.at(i).equipmentsCount;
        double DetailCostWithNdsAndNacenka = count * (DetailCostDouble + DetailCostDouble * Nacenka + DetailCostDouble * NDS);

        totalPrice += DetailCostWithNdsAndNacenka;
    }

    OrderPage_TotalPrice->Text = (totalPrice.ToString() + "BYN");

    return System::Void();
}

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


    OrderPage_CalculateTotalOrdersPrice();


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

        double DetailCostDouble = Storage.getTotalEquipmentPrice(ComponentsList.at(i).equip, &Storage);
        double Nacenka = Storage.getNacenkaOnPrice();
        double NDS = Storage.getNDS();
        double DetailCostWithNdsAndNacenka = (DetailCostDouble + DetailCostDouble * Nacenka + DetailCostDouble * NDS);
        String^ DetailCost = DetailCostWithNdsAndNacenka.ToString();

        String^ DetailCount = ComponentsList.at(i).equipmentsCount.ToString();
        String^ DetailTotalPrice = (DetailCostWithNdsAndNacenka * ComponentsList.at(i).equipmentsCount).ToString();

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

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e)
{
    DataGridView^ EquipmentsGrid = this->OrderPage_OrderedEquipmentDataGrid;

    int curColumnIndex = e->ColumnIndex;
    int curRowIndex = e->RowIndex;

    ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid = EquipmentsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString();

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;

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

        boolean isCorrect = true; ///доделать

        if (curColumnIndex != 4)
        {
            isCorrect = false;
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid;

            string errorMessage = "Можно изменить только количество заказанного оборудования!";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (!this->GlobalStorage.is_number(ComponentsCountStd))
        {
            isCorrect = false;
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid;

            string errorMessage = "Количество обязано быть числом";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (newValueStd.size() >= 15) {
            isCorrect = false;
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid;
            string errorMessage = "Введенное значение слишком велико";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }


        if (isCorrect)
        {
            //MessageBox::Show(gcnew String(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString()));
            int newComponentsCount = Convert::ToInt64(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value);
            this->GlobalStorage.editCountOfOrderedEquipmentByName(newComponentsNameStd, newComponentsCount);
            OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
        }
    }
    else
    {
        DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid;
        string errorMessage = "Значение в ячейке не может быть пустым!\n Есди вы хотите удалить какой-либо элемент - нажмите по нему правой кнопкой мыши и выберите пункт \"Удалить\"";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
    }

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;
        System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;
          

            // Создаем новое контекстное меню
            System::Windows::Forms::ContextMenuStrip^ menu1 = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Удалить компонент");
            deleteDetail->Tag = rowIndex; // Сохраняем индекс строки в Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::removeEquipmentsFromOrder_onClick);
            menu1->Items->Add(deleteDetail);

            // Обработчик события Opening для обновления Tag
            menu1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_RemovingEquipmentFromOrderContextMenu_Opening);

            // Присваиваем новое контекстное меню
            DetailsGrid->ContextMenuStrip = menu1;
            menu1->Show(DetailsGrid, e->Location); // Показываем контекстное меню
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_RemovingEquipmentFromOrderContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{

    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // Обновляем Tag элемента меню
            DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;
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

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::removeEquipmentsFromOrder_onClick(System::Object^ sender, System::EventArgs^ e)
{

    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show("Вы уверены что хотите удалить объект?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
        if (menuItem != nullptr) {
            DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;
            int rowIndex = safe_cast<int>(menuItem->Tag);
            String^ name = DetailsGrid->Rows[rowIndex]->Cells[3]->Value->ToString();
            msclr::interop::marshal_context context;
            std::string ComponentNameStr = context.marshal_as<std::string>(name);
            // Ваш код для удаления детали по rowIndex
            //MessageBox::Show("Удаление строки: " + rowIndex.ToString());
            this->GlobalStorage.removeOrderedEquipmentByName(ComponentNameStr);
            OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
            //ShowDetailsListInDetailsGrid();

        }
    }
    else {

    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OrderPage_MakeOrderButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show("Вы уверены что хотите завершить заказ?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        if (saveFileAsDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Получение пути к выбранному файлу
            String^ filePath = saveFileAsDialog->FileName;
            // Преобразование пути к файлу из String^ в std::string
            msclr::interop::marshal_context context;
            std::string stdFilePath = context.marshal_as<std::string>(filePath);

            String^ userName = OrderPage_NameTextBox->Text->ToString();
            std::string stdUserName = context.marshal_as<std::string>(userName);

            if (filePath != nullptr && userName != nullptr)
            {
                this->OrderPage_OrderedEquipmentDataGrid->Rows->Clear();

                DataGridView^ DetailsGrid = this->OrderPage_OrderedEquipmentDataGrid;

                string orderFileName = (
                    "Order_" +
                    stdUserName +
                    "_" +
                    this->GlobalStorage.getCurrentTime() +
                    ".txt"
                );

                this->GlobalStorage.SaveCheckInFileByFilename(stdFilePath);
                this->GlobalStorage.SaveOrderInFile(orderFileName);
                
            } else if (userName == nullptr) {
                System::Windows::Forms::MessageBox::Show("Введите свое имя:", "Ошибка!", System::Windows::Forms::MessageBoxButtons::OK);
            }
        }
        
    }

    return System::Void();
}