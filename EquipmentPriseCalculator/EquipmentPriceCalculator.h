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
			AddingEquipmentPage->Hide();
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
private: System::Windows::Forms::Button^ AddingEquipmentPage_AddingEquipmentButton;



private: System::Windows::Forms::ComboBox^ AddingEquipmentPage_ComponemtsListSortTypeComboBox;

private: System::Windows::Forms::Label^ AddingEquipmentPage_ComponentsListSortTypeLabel;
private: System::Windows::Forms::Button^ AddingEquipmentPage_ExitfromAddingEquipmentPageButton;


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





private: System::Windows::Forms::TextBox^ AddingEquipmentPage_EquipmentNameInput;
private: System::Windows::Forms::DataGridViewButtonColumn^ Column4;
private: System::Windows::Forms::DataGridViewButtonColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::ToolStripMenuItem^ создатьToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ заказToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ добавитьДеталиToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ добавитьОборудованиеToolStripMenuItem;
private: System::Windows::Forms::Panel^ OrderPage;
private: System::Windows::Forms::TextBox^ OrderPage_EquipmentSearchTextBox;



private: System::Windows::Forms::ComboBox^ OrderPage_EquipmentSortTypeComboBox;

private: System::Windows::Forms::Label^ OrderPage_EquipmentSortTypeTitle;

private: System::Windows::Forms::Label^ OrderPage_WholeEquipmentListLabel;
private: System::Windows::Forms::TextBox^ OrderPage_OrderedEquipmentSearchTextBox;






private: System::Windows::Forms::Button^ OrderPage_MakeOrderButton;
private: System::Windows::Forms::ComboBox^ OrderPage_OrderedEquipmentSortTypeComboBox;


private: System::Windows::Forms::Label^ OrderPage_OrderedEquipmentSortTypeTitle;

private: System::Windows::Forms::Button^ OrderPage_GoToMainMenuButton;
private: System::Windows::Forms::Label^ OrderPage_OrderedEquipmentListLabel;
private: System::Windows::Forms::DataGridView^ OrderPage_OrderedEquipmentDataGrid;
private: System::Windows::Forms::DataGridView^ OrderPage_EquipmentDataGrid;













private: System::Windows::Forms::Label^ OrderPage_TotalPrice;

private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn16;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;































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
			this->создатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_OpenFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileAsButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->окноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->деталиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьДеталиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оборудованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьОборудованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->заказToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->главнаяИнформацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->руководствоПользователяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileAsDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->AddingEquipmentPage = (gcnew System::Windows::Forms::Panel());
			this->AddingEquipmentPage_EquipmentNameInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_DetailsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_DetailsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_DetailsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddingEquipmentPage_ComponentsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_AddingEquipmentButton = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_ComponentsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ComponentsListLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_ComponentsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrderPage = (gcnew System::Windows::Forms::Panel());
			this->OrderPage_TotalPrice = (gcnew System::Windows::Forms::Label());
			this->OrderPage_EquipmentDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrderPage_EquipmentSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrderPage_EquipmentSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->OrderPage_EquipmentSortTypeTitle = (gcnew System::Windows::Forms::Label());
			this->OrderPage_WholeEquipmentListLabel = (gcnew System::Windows::Forms::Label());
			this->OrderPage_OrderedEquipmentSearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OrderPage_MakeOrderButton = (gcnew System::Windows::Forms::Button());
			this->OrderPage_OrderedEquipmentSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->OrderPage_OrderedEquipmentSortTypeTitle = (gcnew System::Windows::Forms::Label());
			this->OrderPage_GoToMainMenuButton = (gcnew System::Windows::Forms::Button());
			this->OrderPage_OrderedEquipmentListLabel = (gcnew System::Windows::Forms::Label());
			this->OrderPage_OrderedEquipmentDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HomePage->SuspendLayout();
			this->DetailsListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->BeginInit();
			this->EquipmentListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->BeginInit();
			this->MainTopMenu->SuspendLayout();
			this->AddingEquipmentPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_DetailsListDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_ComponentsListDataGrid))->BeginInit();
			this->OrderPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_EquipmentDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_OrderedEquipmentDataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// HomePage
			// 
			this->HomePage->Controls->Add(this->HomePage_UsersGuidButton);
			this->HomePage->Controls->Add(this->HomePage_EquipmentButton);
			this->HomePage->Controls->Add(this->label1);
			this->HomePage->Controls->Add(this->HomePage_DetailsButton);
			this->HomePage->Location = System::Drawing::Point(106, 617);
			this->HomePage->Name = L"HomePage";
			this->HomePage->Size = System::Drawing::Size(547, 262);
			this->HomePage->TabIndex = 1;
			// 
			// HomePage_UsersGuidButton
			// 
			this->HomePage_UsersGuidButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_UsersGuidButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_UsersGuidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_UsersGuidButton->Location = System::Drawing::Point(31, 198);
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
			this->HomePage_EquipmentButton->Location = System::Drawing::Point(280, 101);
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
			this->label1->Location = System::Drawing::Point(26, 34);
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
			this->HomePage_DetailsButton->Location = System::Drawing::Point(31, 101);
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
			this->EquipmentListPage__AddingButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::EquipmentListPage__AddingButton_Click);
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
			this->EquipmentListPage_DataGrid->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &EquipmentPriceCalculator::EquipmentListPage_DataGrid_CellBeginEdit);
			this->EquipmentListPage_DataGrid->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPriceCalculator::EquipmentListPage_DataGrid_CellEndEdit);
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
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->создатьToolStripMenuItem,
					this->MainTopMenu_OpenFileButton, this->MainTopMenu_SaveFileButton, this->MainTopMenu_SaveFileAsButton
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// создатьToolStripMenuItem
			// 
			this->создатьToolStripMenuItem->Name = L"создатьToolStripMenuItem";
			this->создатьToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->создатьToolStripMenuItem->Text = L"Создать";
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
			this->окноToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->деталиToolStripMenuItem,
					this->добавитьДеталиToolStripMenuItem, this->оборудованиеToolStripMenuItem, this->добавитьОборудованиеToolStripMenuItem, this->заказToolStripMenuItem
			});
			this->окноToolStripMenuItem->Name = L"окноToolStripMenuItem";
			this->окноToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->окноToolStripMenuItem->Text = L"Окно";
			// 
			// деталиToolStripMenuItem
			// 
			this->деталиToolStripMenuItem->Name = L"деталиToolStripMenuItem";
			this->деталиToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->деталиToolStripMenuItem->Text = L"Детали";
			// 
			// добавитьДеталиToolStripMenuItem
			// 
			this->добавитьДеталиToolStripMenuItem->Name = L"добавитьДеталиToolStripMenuItem";
			this->добавитьДеталиToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->добавитьДеталиToolStripMenuItem->Text = L"Добавить детали";
			// 
			// оборудованиеToolStripMenuItem
			// 
			this->оборудованиеToolStripMenuItem->Name = L"оборудованиеToolStripMenuItem";
			this->оборудованиеToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->оборудованиеToolStripMenuItem->Text = L"Оборудование";
			// 
			// добавитьОборудованиеToolStripMenuItem
			// 
			this->добавитьОборудованиеToolStripMenuItem->Name = L"добавитьОборудованиеToolStripMenuItem";
			this->добавитьОборудованиеToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->добавитьОборудованиеToolStripMenuItem->Text = L"Добавить оборудование";
			// 
			// заказToolStripMenuItem
			// 
			this->заказToolStripMenuItem->Name = L"заказToolStripMenuItem";
			this->заказToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->заказToolStripMenuItem->Text = L"Заказ";
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
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_EquipmentNameInput);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSearchInput);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeComboBox);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_DetailsListDataGrid);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListSearchInput);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_AddingEquipmentButton);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponemtsListSortTypeComboBox);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListSortTypeLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListLabel);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_ComponentsListDataGrid);
			this->AddingEquipmentPage->Location = System::Drawing::Point(3, 617);
			this->AddingEquipmentPage->Name = L"AddingEquipmentPage";
			this->AddingEquipmentPage->Size = System::Drawing::Size(1100, 237);
			this->AddingEquipmentPage->TabIndex = 21;
			this->AddingEquipmentPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_AddingEquipmentPage);
			// 
			// AddingEquipmentPage_EquipmentNameInput
			// 
			this->AddingEquipmentPage_EquipmentNameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->AddingEquipmentPage_EquipmentNameInput->Location = System::Drawing::Point(303, 19);
			this->AddingEquipmentPage_EquipmentNameInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_EquipmentNameInput->Name = L"AddingEquipmentPage_EquipmentNameInput";
			this->AddingEquipmentPage_EquipmentNameInput->Size = System::Drawing::Size(257, 27);
			this->AddingEquipmentPage_EquipmentNameInput->TabIndex = 24;
			this->AddingEquipmentPage_EquipmentNameInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_EquipmentNameInput_TextChanged);
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
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSortTypeComboBox_SelectedIndexChanged);
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
			this->AddingEquipmentPage_DetailsListDataGrid->ReadOnly = true;
			this->AddingEquipmentPage_DetailsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_DetailsListDataGrid->Size = System::Drawing::Size(331, 135);
			this->AddingEquipmentPage_DetailsListDataGrid->TabIndex = 19;
			this->AddingEquipmentPage_DetailsListDataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListDataGrid_MouseClick);
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->Frozen = true;
			this->dataGridViewTextBoxColumn7->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->ReadOnly = true;
			this->dataGridViewTextBoxColumn7->Width = 50;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->Frozen = true;
			this->dataGridViewTextBoxColumn8->HeaderText = L"Название детали";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->ReadOnly = true;
			this->dataGridViewTextBoxColumn8->Width = 170;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->Frozen = true;
			this->dataGridViewTextBoxColumn9->HeaderText = L"Стоимость детали, р/шт";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->ReadOnly = true;
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
			this->AddingEquipmentPage_ComponentsListSearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListSearchInput_TextChanged);
			// 
			// AddingEquipmentPage_AddingEquipmentButton
			// 
			this->AddingEquipmentPage_AddingEquipmentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_AddingEquipmentButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->AddingEquipmentPage_AddingEquipmentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_AddingEquipmentButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->AddingEquipmentPage_AddingEquipmentButton->Location = System::Drawing::Point(908, 132);
			this->AddingEquipmentPage_AddingEquipmentButton->Name = L"AddingEquipmentPage_AddingEquipmentButton";
			this->AddingEquipmentPage_AddingEquipmentButton->Size = System::Drawing::Size(154, 52);
			this->AddingEquipmentPage_AddingEquipmentButton->TabIndex = 17;
			this->AddingEquipmentPage_AddingEquipmentButton->Text = L"Добавить";
			this->AddingEquipmentPage_AddingEquipmentButton->UseVisualStyleBackColor = false;
			this->AddingEquipmentPage_AddingEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_AddingEquipmentButton_Click);
			// 
			// AddingEquipmentPage_ComponemtsListSortTypeComboBox
			// 
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->FormattingEnabled = true;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Id компонента",
					L"Названию компонента", L"Стоимости компонента", L"Количеству компонетов", L"Полной стоимоти компонетов"
			});
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Location = System::Drawing::Point(904, 85);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Name = L"AddingEquipmentPage_ComponemtsListSortTypeComboBox";
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->TabIndex = 16;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponemtsListSortTypeComboBox_SelectedIndexChanged);
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
			// AddingEquipmentPage_ExitfromAddingEquipmentPageButton
			// 
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->BackColor = System::Drawing::Color::DarkRed;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F,
				System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Location = System::Drawing::Point(908, 191);
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Name = L"AddingEquipmentPage_ExitfromAddingEquipmentPageButton";
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Size = System::Drawing::Size(154, 38);
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->TabIndex = 14;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Text = L"Назад";
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->UseVisualStyleBackColor = false;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ExitfromAddingEquipmentPageButton_Click);
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
			this->AddingEquipmentPage_ComponentsListDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column4,
					this->Column3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6, this->Column1,
					this->Column2
			});
			this->AddingEquipmentPage_ComponentsListDataGrid->Location = System::Drawing::Point(513, 85);
			this->AddingEquipmentPage_ComponentsListDataGrid->Name = L"AddingEquipmentPage_ComponentsListDataGrid";
			this->AddingEquipmentPage_ComponentsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_ComponentsListDataGrid->Size = System::Drawing::Size(363, 135);
			this->AddingEquipmentPage_ComponentsListDataGrid->TabIndex = 0;
			this->AddingEquipmentPage_ComponentsListDataGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellContentClick);
			this->AddingEquipmentPage_ComponentsListDataGrid->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_CellEndEdit);
			this->AddingEquipmentPage_ComponentsListDataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListDataGrid_MouseClick);
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"-";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 30;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"+";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 30;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 50;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Название детали";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 170;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Требуемое количество деталей, шт.";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 180;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Стоимоть детали, р/шт";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Полная стоимоть деталей";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 125;
			// 
			// OrderPage
			// 
			this->OrderPage->Controls->Add(this->OrderPage_TotalPrice);
			this->OrderPage->Controls->Add(this->OrderPage_EquipmentDataGrid);
			this->OrderPage->Controls->Add(this->OrderPage_EquipmentSearchTextBox);
			this->OrderPage->Controls->Add(this->OrderPage_EquipmentSortTypeComboBox);
			this->OrderPage->Controls->Add(this->OrderPage_EquipmentSortTypeTitle);
			this->OrderPage->Controls->Add(this->OrderPage_WholeEquipmentListLabel);
			this->OrderPage->Controls->Add(this->OrderPage_OrderedEquipmentSearchTextBox);
			this->OrderPage->Controls->Add(this->OrderPage_MakeOrderButton);
			this->OrderPage->Controls->Add(this->OrderPage_OrderedEquipmentSortTypeComboBox);
			this->OrderPage->Controls->Add(this->OrderPage_OrderedEquipmentSortTypeTitle);
			this->OrderPage->Controls->Add(this->OrderPage_GoToMainMenuButton);
			this->OrderPage->Controls->Add(this->OrderPage_OrderedEquipmentListLabel);
			this->OrderPage->Controls->Add(this->OrderPage_OrderedEquipmentDataGrid);
			this->OrderPage->Location = System::Drawing::Point(3, 46);
			this->OrderPage->Name = L"OrderPage";
			this->OrderPage->Size = System::Drawing::Size(1100, 237);
			this->OrderPage->TabIndex = 22;
			this->OrderPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_VisibleChanged);
			// 
			// OrderPage_TotalPrice
			// 
			this->OrderPage_TotalPrice->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_TotalPrice->AutoSize = true;
			this->OrderPage_TotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_TotalPrice->Location = System::Drawing::Point(363, 182);
			this->OrderPage_TotalPrice->Name = L"OrderPage_TotalPrice";
			this->OrderPage_TotalPrice->Size = System::Drawing::Size(136, 29);
			this->OrderPage_TotalPrice->TabIndex = 25;
			this->OrderPage_TotalPrice->Text = L"00.00 BYN";
			this->OrderPage_TotalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_EquipmentDataGrid
			// 
			this->OrderPage_EquipmentDataGrid->AllowUserToAddRows = false;
			this->OrderPage_EquipmentDataGrid->BackgroundColor = System::Drawing::Color::White;
			this->OrderPage_EquipmentDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OrderPage_EquipmentDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn3,
					this->Column5, this->dataGridViewTextBoxColumn10
			});
			this->OrderPage_EquipmentDataGrid->Location = System::Drawing::Point(8, 86);
			this->OrderPage_EquipmentDataGrid->Name = L"OrderPage_EquipmentDataGrid";
			this->OrderPage_EquipmentDataGrid->RowHeadersWidth = 51;
			this->OrderPage_EquipmentDataGrid->Size = System::Drawing::Size(331, 134);
			this->OrderPage_EquipmentDataGrid->TabIndex = 24;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->Frozen = true;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 50;
			// 
			// Column5
			// 
			this->Column5->Frozen = true;
			this->Column5->HeaderText = L"Стоимость за штуку, р/шт";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->Frozen = true;
			this->dataGridViewTextBoxColumn10->HeaderText = L"Название Оборудования";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->ReadOnly = true;
			this->dataGridViewTextBoxColumn10->Width = 170;
			// 
			// OrderPage_EquipmentSearchTextBox
			// 
			this->OrderPage_EquipmentSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->OrderPage_EquipmentSearchTextBox->Location = System::Drawing::Point(8, 54);
			this->OrderPage_EquipmentSearchTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OrderPage_EquipmentSearchTextBox->Name = L"OrderPage_EquipmentSearchTextBox";
			this->OrderPage_EquipmentSearchTextBox->Size = System::Drawing::Size(332, 27);
			this->OrderPage_EquipmentSearchTextBox->TabIndex = 23;
			this->OrderPage_EquipmentSearchTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentSearchTextBox_TextChanged);
			// 
			// OrderPage_EquipmentSortTypeComboBox
			// 
			this->OrderPage_EquipmentSortTypeComboBox->FormattingEnabled = true;
			this->OrderPage_EquipmentSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали", L"Названию детали",
					L"Стоимости детали"
			});
			this->OrderPage_EquipmentSortTypeComboBox->Location = System::Drawing::Point(353, 85);
			this->OrderPage_EquipmentSortTypeComboBox->Name = L"OrderPage_EquipmentSortTypeComboBox";
			this->OrderPage_EquipmentSortTypeComboBox->Size = System::Drawing::Size(146, 21);
			this->OrderPage_EquipmentSortTypeComboBox->TabIndex = 22;
			this->OrderPage_EquipmentSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentSortTypeComboBox_SelectedIndexChanged);
			// 
			// OrderPage_EquipmentSortTypeTitle
			// 
			this->OrderPage_EquipmentSortTypeTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_EquipmentSortTypeTitle->AutoSize = true;
			this->OrderPage_EquipmentSortTypeTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_EquipmentSortTypeTitle->Location = System::Drawing::Point(349, 54);
			this->OrderPage_EquipmentSortTypeTitle->Name = L"OrderPage_EquipmentSortTypeTitle";
			this->OrderPage_EquipmentSortTypeTitle->Size = System::Drawing::Size(158, 24);
			this->OrderPage_EquipmentSortTypeTitle->TabIndex = 21;
			this->OrderPage_EquipmentSortTypeTitle->Text = L"Сортировка по";
			this->OrderPage_EquipmentSortTypeTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_WholeEquipmentListLabel
			// 
			this->OrderPage_WholeEquipmentListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_WholeEquipmentListLabel->AutoSize = true;
			this->OrderPage_WholeEquipmentListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_WholeEquipmentListLabel->Location = System::Drawing::Point(20, 15);
			this->OrderPage_WholeEquipmentListLabel->Name = L"OrderPage_WholeEquipmentListLabel";
			this->OrderPage_WholeEquipmentListLabel->Size = System::Drawing::Size(378, 29);
			this->OrderPage_WholeEquipmentListLabel->TabIndex = 20;
			this->OrderPage_WholeEquipmentListLabel->Text = L"Общий список оборудования";
			this->OrderPage_WholeEquipmentListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_OrderedEquipmentSearchTextBox
			// 
			this->OrderPage_OrderedEquipmentSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->OrderPage_OrderedEquipmentSearchTextBox->Location = System::Drawing::Point(512, 54);
			this->OrderPage_OrderedEquipmentSearchTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OrderPage_OrderedEquipmentSearchTextBox->Name = L"OrderPage_OrderedEquipmentSearchTextBox";
			this->OrderPage_OrderedEquipmentSearchTextBox->Size = System::Drawing::Size(364, 27);
			this->OrderPage_OrderedEquipmentSearchTextBox->TabIndex = 18;
			this->OrderPage_OrderedEquipmentSearchTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentSearchTextBox_TextChanged);
			// 
			// OrderPage_MakeOrderButton
			// 
			this->OrderPage_MakeOrderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_MakeOrderButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->OrderPage_MakeOrderButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->OrderPage_MakeOrderButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->OrderPage_MakeOrderButton->Location = System::Drawing::Point(908, 132);
			this->OrderPage_MakeOrderButton->Name = L"OrderPage_MakeOrderButton";
			this->OrderPage_MakeOrderButton->Size = System::Drawing::Size(154, 52);
			this->OrderPage_MakeOrderButton->TabIndex = 17;
			this->OrderPage_MakeOrderButton->Text = L"Заказать";
			this->OrderPage_MakeOrderButton->UseVisualStyleBackColor = false;
			// 
			// OrderPage_OrderedEquipmentSortTypeComboBox
			// 
			this->OrderPage_OrderedEquipmentSortTypeComboBox->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->FormattingEnabled = true;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Id оборудования",
					L"Названию оборудования", L"Стоимости одного оборудования", L"Количеству заказанного оборудования", L"Полной стоимоти оборудования"
			});
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Location = System::Drawing::Point(904, 85);
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Name = L"OrderPage_OrderedEquipmentSortTypeComboBox";
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Size = System::Drawing::Size(154, 21);
			this->OrderPage_OrderedEquipmentSortTypeComboBox->TabIndex = 16;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged);
			// 
			// OrderPage_OrderedEquipmentSortTypeTitle
			// 
			this->OrderPage_OrderedEquipmentSortTypeTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_OrderedEquipmentSortTypeTitle->AutoSize = true;
			this->OrderPage_OrderedEquipmentSortTypeTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_OrderedEquipmentSortTypeTitle->Location = System::Drawing::Point(904, 58);
			this->OrderPage_OrderedEquipmentSortTypeTitle->Name = L"OrderPage_OrderedEquipmentSortTypeTitle";
			this->OrderPage_OrderedEquipmentSortTypeTitle->Size = System::Drawing::Size(158, 24);
			this->OrderPage_OrderedEquipmentSortTypeTitle->TabIndex = 15;
			this->OrderPage_OrderedEquipmentSortTypeTitle->Text = L"Сортировка по";
			this->OrderPage_OrderedEquipmentSortTypeTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_GoToMainMenuButton
			// 
			this->OrderPage_GoToMainMenuButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_GoToMainMenuButton->BackColor = System::Drawing::Color::DarkRed;
			this->OrderPage_GoToMainMenuButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->OrderPage_GoToMainMenuButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->OrderPage_GoToMainMenuButton->Location = System::Drawing::Point(908, 191);
			this->OrderPage_GoToMainMenuButton->Name = L"OrderPage_GoToMainMenuButton";
			this->OrderPage_GoToMainMenuButton->Size = System::Drawing::Size(154, 38);
			this->OrderPage_GoToMainMenuButton->TabIndex = 14;
			this->OrderPage_GoToMainMenuButton->Text = L"Назад";
			this->OrderPage_GoToMainMenuButton->UseVisualStyleBackColor = false;
			// 
			// OrderPage_OrderedEquipmentListLabel
			// 
			this->OrderPage_OrderedEquipmentListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_OrderedEquipmentListLabel->AutoSize = true;
			this->OrderPage_OrderedEquipmentListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_OrderedEquipmentListLabel->Location = System::Drawing::Point(508, 15);
			this->OrderPage_OrderedEquipmentListLabel->Name = L"OrderPage_OrderedEquipmentListLabel";
			this->OrderPage_OrderedEquipmentListLabel->Size = System::Drawing::Size(452, 29);
			this->OrderPage_OrderedEquipmentListLabel->TabIndex = 10;
			this->OrderPage_OrderedEquipmentListLabel->Text = L"Список заказанного оборудования";
			this->OrderPage_OrderedEquipmentListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_OrderedEquipmentDataGrid
			// 
			this->OrderPage_OrderedEquipmentDataGrid->AllowUserToAddRows = false;
			this->OrderPage_OrderedEquipmentDataGrid->BackgroundColor = System::Drawing::Color::White;
			this->OrderPage_OrderedEquipmentDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OrderPage_OrderedEquipmentDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->dataGridViewButtonColumn1,
					this->dataGridViewButtonColumn2, this->dataGridViewTextBoxColumn12, this->dataGridViewTextBoxColumn13, this->dataGridViewTextBoxColumn14,
					this->dataGridViewTextBoxColumn15, this->dataGridViewTextBoxColumn16
			});
			this->OrderPage_OrderedEquipmentDataGrid->Location = System::Drawing::Point(513, 85);
			this->OrderPage_OrderedEquipmentDataGrid->Name = L"OrderPage_OrderedEquipmentDataGrid";
			this->OrderPage_OrderedEquipmentDataGrid->RowHeadersWidth = 51;
			this->OrderPage_OrderedEquipmentDataGrid->Size = System::Drawing::Size(363, 135);
			this->OrderPage_OrderedEquipmentDataGrid->TabIndex = 0;
			// 
			// dataGridViewButtonColumn1
			// 
			this->dataGridViewButtonColumn1->HeaderText = L"-";
			this->dataGridViewButtonColumn1->MinimumWidth = 6;
			this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
			this->dataGridViewButtonColumn1->ReadOnly = true;
			this->dataGridViewButtonColumn1->Width = 30;
			// 
			// dataGridViewButtonColumn2
			// 
			this->dataGridViewButtonColumn2->HeaderText = L"+";
			this->dataGridViewButtonColumn2->MinimumWidth = 6;
			this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
			this->dataGridViewButtonColumn2->ReadOnly = true;
			this->dataGridViewButtonColumn2->Width = 30;
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn12->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			this->dataGridViewTextBoxColumn12->ReadOnly = true;
			this->dataGridViewTextBoxColumn12->Width = 50;
			// 
			// dataGridViewTextBoxColumn13
			// 
			this->dataGridViewTextBoxColumn13->HeaderText = L"Название оборудования";
			this->dataGridViewTextBoxColumn13->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
			this->dataGridViewTextBoxColumn13->ReadOnly = true;
			this->dataGridViewTextBoxColumn13->Width = 170;
			// 
			// dataGridViewTextBoxColumn14
			// 
			this->dataGridViewTextBoxColumn14->HeaderText = L"Количество оборудования, шт.";
			this->dataGridViewTextBoxColumn14->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
			this->dataGridViewTextBoxColumn14->Width = 180;
			// 
			// dataGridViewTextBoxColumn15
			// 
			this->dataGridViewTextBoxColumn15->HeaderText = L"Стоимоть за штуку, р/шт";
			this->dataGridViewTextBoxColumn15->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
			this->dataGridViewTextBoxColumn15->ReadOnly = true;
			this->dataGridViewTextBoxColumn15->Width = 125;
			// 
			// dataGridViewTextBoxColumn16
			// 
			this->dataGridViewTextBoxColumn16->HeaderText = L"Полная стоимоть деталей";
			this->dataGridViewTextBoxColumn16->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
			this->dataGridViewTextBoxColumn16->ReadOnly = true;
			this->dataGridViewTextBoxColumn16->Width = 125;
			// 
			// EquipmentPriceCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1209, 857);
			this->Controls->Add(this->OrderPage);
			this->Controls->Add(this->HomePage);
			this->Controls->Add(this->AddingEquipmentPage);
			this->Controls->Add(this->EquipmentListPage);
			this->Controls->Add(this->DetailsListPage);
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
			this->OrderPage->ResumeLayout(false);
			this->OrderPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_EquipmentDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_OrderedEquipmentDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool is_number(const std::string& s) {
		if (s.empty()) {
			std::cerr << "Строка пуста" << std::endl;
			return false;
		}
		bool decimalPoint = false;
		int start = (s[0] == '-') ? 1 : 0; // Начинаем с 1, если число отрицательное

		for (size_t i = start; i < s.size(); ++i) {
			if (s[i] == '.') {
				if (decimalPoint) {
					std::cerr << "Второй символ точки обнаружен в позиции " << i << std::endl;
					return false; // Второй символ точки не разрешается
				}
				decimalPoint = true;
			}
			else if (!std::isdigit(s[i])) {
				std::cerr << "Недопустимый символ обнаружен в позиции " << i << ": " << s[i] << std::endl;
				return false; // Не цифра и не первая точка
			}
		}
		std::cerr << "Строка успешно проверена как число: " << s << std::endl;
		return true;
	}
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
	private: System::Void EquipmentListPage_DataGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
			//AddingEquipmentPage
	private: System::Void AddingEquipmentPage_ShowDetailsListInDetailsGrid();
	private: System::Void AddingEquipmentPage_DetailsListSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OnLoad_AddingEquipmentPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_DetailsListSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void setDetailEquipmentsComponent_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_DetailsListDataGrid_AddingComponentContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void AddingEquipmentPage_DetailsListDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void AddingEquipmentPage_ShowComponentsListInGrid();
	private: System::Void AddingEquipmentPage_ComponemtsListSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_ComponentsListSearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void removeEquipmentsComponent_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_ComponentsListDataGrid_RemovingComponentContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void AddingEquipmentPage_ComponentsListDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void AddingEquipmentPage_EquipmentNameInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_AddingEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_ComponentsListDataGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void AddingEquipmentPage_ComponentsListDataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	String^ ValueBeforeEdit_EquipmentListPage_DataGrid;
	private: System::Void EquipmentListPage_DataGrid_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e);
	private: System::Void EquipmentListPage__AddingButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddingEquipmentPage_ExitfromAddingEquipmentPageButton_Click(System::Object^ sender, System::EventArgs^ e);

			//OrderPage
	private: System::Void ShowEquipmentListInOrderPageEquipmentGrid();
	private: System::Void OrderPage_EquipmentSearchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_EquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_VisibleChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_OrderEquipment_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_EquipmentList_deletingContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void OrderPage_EquipmentGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
	private: System::Void OrderPage_OrderedEquipmentSearchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	  
};
}
