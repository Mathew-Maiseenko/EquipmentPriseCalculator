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

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    AddingEquipmentPage_ShowDetailsListInDetailsGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::OnLoad_AddingEquipmentPage(System::Object^ sender, System::EventArgs^ e)
{
    AddingEquipmentPage_ShowDetailsListInDetailsGrid();
    AddingEquipmentPage_ShowComponentsListInGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    AddingEquipmentPage_ShowDetailsListInDetailsGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_DetailsListDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ DetailsGrid = this->AddingEquipmentPage_DetailsListDataGrid;
        System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;

            SelectRow(DetailsGrid, rowIndex);

            // Создаем новое контекстное меню
            System::Windows::Forms::ContextMenuStrip^ menu1 = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Сделать компонентом");
            deleteDetail->Tag = rowIndex; // Сохраняем индекс строки в Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::setDetailEquipmentsComponent_onClick);
            menu1->Items->Add(deleteDetail);

            // Обработчик события Opening для обновления Tag
            menu1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListDataGrid_AddingComponentContextMenu_Opening);

            // Присваиваем новое контекстное меню
            DetailsGrid->ContextMenuStrip = menu1;
            menu1->Show(DetailsGrid, e->Location); // Показываем контекстное меню
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_DetailsListDataGrid_AddingComponentContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // Обновляем Tag элемента меню
            DataGridView^ DetailsGrid = this->AddingEquipmentPage_DetailsListDataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;
            }
        }
    }
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::setDetailEquipmentsComponent_onClick(System::Object^ sender, System::EventArgs^ e)
{
    ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
    if (menuItem != nullptr) {
        DataGridView^ DetailsGrid = this->AddingEquipmentPage_DetailsListDataGrid;
        int rowIndex = safe_cast<int>(menuItem->Tag);
        String^ name = DetailsGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
        msclr::interop::marshal_context context;
        std::string DetailNameStr = context.marshal_as<std::string>(name);
        // Ваш код для удаления детали по rowIndex
        //MessageBox::Show("Удаление строки: " + rowIndex.ToString());
        this->GlobalStorage.addNewComponentToCurEquipmentToAdd(DetailNameStr);
        AddingEquipmentPage_ShowDetailsListInDetailsGrid();
        AddingEquipmentPage_ShowComponentsListInGrid();
        //ShowDetailsListInDetailsGrid();

    }
    return System::Void();
}



////////////////

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ShowComponentsListInGrid()
{
    this->AddingEquipmentPage_ComponentsListDataGrid->Rows->Clear();

    DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;

    GlobalList Storage = this->GlobalStorage;
    std::vector<EquipmentComponents> ComponentsList;

    String^ selectedItem = dynamic_cast<String^>(this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->SelectedItem);
    if (selectedItem != nullptr)
    {
        ComponentsList = this->GlobalStorage.getSortedCurEquipmentToAddComponents(selectedItem);
    }
    else
    {
        ComponentsList = Storage.getCurEquipmentToAddComponents();
    }


    if (this->AddingEquipmentPage_ComponentsListSearchInput->Text != nullptr)
    {
        msclr::interop::marshal_context context;
        std::string filterDetailsStr = context.marshal_as<std::string>(this->AddingEquipmentPage_ComponentsListSearchInput->Text);
        ComponentsList = Storage.getFilteredComponentsListBySubStr(filterDetailsStr, ComponentsList);
    }
    //std::string filterDetailsStr = msclr::interop::marshal_as<std::string>(this->detailsNameFilterString->ToString());



    for (int i = 0; i < ComponentsList.size(); i++)
    {
        String^ DetailId = ComponentsList.at(i).detail.id.ToString();
        String^ DetailName = gcnew String(ComponentsList.at(i).detail.Name.c_str());
        String^ DetailCost = ComponentsList.at(i).detail.costs.ToString();
        String^ DetailCount = ComponentsList.at(i).detailCount.ToString();
        String^ DetailTotalPrice = (ComponentsList.at(i).detail.costs * ComponentsList.at(i).detailCount).ToString();

        array<String^>^ DetailInfoRow = { "-", "+" ,DetailId,  DetailName , DetailCount, DetailCost, DetailTotalPrice};
        DetailsGrid->Rows->Add(DetailInfoRow);
    }

    DetailsGrid->Refresh();
}



inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponemtsListSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    AddingEquipmentPage_ShowComponentsListInGrid();
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    AddingEquipmentPage_ShowComponentsListInGrid();
    return System::Void();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;
        System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0 && hit->ColumnIndex >= 0) {
            int rowIndex = hit->RowIndex;

            // Создаем новое контекстное меню
            System::Windows::Forms::ContextMenuStrip^ menu1 = gcnew System::Windows::Forms::ContextMenuStrip();

            ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Удалить компонент");
            deleteDetail->Tag = rowIndex; // Сохраняем индекс строки в Tag
            deleteDetail->Click += gcnew EventHandler(this, &EquipmentPriceCalculator::removeEquipmentsComponent_onClick);
            menu1->Items->Add(deleteDetail);

            // Обработчик события Opening для обновления Tag
            menu1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_RemovingComponentContextMenu_Opening);

            // Присваиваем новое контекстное меню
            DetailsGrid->ContextMenuStrip = menu1;
            menu1->Show(DetailsGrid, e->Location); // Показываем контекстное меню
        }
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_RemovingComponentContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{

    System::Windows::Forms::ContextMenuStrip^ menu = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(sender);
    if (menu != nullptr) {
        ToolStripMenuItem^ deleteDetail = dynamic_cast<ToolStripMenuItem^>(menu->Items[0]);
        if (deleteDetail != nullptr) {
            // Обновляем Tag элемента меню
            DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;
            System::Windows::Forms::DataGridView::HitTestInfo^ hit = DetailsGrid->HitTest(DetailsGrid->PointToClient(Cursor->Position).X, DetailsGrid->PointToClient(Cursor->Position).Y);
            if (hit->RowIndex >= 0) {
                deleteDetail->Tag = hit->RowIndex;
            }
        }
    }
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::removeEquipmentsComponent_onClick(System::Object^ sender, System::EventArgs^ e)
{

    System::Windows::Forms::DialogResult result;
    result = System::Windows::Forms::MessageBox::Show("Вы уверены что хотите удалить объект?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel);
    if (result == System::Windows::Forms::DialogResult::OK) {
        ToolStripMenuItem^ menuItem = dynamic_cast<ToolStripMenuItem^>(sender);
        if (menuItem != nullptr) {
            DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;
            int rowIndex = safe_cast<int>(menuItem->Tag);
            String^ name = DetailsGrid->Rows[rowIndex]->Cells[3]->Value->ToString();
            msclr::interop::marshal_context context;
            std::string ComponentNameStr = context.marshal_as<std::string>(name);
            // Ваш код для удаления детали по rowIndex
            //MessageBox::Show("Удаление строки: " + rowIndex.ToString());
            this->GlobalStorage.removeComponentFromCurEquipmentToAddByName(ComponentNameStr);
            AddingEquipmentPage_ShowComponentsListInGrid();
            //ShowDetailsListInDetailsGrid();

        }
    }
    else {

    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_EquipmentNameInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    msclr::interop::marshal_context context;
    std::string newEquipmentsName = context.marshal_as<std::string>(this->AddingEquipmentPage_EquipmentNameInput->Text->ToString());
    this->GlobalStorage.setNameToCurEquipmentToAdd(newEquipmentsName);
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_AddingEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool isCorrect = true;
    Equipment curAddingEquipment = this->GlobalStorage.getCurEquipmentToAdd();


    if (curAddingEquipment.Name.empty())
    {
        isCorrect = false;
        string errorMessage = "Имя оборудования не может быть пустым!";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK));
    }
    else if (is_number(curAddingEquipment.Name))
    {
        isCorrect = false;
        string errorMessage = "Имя оборудования не может быть числом!";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK));
    } 
    else if (this->GlobalStorage.getCurEquipmentToAddComponents().empty())
    {
        isCorrect = false;
        string errorMessage = "Оборудования не может не седержать деталей в себе!";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK));
    }

    if (isCorrect)
    {
        msclr::interop::marshal_context context;
        std::string EquipmentName = context.marshal_as<std::string>(this->AddingEquipmentPage_EquipmentNameInput->Text->ToString());

        this->GlobalStorage.addNewEquipmentToList();
        this->AddingEquipmentPage_ComponentsListDataGrid->Rows->Clear();
        this->AddingEquipmentPage_EquipmentNameInput->Text = "";
        ShowEquipmentListInEquipmentGrid();

        string Message = "Оборудование " + EquipmentName + " успешно добавлено!";
        MessageBox::Show(gcnew String(Message.c_str()), "Успех", static_cast<MessageBoxButtons>(MessageBoxButtons::OK));
    }
    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;

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
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;

            string errorMessage = "Можно изменить только необходимое количество компонентов!";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (!this->GlobalStorage.is_number(ComponentsCountStd))
        {
            isCorrect = false;
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;

            string errorMessage = "Количество обязано быть числом";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }
        else if (newValueStd.size() >= 15) {
            isCorrect = false;
            msclr::interop::marshal_context context;
            string oldValue = this->GlobalStorage.getOldComponentsValue(newComponentsNameStd, curColumnIndex);
            System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
            DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
            string errorMessage = "Введенное значение слишком велико";
            MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
        }


        if (isCorrect)
        {
            //MessageBox::Show(gcnew String(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value->ToString()));
            int newComponentsCount = Convert::ToInt64(DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value);
            this->GlobalStorage.editCountOfTheEquipmentsComponentByName(newComponentsNameStd, newComponentsCount);
            AddingEquipmentPage_ShowComponentsListInGrid();
        }
    }
    else
    {
        msclr::interop::marshal_context context;
        string oldValue = this->GlobalStorage.getOldDetailsValue(curColumnIndex, curRowIndex);
        System::String^ oldValueCs = context.marshal_as<System::String^>(oldValue);
        DetailsGrid->Rows[curRowIndex]->Cells[curColumnIndex]->Value = oldValueCs;
        string errorMessage = "Значение в ячейке не может быть пустым!\n Есди вы хотите удалить какой-либо элемент - нажмите по нему правой кнопкой мыши и выберите пункт \"Удалить\"";
        MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
    }

    return System::Void();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DataGridView^ DetailsGrid = this->AddingEquipmentPage_ComponentsListDataGrid;

    if (e->ColumnIndex == 0)
    {
        int curComponentsCount = Convert::ToInt64(DetailsGrid->Rows[e->RowIndex]->Cells[4]->Value);
        String^ ComponentsNameSTRING = safe_cast<String^>(DetailsGrid->Rows[e->RowIndex]->Cells[3]->Value);
        std::string ComponentsName = msclr::interop::marshal_as<std::string>(ComponentsNameSTRING);
        if (curComponentsCount > 1)
        {
            this->GlobalStorage.decrementCountOfTheEquipmentsComponentByName(ComponentsName);
            AddingEquipmentPage_ShowComponentsListInGrid();
        }
        else {
            this->GlobalStorage.removeComponentFromCurEquipmentToAddByName(ComponentsName);
            AddingEquipmentPage_ShowComponentsListInGrid();
        }
     
    }
    if (e->ColumnIndex == 1)
    {
        String^ ComponentsNameSTRING = safe_cast<String^>(DetailsGrid->Rows[e->RowIndex]->Cells[3]->Value);
        std::string ComponentsName = msclr::interop::marshal_as<std::string>(ComponentsNameSTRING);
        this->GlobalStorage.incrementCountOfTheEquipmentsComponentByName(ComponentsName);
        AddingEquipmentPage_ShowComponentsListInGrid();
    }

    return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::EquipmentListPage__AddingButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    EquipmentListPage->Hide();
    AddingEquipmentPage->Show();
    return System::Void();
}


inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::AddingEquipmentPage_ExitfromAddingEquipmentPageButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    EquipmentListPage->Show();
    AddingEquipmentPage->Hide();
    return System::Void();
}