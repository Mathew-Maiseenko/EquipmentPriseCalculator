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

			DetailsPage->Hide();

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
	private: System::Windows::Forms::Panel^ EquipmentPage;
	protected:

	private: System::Windows::Forms::Panel^ HomePage;
	protected:


	protected:

	private: System::Windows::Forms::Label^ AuthorNameLabel;
	private: System::Windows::Forms::Button^ HomePage_UsersGuidButton;
	private: System::Windows::Forms::Button^ HomePage_EquipmentButton;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ HomePage_DetailsButton;
	private: System::Windows::Forms::Label^ EquipmentPage_Title;
	private: System::Windows::Forms::Button^ EquipmentPage_EditListButton;




	private: System::Windows::Forms::Button^ EquipmentPage_ViewWholeListButton;
	private: System::Windows::Forms::Button^ EquipmentPage_ExitButton;







	private: System::Windows::Forms::Button^ EquipmentPage_SearchButton;
	private: System::Windows::Forms::Panel^ DetailsPage;
	private: System::Windows::Forms::Button^ DetailsPage_ExitButton;



	private: System::Windows::Forms::Button^ DetailsPage_SearchButton;

	private: System::Windows::Forms::Button^ DetailsPage_EditListButton;
	private: System::Windows::Forms::Button^ DetailsPage_ViewWholeListButton;



	private: System::Windows::Forms::Label^ DetailsPage_Title;

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
			this->EquipmentPage = (gcnew System::Windows::Forms::Panel());
			this->EquipmentPage_ExitButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentPage_SearchButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentPage_EditListButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentPage_ViewWholeListButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentPage_Title = (gcnew System::Windows::Forms::Label());
			this->HomePage = (gcnew System::Windows::Forms::Panel());
			this->AuthorNameLabel = (gcnew System::Windows::Forms::Label());
			this->HomePage_UsersGuidButton = (gcnew System::Windows::Forms::Button());
			this->HomePage_EquipmentButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HomePage_DetailsButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPage = (gcnew System::Windows::Forms::Panel());
			this->DetailsPage_ExitButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPage_SearchButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPage_EditListButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPage_ViewWholeListButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPage_Title = (gcnew System::Windows::Forms::Label());
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
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EquipmentPage->SuspendLayout();
			this->HomePage->SuspendLayout();
			this->DetailsPage->SuspendLayout();
			this->DetailsListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->BeginInit();
			this->EquipmentListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// EquipmentPage
			// 
			this->EquipmentPage->Controls->Add(this->EquipmentPage_ExitButton);
			this->EquipmentPage->Controls->Add(this->EquipmentPage_SearchButton);
			this->EquipmentPage->Controls->Add(this->EquipmentPage_EditListButton);
			this->EquipmentPage->Controls->Add(this->EquipmentPage_ViewWholeListButton);
			this->EquipmentPage->Controls->Add(this->EquipmentPage_Title);
			this->EquipmentPage->Location = System::Drawing::Point(1232, 4);
			this->EquipmentPage->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentPage->Name = L"EquipmentPage";
			this->EquipmentPage->Size = System::Drawing::Size(364, 217);
			this->EquipmentPage->TabIndex = 0;
			// 
			// EquipmentPage_ExitButton
			// 
			this->EquipmentPage_ExitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentPage_ExitButton->BackColor = System::Drawing::Color::DarkRed;
			this->EquipmentPage_ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentPage_ExitButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->EquipmentPage_ExitButton->Location = System::Drawing::Point(195, 149);
			this->EquipmentPage_ExitButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentPage_ExitButton->Name = L"EquipmentPage_ExitButton";
			this->EquipmentPage_ExitButton->Size = System::Drawing::Size(332, 95);
			this->EquipmentPage_ExitButton->TabIndex = 13;
			this->EquipmentPage_ExitButton->Text = L"Назад";
			this->EquipmentPage_ExitButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentPage_SearchButton
			// 
			this->EquipmentPage_SearchButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentPage_SearchButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->EquipmentPage_SearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentPage_SearchButton->Location = System::Drawing::Point(-173, 149);
			this->EquipmentPage_SearchButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentPage_SearchButton->Name = L"EquipmentPage_SearchButton";
			this->EquipmentPage_SearchButton->Size = System::Drawing::Size(332, 95);
			this->EquipmentPage_SearchButton->TabIndex = 12;
			this->EquipmentPage_SearchButton->Text = L"Поиск";
			this->EquipmentPage_SearchButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentPage_EditListButton
			// 
			this->EquipmentPage_EditListButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentPage_EditListButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->EquipmentPage_EditListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentPage_EditListButton->Location = System::Drawing::Point(195, 20);
			this->EquipmentPage_EditListButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentPage_EditListButton->Name = L"EquipmentPage_EditListButton";
			this->EquipmentPage_EditListButton->Size = System::Drawing::Size(332, 95);
			this->EquipmentPage_EditListButton->TabIndex = 11;
			this->EquipmentPage_EditListButton->Text = L"Редактировать список";
			this->EquipmentPage_EditListButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentPage_ViewWholeListButton
			// 
			this->EquipmentPage_ViewWholeListButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentPage_ViewWholeListButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->EquipmentPage_ViewWholeListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentPage_ViewWholeListButton->Location = System::Drawing::Point(-168, 20);
			this->EquipmentPage_ViewWholeListButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentPage_ViewWholeListButton->Name = L"EquipmentPage_ViewWholeListButton";
			this->EquipmentPage_ViewWholeListButton->Size = System::Drawing::Size(327, 95);
			this->EquipmentPage_ViewWholeListButton->TabIndex = 10;
			this->EquipmentPage_ViewWholeListButton->Text = L"Смотреть весь список";
			this->EquipmentPage_ViewWholeListButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentPage_Title
			// 
			this->EquipmentPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentPage_Title->AutoSize = true;
			this->EquipmentPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->EquipmentPage_Title->Location = System::Drawing::Point(37, -49);
			this->EquipmentPage_Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EquipmentPage_Title->Name = L"EquipmentPage_Title";
			this->EquipmentPage_Title->Size = System::Drawing::Size(262, 39);
			this->EquipmentPage_Title->TabIndex = 10;
			this->EquipmentPage_Title->Text = L"Оборудование";
			this->EquipmentPage_Title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePage
			// 
			this->HomePage->Controls->Add(this->AuthorNameLabel);
			this->HomePage->Controls->Add(this->HomePage_UsersGuidButton);
			this->HomePage->Controls->Add(this->HomePage_EquipmentButton);
			this->HomePage->Controls->Add(this->label1);
			this->HomePage->Controls->Add(this->HomePage_DetailsButton);
			this->HomePage->Location = System::Drawing::Point(423, 4);
			this->HomePage->Margin = System::Windows::Forms::Padding(4);
			this->HomePage->Name = L"HomePage";
			this->HomePage->Size = System::Drawing::Size(787, 326);
			this->HomePage->TabIndex = 1;
			// 
			// AuthorNameLabel
			// 
			this->AuthorNameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AuthorNameLabel->AutoSize = true;
			this->AuthorNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AuthorNameLabel->Location = System::Drawing::Point(194, 61);
			this->AuthorNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AuthorNameLabel->Name = L"AuthorNameLabel";
			this->AuthorNameLabel->Size = System::Drawing::Size(424, 31);
			this->AuthorNameLabel->TabIndex = 9;
			this->AuthorNameLabel->Text = L"Майсеенко Матвей Андреевич";
			this->AuthorNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePage_UsersGuidButton
			// 
			this->HomePage_UsersGuidButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_UsersGuidButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_UsersGuidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_UsersGuidButton->Location = System::Drawing::Point(71, 245);
			this->HomePage_UsersGuidButton->Margin = System::Windows::Forms::Padding(4);
			this->HomePage_UsersGuidButton->Name = L"HomePage_UsersGuidButton";
			this->HomePage_UsersGuidButton->Size = System::Drawing::Size(652, 54);
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
			this->HomePage_EquipmentButton->Location = System::Drawing::Point(403, 126);
			this->HomePage_EquipmentButton->Margin = System::Windows::Forms::Padding(4);
			this->HomePage_EquipmentButton->Name = L"HomePage_EquipmentButton";
			this->HomePage_EquipmentButton->Size = System::Drawing::Size(320, 111);
			this->HomePage_EquipmentButton->TabIndex = 7;
			this->HomePage_EquipmentButton->Text = L"Оборудование";
			this->HomePage_EquipmentButton->UseVisualStyleBackColor = false;
			this->HomePage_EquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowEquipmentPage);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label1->Location = System::Drawing::Point(88, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(597, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Калькулятор себестоимости оборудования";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePage_DetailsButton
			// 
			this->HomePage_DetailsButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_DetailsButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_DetailsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_DetailsButton->Location = System::Drawing::Point(71, 126);
			this->HomePage_DetailsButton->Margin = System::Windows::Forms::Padding(4);
			this->HomePage_DetailsButton->Name = L"HomePage_DetailsButton";
			this->HomePage_DetailsButton->Size = System::Drawing::Size(320, 111);
			this->HomePage_DetailsButton->TabIndex = 5;
			this->HomePage_DetailsButton->Text = L"Детали";
			this->HomePage_DetailsButton->UseVisualStyleBackColor = false;
			this->HomePage_DetailsButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsPage);
			// 
			// DetailsPage
			// 
			this->DetailsPage->Controls->Add(this->DetailsPage_ExitButton);
			this->DetailsPage->Controls->Add(this->DetailsPage_SearchButton);
			this->DetailsPage->Controls->Add(this->DetailsPage_EditListButton);
			this->DetailsPage->Controls->Add(this->DetailsPage_ViewWholeListButton);
			this->DetailsPage->Controls->Add(this->DetailsPage_Title);
			this->DetailsPage->Location = System::Drawing::Point(38, 24);
			this->DetailsPage->Margin = System::Windows::Forms::Padding(4);
			this->DetailsPage->Name = L"DetailsPage";
			this->DetailsPage->Size = System::Drawing::Size(54, 217);
			this->DetailsPage->TabIndex = 14;
			// 
			// DetailsPage_ExitButton
			// 
			this->DetailsPage_ExitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsPage_ExitButton->BackColor = System::Drawing::Color::DarkRed;
			this->DetailsPage_ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsPage_ExitButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsPage_ExitButton->Location = System::Drawing::Point(41, 149);
			this->DetailsPage_ExitButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsPage_ExitButton->Name = L"DetailsPage_ExitButton";
			this->DetailsPage_ExitButton->Size = System::Drawing::Size(332, 95);
			this->DetailsPage_ExitButton->TabIndex = 13;
			this->DetailsPage_ExitButton->Text = L"Назад";
			this->DetailsPage_ExitButton->UseVisualStyleBackColor = false;
			this->DetailsPage_ExitButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::GoBackFromDetailsPageToHomePage);
			// 
			// DetailsPage_SearchButton
			// 
			this->DetailsPage_SearchButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsPage_SearchButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DetailsPage_SearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsPage_SearchButton->Location = System::Drawing::Point(-327, 149);
			this->DetailsPage_SearchButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsPage_SearchButton->Name = L"DetailsPage_SearchButton";
			this->DetailsPage_SearchButton->Size = System::Drawing::Size(332, 95);
			this->DetailsPage_SearchButton->TabIndex = 12;
			this->DetailsPage_SearchButton->Text = L"Поиск";
			this->DetailsPage_SearchButton->UseVisualStyleBackColor = false;
			// 
			// DetailsPage_EditListButton
			// 
			this->DetailsPage_EditListButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsPage_EditListButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DetailsPage_EditListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsPage_EditListButton->Location = System::Drawing::Point(41, 20);
			this->DetailsPage_EditListButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsPage_EditListButton->Name = L"DetailsPage_EditListButton";
			this->DetailsPage_EditListButton->Size = System::Drawing::Size(332, 95);
			this->DetailsPage_EditListButton->TabIndex = 11;
			this->DetailsPage_EditListButton->Text = L"Редактировать список";
			this->DetailsPage_EditListButton->UseVisualStyleBackColor = false;
			// 
			// DetailsPage_ViewWholeListButton
			// 
			this->DetailsPage_ViewWholeListButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsPage_ViewWholeListButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DetailsPage_ViewWholeListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsPage_ViewWholeListButton->Location = System::Drawing::Point(-322, 20);
			this->DetailsPage_ViewWholeListButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsPage_ViewWholeListButton->Name = L"DetailsPage_ViewWholeListButton";
			this->DetailsPage_ViewWholeListButton->Size = System::Drawing::Size(327, 95);
			this->DetailsPage_ViewWholeListButton->TabIndex = 10;
			this->DetailsPage_ViewWholeListButton->Text = L"Смотреть весь список";
			this->DetailsPage_ViewWholeListButton->UseVisualStyleBackColor = false;
			this->DetailsPage_ViewWholeListButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsListPage);
			// 
			// DetailsPage_Title
			// 
			this->DetailsPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsPage_Title->AutoSize = true;
			this->DetailsPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsPage_Title->Location = System::Drawing::Point(-55, -49);
			this->DetailsPage_Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DetailsPage_Title->Name = L"DetailsPage_Title";
			this->DetailsPage_Title->Size = System::Drawing::Size(141, 39);
			this->DetailsPage_Title->TabIndex = 10;
			this->DetailsPage_Title->Text = L"Детали";
			this->DetailsPage_Title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->DetailsListPage->Location = System::Drawing::Point(4, 331);
			this->DetailsListPage->Margin = System::Windows::Forms::Padding(4);
			this->DetailsListPage->Name = L"DetailsListPage";
			this->DetailsListPage->Size = System::Drawing::Size(729, 370);
			this->DetailsListPage->TabIndex = 15;
			this->DetailsListPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_DetailsListPage);
			// 
			// DetailsListPage_SearchInput
			// 
			this->DetailsListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DetailsListPage_SearchInput->Location = System::Drawing::Point(19, 89);
			this->DetailsListPage_SearchInput->Name = L"DetailsListPage_SearchInput";
			this->DetailsListPage_SearchInput->Size = System::Drawing::Size(484, 32);
			this->DetailsListPage_SearchInput->TabIndex = 18;
			this->DetailsListPage_SearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_SearchInput_TextChanged);
			// 
			// DetailsListPage_AddingButton
			// 
			this->DetailsListPage_AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->DetailsListPage_AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsListPage_AddingButton->Location = System::Drawing::Point(513, 193);
			this->DetailsListPage_AddingButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsListPage_AddingButton->Name = L"DetailsListPage_AddingButton";
			this->DetailsListPage_AddingButton->Size = System::Drawing::Size(205, 64);
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
			this->DetailsListPage_SortTypeComboBox->Location = System::Drawing::Point(513, 133);
			this->DetailsListPage_SortTypeComboBox->Margin = System::Windows::Forms::Padding(4);
			this->DetailsListPage_SortTypeComboBox->Name = L"DetailsListPage_SortTypeComboBox";
			this->DetailsListPage_SortTypeComboBox->Size = System::Drawing::Size(204, 24);
			this->DetailsListPage_SortTypeComboBox->TabIndex = 16;
			this->DetailsListPage_SortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onSelectDetailsListSortType);
			// 
			// DetailsListPage_SortTypeMessage
			// 
			this->DetailsListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_SortTypeMessage->AutoSize = true;
			this->DetailsListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsListPage_SortTypeMessage->Location = System::Drawing::Point(518, 89);
			this->DetailsListPage_SortTypeMessage->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DetailsListPage_SortTypeMessage->Name = L"DetailsListPage_SortTypeMessage";
			this->DetailsListPage_SortTypeMessage->Size = System::Drawing::Size(199, 29);
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
			this->DetailsListPage_ExitButton->Location = System::Drawing::Point(513, 279);
			this->DetailsListPage_ExitButton->Margin = System::Windows::Forms::Padding(4);
			this->DetailsListPage_ExitButton->Name = L"DetailsListPage_ExitButton";
			this->DetailsListPage_ExitButton->Size = System::Drawing::Size(205, 70);
			this->DetailsListPage_ExitButton->TabIndex = 14;
			this->DetailsListPage_ExitButton->Text = L"Назад";
			this->DetailsListPage_ExitButton->UseVisualStyleBackColor = false;
			// 
			// DetailsListPage_Title
			// 
			this->DetailsListPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_Title->AutoSize = true;
			this->DetailsListPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DetailsListPage_Title->Location = System::Drawing::Point(12, 18);
			this->DetailsListPage_Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DetailsListPage_Title->Name = L"DetailsListPage_Title";
			this->DetailsListPage_Title->Size = System::Drawing::Size(336, 46);
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
			this->DetailsListPage_DataGrid->Location = System::Drawing::Point(19, 133);
			this->DetailsListPage_DataGrid->Margin = System::Windows::Forms::Padding(4);
			this->DetailsListPage_DataGrid->Name = L"DetailsListPage_DataGrid";
			this->DetailsListPage_DataGrid->RowHeadersWidth = 51;
			this->DetailsListPage_DataGrid->Size = System::Drawing::Size(484, 216);
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
			this->EquipmentListPage->Location = System::Drawing::Point(741, 331);
			this->EquipmentListPage->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentListPage->Name = L"EquipmentListPage";
			this->EquipmentListPage->Size = System::Drawing::Size(729, 370);
			this->EquipmentListPage->TabIndex = 19;
			// 
			// EquipmentListPage_SearchInput
			// 
			this->EquipmentListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EquipmentListPage_SearchInput->Location = System::Drawing::Point(19, 89);
			this->EquipmentListPage_SearchInput->Name = L"EquipmentListPage_SearchInput";
			this->EquipmentListPage_SearchInput->Size = System::Drawing::Size(484, 32);
			this->EquipmentListPage_SearchInput->TabIndex = 18;
			// 
			// EquipmentListPage__AddingButton
			// 
			this->EquipmentListPage__AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage__AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->EquipmentListPage__AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentListPage__AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->EquipmentListPage__AddingButton->Location = System::Drawing::Point(513, 193);
			this->EquipmentListPage__AddingButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentListPage__AddingButton->Name = L"EquipmentListPage__AddingButton";
			this->EquipmentListPage__AddingButton->Size = System::Drawing::Size(205, 64);
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
			this->EquipmentListPage__SortTypeComboBox->Location = System::Drawing::Point(513, 133);
			this->EquipmentListPage__SortTypeComboBox->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentListPage__SortTypeComboBox->Name = L"EquipmentListPage__SortTypeComboBox";
			this->EquipmentListPage__SortTypeComboBox->Size = System::Drawing::Size(204, 24);
			this->EquipmentListPage__SortTypeComboBox->TabIndex = 16;
			// 
			// EquipmentListPage_SortTypeMessage
			// 
			this->EquipmentListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_SortTypeMessage->AutoSize = true;
			this->EquipmentListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->EquipmentListPage_SortTypeMessage->Location = System::Drawing::Point(518, 89);
			this->EquipmentListPage_SortTypeMessage->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EquipmentListPage_SortTypeMessage->Name = L"EquipmentListPage_SortTypeMessage";
			this->EquipmentListPage_SortTypeMessage->Size = System::Drawing::Size(199, 29);
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
			this->EquipmentListPage_ExitButton->Location = System::Drawing::Point(513, 279);
			this->EquipmentListPage_ExitButton->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentListPage_ExitButton->Name = L"EquipmentListPage_ExitButton";
			this->EquipmentListPage_ExitButton->Size = System::Drawing::Size(205, 70);
			this->EquipmentListPage_ExitButton->TabIndex = 14;
			this->EquipmentListPage_ExitButton->Text = L"Назад";
			this->EquipmentListPage_ExitButton->UseVisualStyleBackColor = false;
			// 
			// EquipmentListPage_Title
			// 
			this->EquipmentListPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_Title->AutoSize = true;
			this->EquipmentListPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EquipmentListPage_Title->Location = System::Drawing::Point(12, 18);
			this->EquipmentListPage_Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EquipmentListPage_Title->Name = L"EquipmentListPage_Title";
			this->EquipmentListPage_Title->Size = System::Drawing::Size(455, 46);
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
			this->EquipmentListPage_DataGrid->Location = System::Drawing::Point(19, 133);
			this->EquipmentListPage_DataGrid->Margin = System::Windows::Forms::Padding(4);
			this->EquipmentListPage_DataGrid->Name = L"EquipmentListPage_DataGrid";
			this->EquipmentListPage_DataGrid->RowHeadersWidth = 51;
			this->EquipmentListPage_DataGrid->Size = System::Drawing::Size(484, 216);
			this->EquipmentListPage_DataGrid->TabIndex = 0;
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
			// EquipmentPriceCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1612, 1055);
			this->Controls->Add(this->EquipmentListPage);
			this->Controls->Add(this->DetailsListPage);
			this->Controls->Add(this->DetailsPage);
			this->Controls->Add(this->HomePage);
			this->Controls->Add(this->EquipmentPage);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EquipmentPriceCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EquipmentPriceCalculator";
			this->Load += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onAppLoad);
			this->EquipmentPage->ResumeLayout(false);
			this->EquipmentPage->PerformLayout();
			this->HomePage->ResumeLayout(false);
			this->HomePage->PerformLayout();
			this->DetailsPage->ResumeLayout(false);
			this->DetailsPage->PerformLayout();
			this->DetailsListPage->ResumeLayout(false);
			this->DetailsListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->EndInit();
			this->EquipmentListPage->ResumeLayout(false);
			this->EquipmentListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->EndInit();
			this->ResumeLayout(false);

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
	//MainPage
	private: System::Void ShowGuidOnClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowEquipmentPage(System::Object^ sender, System::EventArgs^ e);

	//DetailsPage
	private: System::Void GoBackFromDetailsPageToHomePage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e);

	//DetailsList
	private: System::Void OnLoad_DetailsListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsListInDetailsGrid();
	private: System::Void onSelectDetailsListSortType(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DetailsGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void deleteDetail_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EquipmentPriceCalculator::menu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void DetailsGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void DetailsListPage_DataGrid_OpeningDetailsAddingWindow(System::Object^ sender, System::EventArgs^ e);
	private: void OnGivingNewDetailsInfoEvent(Object^ sender, GivingNewDetailsInfoEventArgs^ e);
	private: System::Void DetailsListPage_SearchInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
