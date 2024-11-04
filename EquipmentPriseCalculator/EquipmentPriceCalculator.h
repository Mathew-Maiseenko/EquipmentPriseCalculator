#pragma once
#include <windows.h>
#include <shellapi.h>
#include <msclr/marshal_cppstd.h>
#include "GlobalList.h"
#include "MainApplication.h"
#include "DetailAddingWindow.h"

namespace EquipmentPriseCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Сводка для EquipmentPriceCalculator
	/// </summary>
	public ref class EquipmentPriceCalculator : public System::Windows::Forms::Form
	{
	public:
		EquipmentPriceCalculator(GlobalList& globalStorage) : GlobalStorage(globalStorage)
		{
			InitializeComponent();

			DetailsListPage->Hide();
			EquipmentListPage->Hide();
			// Открываем файлы
			fstream DetailFile("DetailSpisok.csv");
			fstream EquipmentFile("EquipmentSpisok.csv");

			// Проверяем, открылись ли файлы
			if (!DetailFile.is_open()) {
				MessageBox::Show("Не удалось открыть файл DetailSpisok.csv");
				return;
			}

			if (!EquipmentFile.is_open()) {
				MessageBox::Show("Не удалось открыть файл EquipmentSpisok.csv");
				return;
			}

			// Добавление обработчика для горячей клавиши
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &EquipmentPriceCalculator::OnKeyDown);

			// Вызываем методы для работы с файлами
			//GlobalStorage.readDetailsFile(DetailFile, GlobalStorage, "DetailSpisok.csv");
			//GlobalStorage.readEquipmentFile(EquipmentFile, GlobalStorage, "EquipmentSpisok.csv");

			//
			//TODO: добавьте код конструктора
			//
		}

		/*
				EquipmentPriceCalculator(void)
		{
			InitializeComponent();

			DetailsPage->Hide();

			fstream DetailFile;
			DetailFile.open("DetailSpisok.csv");

			fstream EquipmentFile;
			EquipmentFile.open("EquipmentSpisok.csv");

			this->GlobalStorage = GlobalList();
			this->GlobalStorage->testDetailList();

			this->GlobalStorage->testDetailList();
			this->GlobalStorage->readDetailsFile(DetailFile, GlobalStorage, "DetailSpisok.csv");
			this->GlobalStorage->readEquipmentFile(EquipmentFile, GlobalStorage, "EquipmentSpisok.csv");

			//
			//TODO: добавьте код конструктора
			//
		}
		*/

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EquipmentPriceCalculator()
		{
			if (components)
			{
				delete components;
			}
			//delete GlobalStorage;
		}

	protected:

	private: System::Windows::Forms::Panel^ HomePage;
	protected:


	protected:


	private: System::Windows::Forms::Button^ HomePage_UsersGuidButton;
	private: System::Windows::Forms::Button^ HomePage_EquipmentButton;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ HomePage_DetailsButton;



























	private: System::Windows::Forms::Panel^ DetailsListPage;
	private: System::Windows::Forms::DataGridView^ DetailsListPage_DataGrid;


	private: System::Windows::Forms::Button^ DetailsListPage_ExitButton;

	private: System::Windows::Forms::Label^ DetailsListPage_Title;




	private: System::Windows::Forms::Label^ DetailsListPage_SortTypeMessage;
	private: System::Windows::Forms::ComboBox^ DetailsListPage_SortTypeComboBox;










	private: GlobalList& GlobalStorage;
	private: System::Windows::Forms::Button^ DetailsListPage_AddingButton;
	private: System::Windows::Forms::TextBox^ DetailsListPage_SearchInput;



	private: System::Windows::Forms::Panel^ EquipmentListPage;
	private: System::Windows::Forms::TextBox^ EquipmentListPage_SearchInput;
	private: System::Windows::Forms::Button^ EquipmentListPage__AddingButton;


	private: System::Windows::Forms::ComboBox^ EquipmentListPage__SortTypeComboBox;


	private: System::Windows::Forms::Label^ EquipmentListPage_SortTypeMessage;
	private: System::Windows::Forms::Button^ EquipmentListPage_ExitButton;


	private: System::Windows::Forms::Label^ EquipmentListPage_Title;
	private: System::Windows::Forms::DataGridView^ EquipmentListPage_DataGrid;




	private: System::Windows::Forms::MenuStrip^ MainTopMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ MainTopMenu_OpenFileButton;

	private: System::Windows::Forms::ToolStripMenuItem^ MainTopMenu_SaveFileButton;
	private: System::Windows::Forms::ToolStripMenuItem^ MainTopMenu_SaveFileAsButton;


	private: System::Windows::Forms::ToolStripMenuItem^ окноToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ деталиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оборудованиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ главнаяИнформацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ руководствоПользователяToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileAsDialog;
private: System::Windows::Forms::Panel^ AddingEquipmentPage;
private: System::Windows::Forms::TextBox^ AddingEquipmentPage_ComponentsListSearchInput;


private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::ComboBox^ AddingEquipmentPage_ComponemtsListSortTypeComboBox;

private: System::Windows::Forms::Label^ AddingEquipmentPage_ComponentsListSortTypeLabel;

private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ AddingEquipmentPage_ComponentsListLabel;
private: System::Windows::Forms::DataGridView^ AddingEquipmentPage_ComponentsListDataGrid;


private: System::Windows::Forms::TextBox^ AddingEquipmentPage_DetailsListSearchInput;
private: System::Windows::Forms::ComboBox^ AddingEquipmentPage_DetailsListSortTypeComboBox;






private: System::Windows::Forms::Label^ AddingEquipmentPage_DetailsListSortTypeLabel;

private: System::Windows::Forms::Label^ AddingEquipmentPage_DetailsListLabel;
private: System::Windows::Forms::DataGridView^ AddingEquipmentPage_DetailsListDataGrid;


private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailId;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailName;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailPrice;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;













	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->HomePage = (gcnew System::Windows::Forms::Panel());
			this->HomePage_UsersGuidButton = (gcnew System::Windows::Forms::Button());
			this->HomePage_EquipmentButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HomePage_DetailsButton = (gcnew System::Windows::Forms::Button());
			this->DetailsListPage = (gcnew System::Windows::Forms::Panel());
			this->DetailsListPage_SearchInput = (gcnew System::Windows::Forms::TextBox());
			this->DetailsListPage_AddingButton = (gcnew System::Windows::Forms::Button());
			this->DetailsListPage_SortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DetailsListPage_SortTypeMessage = (gcnew System::Windows::Forms::Label());
			this->DetailsListPage_ExitButton = (gcnew System::Windows::Forms::Button());
			this->DetailsListPage_Title = (gcnew System::Windows::Forms::Label());
			this->DetailsListPage_DataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->DetailId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetailName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DetailPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EquipmentListPage = (gcnew System::Windows::Forms::Panel());
			this->EquipmentListPage_SearchInput = (gcnew System::Windows::Forms::TextBox());
			this->EquipmentListPage__AddingButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentListPage__SortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->EquipmentListPage_SortTypeMessage = (gcnew System::Windows::Forms::Label());
			this->EquipmentListPage_ExitButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentListPage_Title = (gcnew System::Windows::Forms::Label());
			this->EquipmentListPage_DataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MainTopMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_OpenFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileAsButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->окноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->деталиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оборудованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->главнаяИнформацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->руководствоПользователяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileAsDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->AddingEquipmentPage = (gcnew System::Windows::Forms::Panel());
			this->AddingEquipmentPage_DetailsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_DetailsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_DetailsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddingEquipmentPage_ComponentsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_ComponentsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ComponentsListLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_ComponentsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HomePage->SuspendLayout();
			this->DetailsListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->BeginInit();
			this->EquipmentListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->BeginInit();
			this->MainTopMenu->SuspendLayout();
			this->AddingEquipmentPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_DetailsListDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_ComponentsListDataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// HomePage
			// 
			this->HomePage->Controls->Add(this->HomePage_UsersGuidButton);
			this->HomePage->Controls->Add(this->HomePage_EquipmentButton);
			this->HomePage->Controls->Add(this->label1);
			this->HomePage->Controls->Add(this->HomePage_DetailsButton);
			this->HomePage->Location = System::Drawing::Point(322, 42);
			this->HomePage->Name = L"HomePage";
			this->HomePage->Size = System::Drawing::Size(590, 262);
			this->HomePage->TabIndex = 1;
			// 
			// HomePage_UsersGuidButton
			// 
			this->HomePage_UsersGuidButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_UsersGuidButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_UsersGuidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_UsersGuidButton->Location = System::Drawing::Point(53, 198);
			this->HomePage_UsersGuidButton->Name = L"HomePage_UsersGuidButton";
			this->HomePage_UsersGuidButton->Size = System::Drawing::Size(489, 44);
			this->HomePage_UsersGuidButton->TabIndex = 8;
			this->HomePage_UsersGuidButton->Text = L"Руководство пользователя";
			this->HomePage_UsersGuidButton->UseVisualStyleBackColor = false;
			this->HomePage_UsersGuidButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowGuidOnClick);
			// 
			// HomePage_EquipmentButton
			// 
			this->HomePage_EquipmentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_EquipmentButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_EquipmentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->HomePage_EquipmentButton->Location = System::Drawing::Point(302, 101);
			this->HomePage_EquipmentButton->Name = L"HomePage_EquipmentButton";
			this->HomePage_EquipmentButton->Size = System::Drawing::Size(240, 90);
			this->HomePage_EquipmentButton->TabIndex = 7;
			this->HomePage_EquipmentButton->Text = L"Оборудование";
			this->HomePage_EquipmentButton->UseVisualStyleBackColor = false;
			this->HomePage_EquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowEquipmentListPage);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label1->Location = System::Drawing::Point(48, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(494, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Калькулятор себестоимости оборудования";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePage_DetailsButton
			// 
			this->HomePage_DetailsButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_DetailsButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_DetailsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_DetailsButton->Location = System::Drawing::Point(53, 101);
			this->HomePage_DetailsButton->Name = L"HomePage_DetailsButton";
			this->HomePage_DetailsButton->Size = System::Drawing::Size(240, 90);
			this->HomePage_DetailsButton->TabIndex = 5;
			this->HomePage_DetailsButton->Text = L"Детали";
			this->HomePage_DetailsButton->UseVisualStyleBackColor = false;
			this->HomePage_DetailsButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsListPage);
			// 
			// DetailsListPage
			// 
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SearchInput);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_AddingButton);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SortTypeComboBox);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SortTypeMessage);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_ExitButton);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_Title);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_DataGrid);
			this->DetailsListPage->Location = System::Drawing::Point(3, 310);
			this->DetailsListPage->Name = L"DetailsListPage";
			this->DetailsListPage->Size = System::Drawing::Size(547, 301);
			this->DetailsListPage->TabIndex = 15;
			this->DetailsListPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_DetailsListPage);
			// 
			// DetailsListPage_SearchInput
			// 
			this->DetailsListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DetailsListPage_SearchInput->Location = System::Drawing::Point(14, 72);
			this->DetailsListPage_SearchInput->Margin = System::Windows::Forms::Padding(2);
			this->DetailsListPage_SearchInput->Name = L"DetailsListPage_SearchInput";
			this->DetailsListPage_SearchInput->Size = System::Drawing::Size(364, 27);
			this->DetailsListPage_SearchInput->TabIndex = 18;
			this->DetailsListPage_SearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_SearchInput_TextChanged);
			// 
			// DetailsListPage_AddingButton
			// 
			this->DetailsListPage_AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->DetailsListPage_AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsListPage_AddingButton->Location = System::Drawing::Point(383, 135);
			this->DetailsListPage_AddingButton->Name = L"DetailsListPage_AddingButton";
			this->DetailsListPage_AddingButton->Size = System::Drawing::Size(154, 52);
			this->DetailsListPage_AddingButton->TabIndex = 17;
			this->DetailsListPage_AddingButton->Text = L"Добавить";
			this->DetailsListPage_AddingButton->UseVisualStyleBackColor = false;
			this->DetailsListPage_AddingButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsAddingWindow);
			// 
			// DetailsListPage_SortTypeComboBox
			// 
			this->DetailsListPage_SortTypeComboBox->FormattingEnabled = true;
			this->DetailsListPage_SortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали", L"Названию детали",
					L"Стоимости детали"
			});
			this->DetailsListPage_SortTypeComboBox->Location = System::Drawing::Point(385, 108);
			this->DetailsListPage_SortTypeComboBox->Name = L"DetailsListPage_SortTypeComboBox";
			this->DetailsListPage_SortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->DetailsListPage_SortTypeComboBox->TabIndex = 16;
			this->DetailsListPage_SortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onSelectDetailsListSortType);
			// 
			// DetailsListPage_SortTypeMessage
			// 
			this->DetailsListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_SortTypeMessage->AutoSize = true;
			this->DetailsListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsListPage_SortTypeMessage->Location = System::Drawing::Point(381, 72);
			this->DetailsListPage_SortTypeMessage->Name = L"DetailsListPage_SortTypeMessage";
			this->DetailsListPage_SortTypeMessage->Size = System::Drawing::Size(158, 24);
			this->DetailsListPage_SortTypeMessage->TabIndex = 15;
			this->DetailsListPage_SortTypeMessage->Text = L"Сортировка по";
			this->DetailsListPage_SortTypeMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DetailsListPage_ExitButton
			// 
			this->DetailsListPage_ExitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_ExitButton->BackColor = System::Drawing::Color::DarkRed;
			this->DetailsListPage_ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_ExitButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsListPage_ExitButton->Location = System::Drawing::Point(385, 246);
			this->DetailsListPage_ExitButton->Name = L"DetailsListPage_ExitButton";
			this->DetailsListPage_ExitButton->Size = System::Drawing::Size(154, 38);
			this->DetailsListPage_ExitButton->TabIndex = 14;
			this->DetailsListPage_ExitButton->Text = L"Назад";
			this->DetailsListPage_ExitButton->UseVisualStyleBackColor = false;
			this->DetailsListPage_ExitButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::goBackToMainMenuFromDetailsList);
			// 
			// DetailsListPage_Title
			// 
			this->DetailsListPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_Title->AutoSize = true;
			this->DetailsListPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DetailsListPage_Title->Location = System::Drawing::Point(9, 15);
			this->DetailsListPage_Title->Name = L"DetailsListPage_Title";
			this->DetailsListPage_Title->Size = System::Drawing::Size(259, 37);
			this->DetailsListPage_Title->TabIndex = 10;
			this->DetailsListPage_Title->Text = L"Список деталей";
			this->DetailsListPage_Title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DetailsListPage_DataGrid
			// 
			this->DetailsListPage_DataGrid->AllowUserToAddRows = false;
			this->DetailsListPage_DataGrid->BackgroundColor = System::Drawing::Color::White;
			this->DetailsListPage_DataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DetailsListPage_DataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->DetailId,
					this->DetailName, this->DetailPrice
			});
			this->DetailsListPage_DataGrid->Location = System::Drawing::Point(14, 108);
			this->DetailsListPage_DataGrid->Name = L"DetailsListPage_DataGrid";
			this->DetailsListPage_DataGrid->RowHeadersWidth = 51;
			this->DetailsListPage_DataGrid->Size = System::Drawing::Size(363, 176);
			this->DetailsListPage_DataGrid->TabIndex = 0;
			this->DetailsListPage_DataGrid->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPriceCalculator::DetailsGrid_CellEndEdit);
			this->DetailsListPage_DataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::DetailsGrid_MouseClick);
			// 
			// DetailId
			// 
			this->DetailId->Frozen = true;
			this->DetailId->HeaderText = L"Id";
			this->DetailId->MinimumWidth = 6;
			this->DetailId->Name = L"DetailId";
			this->DetailId->Width = 50;
			// 
			// DetailName
			// 
			this->DetailName->Frozen = true;
			this->DetailName->HeaderText = L"Название детали";
			this->DetailName->MinimumWidth = 6;
			this->DetailName->Name = L"DetailName";
			this->DetailName->Width = 170;
			// 
			// DetailPrice
			// 
			this->DetailPrice->Frozen = true;
			this->DetailPrice->HeaderText = L"Стоимость детали, р/шт";
			this->DetailPrice->MinimumWidth = 6;
			this->DetailPrice->Name = L"DetailPrice";
			this->DetailPrice->Width = 125;
			// 
			// EquipmentListPage
			// 
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_SearchInput);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage__AddingButton);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage__SortTypeComboBox);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_SortTypeMessage);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_ExitButton);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_Title);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_DataGrid);
			this->EquipmentListPage->Location = System::Drawing::Point(556, 310);
			this->EquipmentListPage->Name = L"EquipmentListPage";
			this->EquipmentListPage->Size = System::Drawing::Size(547, 301);
			this->EquipmentListPage->TabIndex = 19;
			this->EquipmentListPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_EquipmentListPage);
			// 
			// EquipmentListPage_SearchInput
			// 
			this->EquipmentListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EquipmentListPage_SearchInput->Location = System::Drawing::Point(14, 72);
			this->EquipmentListPage_SearchInput->Margin = System::Windows::Forms::Padding(2);
			this->EquipmentListPage_SearchInput->Name = L"EquipmentListPage_SearchInput";
			this->EquipmentListPage_SearchInput->Size = System::Drawing::Size(364, 27);
			this->EquipmentListPage_SearchInput->TabIndex = 18;
			this->EquipmentListPage_SearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::EquipmentListPage_SearchInput_TextChanged);
			// 
			// EquipmentListPage__AddingButton
			// 
			this->EquipmentListPage__AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage__AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->EquipmentListPage__AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentListPage__AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->EquipmentListPage__AddingButton->Location = System::Drawing::Point(385, 135);
			this->EquipmentListPage__AddingButton->Name = L"EquipmentListPage__AddingButton";
			this->EquipmentListPage__AddingButton->Size = System::Drawing::Size(154, 52);
			this->EquipmentListPage__AddingButton->TabIndex = 17;
			this->EquipmentListPage__AddingButton->Text = L"Добавить";
			this->EquipmentListPage__AddingButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentListPage__SortTypeComboBox
			// 
			this->EquipmentListPage__SortTypeComboBox->FormattingEnabled = true;
			this->EquipmentListPage__SortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id оборудования", L"Названию оборудования",
					L"Стоимости оборудования"
			});
			this->EquipmentListPage__SortTypeComboBox->Location = System::Drawing::Point(385, 108);
			this->EquipmentListPage__SortTypeComboBox->Name = L"EquipmentListPage__SortTypeComboBox";
			this->EquipmentListPage__SortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->EquipmentListPage__SortTypeComboBox->TabIndex = 16;
			this->EquipmentListPage__SortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onSelectEquipmentsListSortType);
			// 
			// EquipmentListPage_SortTypeMessage
			// 
			this->EquipmentListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_SortTypeMessage->AutoSize = true;
			this->EquipmentListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->EquipmentListPage_SortTypeMessage->Location = System::Drawing::Point(381, 72);
			this->EquipmentListPage_SortTypeMessage->Name = L"EquipmentListPage_SortTypeMessage";
			this->EquipmentListPage_SortTypeMessage->Size = System::Drawing::Size(158, 24);
			this->EquipmentListPage_SortTypeMessage->TabIndex = 15;
			this->EquipmentListPage_SortTypeMessage->Text = L"Сортировка по";
			this->EquipmentListPage_SortTypeMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// EquipmentListPage_ExitButton
			// 
			this->EquipmentListPage_ExitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_ExitButton->BackColor = System::Drawing::Color::DarkRed;
			this->EquipmentListPage_ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentListPage_ExitButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->EquipmentListPage_ExitButton->Location = System::Drawing::Point(385, 246);
			this->EquipmentListPage_ExitButton->Name = L"EquipmentListPage_ExitButton";
			this->EquipmentListPage_ExitButton->Size = System::Drawing::Size(154, 38);
			this->EquipmentListPage_ExitButton->TabIndex = 14;
			this->EquipmentListPage_ExitButton->Text = L"Назад";
			this->EquipmentListPage_ExitButton->UseVisualStyleBackColor = false;
			this->EquipmentListPage_ExitButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::goBackToMainMenuFromEquipmentListPage);
			// 
			// EquipmentListPage_Title
			// 
			this->EquipmentListPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_Title->AutoSize = true;
			this->EquipmentListPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EquipmentListPage_Title->Location = System::Drawing::Point(9, 15);
			this->EquipmentListPage_Title->Name = L"EquipmentListPage_Title";
			this->EquipmentListPage_Title->Size = System::Drawing::Size(347, 37);
			this->EquipmentListPage_Title->TabIndex = 10;
			this->EquipmentListPage_Title->Text = L"Список оборудования";
			this->EquipmentListPage_Title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// EquipmentListPage_DataGrid
			// 
			this->EquipmentListPage_DataGrid->AllowUserToAddRows = false;
			this->EquipmentListPage_DataGrid->BackgroundColor = System::Drawing::Color::White;
			this->EquipmentListPage_DataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->EquipmentListPage_DataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->EquipmentListPage_DataGrid->Location = System::Drawing::Point(14, 108);
			this->EquipmentListPage_DataGrid->Name = L"EquipmentListPage_DataGrid";
			this->EquipmentListPage_DataGrid->RowHeadersWidth = 51;
			this->EquipmentListPage_DataGrid->Size = System::Drawing::Size(363, 176);
			this->EquipmentListPage_DataGrid->TabIndex = 0;
			this->EquipmentListPage_DataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::EquipmentGrid_MouseClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->Frozen = true;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Frozen = true;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Название Оборудования";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 170;
			// 
			// MainTopMenu
			// 
			this->MainTopMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->MainTopMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->окноToolStripMenuItem, this->оПрограммеToolStripMenuItem
			});
			this->MainTopMenu->Location = System::Drawing::Point(0, 0);
			this->MainTopMenu->Name = L"MainTopMenu";
			this->MainTopMenu->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->MainTopMenu->Size = System::Drawing::Size(1209, 24);
			this->MainTopMenu->TabIndex = 20;
			this->MainTopMenu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->MainTopMenu_OpenFileButton,
					this->MainTopMenu_SaveFileButton, this->MainTopMenu_SaveFileAsButton
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// MainTopMenu_OpenFileButton
			// 
			this->MainTopMenu_OpenFileButton->Name = L"MainTopMenu_OpenFileButton";
			this->MainTopMenu_OpenFileButton->Size = System::Drawing::Size(154, 22);
			this->MainTopMenu_OpenFileButton->Text = L"Открыть";
			this->MainTopMenu_OpenFileButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::MainTopMenu_OpenExtraFileDialog);
			// 
			// MainTopMenu_SaveFileButton
			// 
			this->MainTopMenu_SaveFileButton->Name = L"MainTopMenu_SaveFileButton";
			this->MainTopMenu_SaveFileButton->Size = System::Drawing::Size(154, 22);
			this->MainTopMenu_SaveFileButton->Text = L"Сохранить";
			this->MainTopMenu_SaveFileButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::MainTopMenu_SaveFile);
			// 
			// MainTopMenu_SaveFileAsButton
			// 
			this->MainTopMenu_SaveFileAsButton->Name = L"MainTopMenu_SaveFileAsButton";
			this->MainTopMenu_SaveFileAsButton->Size = System::Drawing::Size(154, 22);
			this->MainTopMenu_SaveFileAsButton->Text = L"Сохранить как";
			this->MainTopMenu_SaveFileAsButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::MainTopMenu_SaveFileAs);
			// 
			// окноToolStripMenuItem
			// 
			this->окноToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->деталиToolStripMenuItem,
					this->оборудованиеToolStripMenuItem
			});
			this->окноToolStripMenuItem->Name = L"окноToolStripMenuItem";
			this->окноToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->окноToolStripMenuItem->Text = L"Окно";
			// 
			// деталиToolStripMenuItem
			// 
			this->деталиToolStripMenuItem->Name = L"деталиToolStripMenuItem";
			this->деталиToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->деталиToolStripMenuItem->Text = L"Детали";
			// 
			// оборудованиеToolStripMenuItem
			// 
			this->оборудованиеToolStripMenuItem->Name = L"оборудованиеToolStripMenuItem";
			this->оборудованиеToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->оборудованиеToolStripMenuItem->Text = L"Оборудование";
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->главнаяИнформацияToolStripMenuItem,
					this->руководствоПользователяToolStripMenuItem
			});
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			// 
			// главнаяИнформацияToolStripMenuItem
			// 
			this->главнаяИнформацияToolStripMenuItem->Name = L"главнаяИнформацияToolStripMenuItem";
			this->главнаяИнформацияToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->главнаяИнформацияToolStripMenuItem->Text = L"Главная информация";
			// 
			// руководствоПользователяToolStripMenuItem
			// 
			this->руководствоПользователяToolStripMenuItem->Name = L"руководствоПользователяToolStripMenuItem";
			this->руководствоПользователяToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->руководствоПользователяToolStripMenuItem->Text = L"Руководство пользователя";
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"openFileDialog";
			this->OpenFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|CSV файлы (*.csv)|*.csv";
			this->OpenFileDialog->FilterIndex = 2;
			this->OpenFileDialog->Title = L"Открыть файл";
			// 
			// saveFileAsDialog
			// 
			this->saveFileAsDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|csv файлы (*.csv)|*.csv";
			// 
			// AddingEquipmentPage
			// 
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSearchInput);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeComboBox);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListDataGrid);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListSearchInput);
			this->AddingEquipmentPage->Controls->Add(this->button1);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponemtsListSortTypeComboBox);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListSortTypeLabel);
			this->AddingEquipmentPage->Controls->Add(this->button2);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListDataGrid);
			this->AddingEquipmentPage->Location = System::Drawing::Point(3, 617);
			this->AddingEquipmentPage->Name = L"AddingEquipmentPage";
			this->AddingEquipmentPage->Size = System::Drawing::Size(1100, 237);
			this->AddingEquipmentPage->TabIndex = 21;
			// 
			// AddingEquipmentPage_DetailsListSearchInput
			// 
			this->AddingEquipmentPage_DetailsListSearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->AddingEquipmentPage_DetailsListSearchInput->Location = System::Drawing::Point(8, 54);
			this->AddingEquipmentPage_DetailsListSearchInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_DetailsListSearchInput->Name = L"AddingEquipmentPage_DetailsListSearchInput";
			this->AddingEquipmentPage_DetailsListSearchInput->Size = System::Drawing::Size(332, 27);
			this->AddingEquipmentPage_DetailsListSearchInput->TabIndex = 23;
			this->AddingEquipmentPage_DetailsListSearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSearchInput_TextChanged);
			// 
			// AddingEquipmentPage_DetailsListSortTypeComboBox
			// 
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->FormattingEnabled = true;
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали",
					L"Названию детали", L"Стоимости детали"
			});
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Location = System::Drawing::Point(353, 85);
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Name = L"AddingEquipmentPage_DetailsListSortTypeComboBox";
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Size = System::Drawing::Size(146, 21);
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->TabIndex = 22;
			// 
			// AddingEquipmentPage_DetailsListSortTypeLabel
			// 
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->AutoSize = true;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Location = System::Drawing::Point(349, 54);
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Name = L"AddingEquipmentPage_DetailsListSortTypeLabel";
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Size = System::Drawing::Size(158, 24);
			this->AddingEquipmentPage_DetailsListSortTypeLabel->TabIndex = 21;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Text = L"Сортировка по";
			this->AddingEquipmentPage_DetailsListSortTypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_DetailsListLabel
			// 
			this->AddingEquipmentPage_DetailsListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_DetailsListLabel->AutoSize = true;
			this->AddingEquipmentPage_DetailsListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_DetailsListLabel->Location = System::Drawing::Point(20, 15);
			this->AddingEquipmentPage_DetailsListLabel->Name = L"AddingEquipmentPage_DetailsListLabel";
			this->AddingEquipmentPage_DetailsListLabel->Size = System::Drawing::Size(305, 29);
			this->AddingEquipmentPage_DetailsListLabel->TabIndex = 20;
			this->AddingEquipmentPage_DetailsListLabel->Text = L"Общий список деталей";
			this->AddingEquipmentPage_DetailsListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_DetailsListDataGrid
			// 
			this->AddingEquipmentPage_DetailsListDataGrid->AllowUserToAddRows = false;
			this->AddingEquipmentPage_DetailsListDataGrid->BackgroundColor = System::Drawing::Color::White;
			this->AddingEquipmentPage_DetailsListDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->AddingEquipmentPage_DetailsListDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn7,
					this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9
			});
			this->AddingEquipmentPage_DetailsListDataGrid->Location = System::Drawing::Point(8, 85);
			this->AddingEquipmentPage_DetailsListDataGrid->Name = L"AddingEquipmentPage_DetailsListDataGrid";
			this->AddingEquipmentPage_DetailsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_DetailsListDataGrid->Size = System::Drawing::Size(331, 135);
			this->AddingEquipmentPage_DetailsListDataGrid->TabIndex = 19;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->Frozen = true;
			this->dataGridViewTextBoxColumn7->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 50;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->Frozen = true;
			this->dataGridViewTextBoxColumn8->HeaderText = L"Название детали";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->Width = 170;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->Frozen = true;
			this->dataGridViewTextBoxColumn9->HeaderText = L"Стоимость детали, р/шт";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->Width = 125;
			// 
			// AddingEquipmentPage_ComponentsListSearchInput
			// 
			this->AddingEquipmentPage_ComponentsListSearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->AddingEquipmentPage_ComponentsListSearchInput->Location = System::Drawing::Point(512, 54);
			this->AddingEquipmentPage_ComponentsListSearchInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_ComponentsListSearchInput->Name = L"AddingEquipmentPage_ComponentsListSearchInput";
			this->AddingEquipmentPage_ComponentsListSearchInput->Size = System::Drawing::Size(364, 27);
			this->AddingEquipmentPage_ComponentsListSearchInput->TabIndex = 18;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(908, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 52);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// AddingEquipmentPage_ComponemtsListSortTypeComboBox
			// 
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->FormattingEnabled = true;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали",
					L"Названию детали", L"Стоимости детали"
			});
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Location = System::Drawing::Point(904, 85);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Name = L"AddingEquipmentPage_ComponemtsListSortTypeComboBox";
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->TabIndex = 16;
			// 
			// AddingEquipmentPage_ComponentsListSortTypeLabel
			// 
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->AutoSize = true;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Location = System::Drawing::Point(904, 58);
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Name = L"AddingEquipmentPage_ComponentsListSortTypeLabel";
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Size = System::Drawing::Size(158, 24);
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->TabIndex = 15;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Text = L"Сортировка по";
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::DarkRed;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(908, 191);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 38);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Назад";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// AddingEquipmentPage_ComponentsListLabel
			// 
			this->AddingEquipmentPage_ComponentsListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ComponentsListLabel->AutoSize = true;
			this->AddingEquipmentPage_ComponentsListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_ComponentsListLabel->Location = System::Drawing::Point(564, 15);
			this->AddingEquipmentPage_ComponentsListLabel->Name = L"AddingEquipmentPage_ComponentsListLabel";
			this->AddingEquipmentPage_ComponentsListLabel->Size = System::Drawing::Size(462, 29);
			this->AddingEquipmentPage_ComponentsListLabel->TabIndex = 10;
			this->AddingEquipmentPage_ComponentsListLabel->Text = L"Список компонентов оборудования";
			this->AddingEquipmentPage_ComponentsListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_ComponentsListDataGrid
			// 
			this->AddingEquipmentPage_ComponentsListDataGrid->AllowUserToAddRows = false;
			this->AddingEquipmentPage_ComponentsListDataGrid->BackgroundColor = System::Drawing::Color::White;
			this->AddingEquipmentPage_ComponentsListDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->AddingEquipmentPage_ComponentsListDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->AddingEquipmentPage_ComponentsListDataGrid->Location = System::Drawing::Point(512, 85);
			this->AddingEquipmentPage_ComponentsListDataGrid->Name = L"AddingEquipmentPage_ComponentsListDataGrid";
			this->AddingEquipmentPage_ComponentsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_ComponentsListDataGrid->Size = System::Drawing::Size(363, 135);
			this->AddingEquipmentPage_ComponentsListDataGrid->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->Frozen = true;
			this->dataGridViewTextBoxColumn4->HeaderText = L"Id Оборудования";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 50;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->Frozen = true;
			this->dataGridViewTextBoxColumn5->HeaderText = L"Название детали";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 170;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->Frozen = true;
			this->dataGridViewTextBoxColumn6->HeaderText = L"Требуемое количество деталей, шт.";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 225;
			// 
			// EquipmentPriceCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1209, 857);
			this->Controls->Add(this->AddingEquipmentPage);
			this->Controls->Add(this->EquipmentListPage);
			this->Controls->Add(this->DetailsListPage);
			this->Controls->Add(this->HomePage);
			this->Controls->Add(this->MainTopMenu);
			this->MainMenuStrip = this->MainTopMenu;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EquipmentPriceCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EquipmentPriceCalculator";
			this->Load += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onAppLoad);
			this->HomePage->ResumeLayout(false);
			this->HomePage->PerformLayout();
			this->DetailsListPage->ResumeLayout(false);
			this->DetailsListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->EndInit();
			this->EquipmentListPage->ResumeLayout(false);
			this->EquipmentListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->EndInit();
			this->MainTopMenu->ResumeLayout(false);
			this->MainTopMenu->PerformLayout();
			this->AddingEquipmentPage->ResumeLayout(false);
			this->AddingEquipmentPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_DetailsListDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_ComponentsListDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//App
	private: System::Void onAppLoad(System::Object^ sender, System::EventArgs^ e) {};

	private: void OnKeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->Control && e->KeyCode == Keys::S) {
			this->GlobalStorage.SaveAllInFile();
		}
	}
		   //MainTopMenu

	private: System::Void MainTopMenu_OpenExtraFileDialog(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainTopMenu_SaveFile(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainTopMenu_SaveFileAs(System::Object^ sender, System::EventArgs^ e);

		   //MainPage
	private: System::Void ShowGuidOnClick(System::Object^ sender, System::EventArgs^ e);

		   //DetailsPage
	private: System::Void GoBackFromDetailsPageToHomePage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e);

		   //DetailsList
	private: System::Void OnLoad_DetailsListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsListInDetailsGrid();
	private: System::Void onSelectDetailsListSortType(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DetailsGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void deleteDetail_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DetailsList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void DetailsGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void DetailsListPage_DataGrid_OpeningDetailsAddingWindow(System::Object^ sender, System::EventArgs^ e);
	private: void OnGivingNewDetailsInfoEvent(Object^ sender, GivingNewDetailsInfoEventArgs^ e);
	private: System::Void DetailsListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowEquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void goBackToMainMenuFromDetailsList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void goBackToMainMenuFromEquipmentListPage(System::Object^ sender, System::EventArgs^ e);

		   //EquipmentList
	private: System::Void ShowEquipmentListInEquipmentGrid();
	private: System::Void OnLoad_EquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EquipmentGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void EquipmentList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void deleteEquipment_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void onSelectEquipmentsListSortType(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EquipmentListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);

			//AddingEquipmentPage
	private: System::Void AddingEquipmentPage_ShowDetailsListInDetailsGrid();
	private: System::Void AddingEquipmentPage_DetailsListSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
