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

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailPrice;
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
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::Button^ DetailsListPage_SavingButton;
private: System::Windows::Forms::MenuStrip^ MainTopMenu;
private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ сохранитьКакToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ окноToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ деталиToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ оборудованиеToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ главнаяИнформацияToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ руководствоПользователяToolStripMenuItem;
private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;









	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->DetailsListPage_SavingButton = (gcnew System::Windows::Forms::Button());
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
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MainTopMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->окноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->деталиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оборудованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->главнаяИнформацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->руководствоПользователяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->HomePage->SuspendLayout();
			this->DetailsListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->BeginInit();
			this->EquipmentListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->BeginInit();
			this->MainTopMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// HomePage
			// 
			this->HomePage->Controls->Add(this->HomePage_UsersGuidButton);
			this->HomePage->Controls->Add(this->HomePage_EquipmentButton);
			this->HomePage->Controls->Add(this->label1);
			this->HomePage->Controls->Add(this->HomePage_DetailsButton);
			this->HomePage->Location = System::Drawing::Point(317, 59);
			this->HomePage->Name = L"HomePage";
			this->HomePage->Size = System::Drawing::Size(590, 245);
			this->HomePage->TabIndex = 1;
			// 
			// HomePage_UsersGuidButton
			// 
			this->HomePage_UsersGuidButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_UsersGuidButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_UsersGuidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_UsersGuidButton->Location = System::Drawing::Point(53, 189);
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
			this->HomePage_EquipmentButton->Location = System::Drawing::Point(302, 92);
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
			this->label1->Location = System::Drawing::Point(48, 25);
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
			this->HomePage_DetailsButton->Location = System::Drawing::Point(53, 92);
			this->HomePage_DetailsButton->Name = L"HomePage_DetailsButton";
			this->HomePage_DetailsButton->Size = System::Drawing::Size(240, 90);
			this->HomePage_DetailsButton->TabIndex = 5;
			this->HomePage_DetailsButton->Text = L"Детали";
			this->HomePage_DetailsButton->UseVisualStyleBackColor = false;
			this->HomePage_DetailsButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsListPage);
			// 
			// DetailsListPage
			// 
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SavingButton);
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
			// DetailsListPage_SavingButton
			// 
			this->DetailsListPage_SavingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_SavingButton->BackColor = System::Drawing::Color::DodgerBlue;
			this->DetailsListPage_SavingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_SavingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsListPage_SavingButton->Location = System::Drawing::Point(383, 193);
			this->DetailsListPage_SavingButton->Name = L"DetailsListPage_SavingButton";
			this->DetailsListPage_SavingButton->Size = System::Drawing::Size(154, 52);
			this->DetailsListPage_SavingButton->TabIndex = 19;
			this->DetailsListPage_SavingButton->Text = L"Сохранить";
			this->DetailsListPage_SavingButton->UseVisualStyleBackColor = false;
			this->DetailsListPage_SavingButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsSavingWindow);
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
			this->DetailId->HeaderText = L"Id детали";
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
				L"Id детали", L"Названию детали",
					L"Стоимости детали"
			});
			this->EquipmentListPage__SortTypeComboBox->Location = System::Drawing::Point(385, 108);
			this->EquipmentListPage__SortTypeComboBox->Name = L"EquipmentListPage__SortTypeComboBox";
			this->EquipmentListPage__SortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->EquipmentListPage__SortTypeComboBox->TabIndex = 16;
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
			this->EquipmentListPage_DataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->EquipmentListPage_DataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
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
			this->dataGridViewTextBoxColumn1->HeaderText = L"Id Оборудования";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Frozen = true;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Название детали";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 170;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->Frozen = true;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Стоимость детали, р/шт";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// MainTopMenu
			// 
			this->MainTopMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->окноToolStripMenuItem, this->оПрограммеToolStripMenuItem
			});
			this->MainTopMenu->Location = System::Drawing::Point(0, 0);
			this->MainTopMenu->Name = L"MainTopMenu";
			this->MainTopMenu->Size = System::Drawing::Size(1209, 24);
			this->MainTopMenu->TabIndex = 20;
			this->MainTopMenu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->открытьToolStripMenuItem,
					this->сохранитьToolStripMenuItem, this->сохранитьКакToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::MainTopMenu_OpenExtraFileDialog);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			// 
			// сохранитьКакToolStripMenuItem
			// 
			this->сохранитьКакToolStripMenuItem->Name = L"сохранитьКакToolStripMenuItem";
			this->сохранитьКакToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->сохранитьКакToolStripMenuItem->Text = L"Сохранить как";
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
			this->OpenFileDialog->FileName = L"openFileDialog1";
			// 
			// EquipmentPriceCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1209, 857);
			this->Controls->Add(this->EquipmentListPage);
			this->Controls->Add(this->DetailsListPage);
			this->Controls->Add(this->HomePage);
			this->Controls->Add(this->MainTopMenu);
			this->MainMenuStrip = this->MainTopMenu;
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//App
	private: System::Void onAppLoad(System::Object^ sender, System::EventArgs^ e) {
		//System::Windows::Forms::ContextMenuStrip^ DetailsGridmenu = gcnew System::Windows::Forms::ContextMenuStrip();
		//DataGridView^ DetailsGrid = this->DetailsListPage_DataGrid;
		//ToolStripMenuItem^ deleteDetail = gcnew ToolStripMenuItem("Удалить");
		//DetailsGridmenu->Items->Add(deleteDetail);
		//DetailsGrid->ContextMenuStrip = DetailsGridmenu;
	};
	//MainTopMenu

	private: System::Void MainTopMenu_OpenExtraFileDialog(System::Object^ sender, System::EventArgs^ e);
	
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
	private: System::Void EquipmentPriceCalculator::DetailsList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void DetailsGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void DetailsListPage_DataGrid_OpeningDetailsAddingWindow(System::Object^ sender, System::EventArgs^ e);
	private: void OnGivingNewDetailsInfoEvent(Object^ sender, GivingNewDetailsInfoEventArgs^ e);
	private: System::Void DetailsListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowEquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void goBackToMainMenuFromDetailsList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void goBackToMainMenuFromEquipmentListPage(System::Object^ sender, System::EventArgs^ e);

	private: System::Void DetailsListPage_DataGrid_OpeningDetailsSavingWindow(System::Object^ sender, System::EventArgs^ e);

	//EquipmentList
	private: System::Void ShowEquipmentListInEquipmentGrid();
	private: System::Void OnLoad_EquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EquipmentGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void EquipmentPriceCalculator::EquipmentList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void deleteEquipment_onClick(System::Object^ sender, System::EventArgs^ e);
};
}
