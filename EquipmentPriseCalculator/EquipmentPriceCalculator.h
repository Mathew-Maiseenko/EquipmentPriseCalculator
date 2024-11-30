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

			StartPage->Show();
			MainPage->Hide();
			HomePage->Hide();
			DetailsListPage->Hide();
			EquipmentListPage->Hide();
			AddingEquipmentPage->Hide();
			OrderPage->Hide();
			MainTopMenu->Hide();

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
	private: System::Windows::Forms::Button^ MainPage_UsersGuidButton;
	protected:


	protected:



	private: System::Windows::Forms::Button^ HomePage_EquipmentButton;
	private: System::Windows::Forms::Label^ HomePage_Label;



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















private: System::Windows::Forms::TextBox^ AddingEquipmentPage_EquipmentNameInput;







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
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::SaveFileDialog^ printUsersCheckInFileDialog;
private: System::Windows::Forms::Panel^ MainPage;



private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ HomePage_ExitFromPageButton;
private: System::Windows::Forms::ToolStripMenuItem^ главнаяToolStripMenuItem;
private: System::Windows::Forms::Panel^ StartPage;

private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ StartPage_CreateFileButton;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Button^ StartPage_OpenFileButton;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::DataGridViewButtonColumn^ Column4;
private: System::Windows::Forms::DataGridViewButtonColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailId;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailName;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ DetailPrice;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox7;

private: System::Windows::Forms::PictureBox^ pictureBox11;

private: System::Windows::Forms::PictureBox^ pictureBox9;

private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::PictureBox^ pictureBox13;
private: System::Windows::Forms::PictureBox^ pictureBox14;


private: System::Windows::Forms::PictureBox^ pictureBox15;
private: System::Windows::Forms::PictureBox^ pictureBox18;
private: System::Windows::Forms::PictureBox^ pictureBox19;

private: System::Windows::Forms::PictureBox^ pictureBox21;
private: System::Windows::Forms::PictureBox^ pictureBox22;
private: System::Windows::Forms::PictureBox^ pictureBox23;
private: System::Windows::Forms::PictureBox^ pictureBox27;

private: System::Windows::Forms::PictureBox^ pictureBox25;

private: System::Windows::Forms::PictureBox^ pictureBox29;



private: System::Windows::Forms::PictureBox^ pictureBox16;


private: System::Windows::Forms::PictureBox^ pictureBox30;
private: System::Windows::Forms::PictureBox^ pictureBox17;
private: System::Windows::Forms::PictureBox^ pictureBox33;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::PictureBox^ pictureBox34;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::TextBox^ OrderPage_NameTextBox;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::PictureBox^ pictureBox20;
private: System::Windows::Forms::PictureBox^ pictureBox24;
private: System::Windows::Forms::PictureBox^ pictureBox26;


















































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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EquipmentPriceCalculator::typeid));
			this->HomePage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->HomePage_ExitFromPageButton = (gcnew System::Windows::Forms::Button());
			this->HomePage_EquipmentButton = (gcnew System::Windows::Forms::Button());
			this->HomePage_Label = (gcnew System::Windows::Forms::Label());
			this->HomePage_DetailsButton = (gcnew System::Windows::Forms::Button());
			this->MainPage_UsersGuidButton = (gcnew System::Windows::Forms::Button());
			this->DetailsListPage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->EquipmentListPage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->EquipmentListPage_SearchInput = (gcnew System::Windows::Forms::TextBox());
			this->EquipmentListPage__AddingButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentListPage__SortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->EquipmentListPage_SortTypeMessage = (gcnew System::Windows::Forms::Label());
			this->EquipmentListPage_ExitButton = (gcnew System::Windows::Forms::Button());
			this->EquipmentListPage_Title = (gcnew System::Windows::Forms::Label());
			this->EquipmentListPage_DataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StartPage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->StartPage_CreateFileButton = (gcnew System::Windows::Forms::Button());
			this->StartPage_OpenFileButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MainTopMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->создатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_OpenFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTopMenu_SaveFileAsButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->окноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->главнаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->AddingEquipmentPage_ComponentsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_AddingEquipmentButton = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton = (gcnew System::Windows::Forms::Button());
			this->AddingEquipmentPage_ComponentsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_ComponentsListLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_ComponentsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListSortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AddingEquipmentPage_DetailsListSortTypeLabel = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_DetailsListSearchInput = (gcnew System::Windows::Forms::TextBox());
			this->AddingEquipmentPage_DetailsListDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AddingEquipmentPage_DetailsListLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AddingEquipmentPage_EquipmentNameInput = (gcnew System::Windows::Forms::TextBox());
			this->OrderPage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->OrderPage_TotalPrice = (gcnew System::Windows::Forms::Label());
			this->OrderPage_EquipmentDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->printUsersCheckInFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->MainPage = (gcnew System::Windows::Forms::Panel());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->OrderPage_NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->HomePage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			this->DetailsListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->EquipmentListPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->BeginInit();
			this->StartPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			this->MainTopMenu->SuspendLayout();
			this->AddingEquipmentPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_ComponentsListDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_DetailsListDataGrid))->BeginInit();
			this->OrderPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_EquipmentDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_OrderedEquipmentDataGrid))->BeginInit();
			this->MainPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
			this->SuspendLayout();
			// 
			// HomePage
			// 
			this->HomePage->AllowDrop = true;
			this->HomePage->Controls->Add(this->pictureBox30);
			this->HomePage->Controls->Add(this->pictureBox16);
			this->HomePage->Controls->Add(this->HomePage_ExitFromPageButton);
			this->HomePage->Controls->Add(this->HomePage_EquipmentButton);
			this->HomePage->Controls->Add(this->HomePage_Label);
			this->HomePage->Controls->Add(this->HomePage_DetailsButton);
			this->HomePage->Location = System::Drawing::Point(3, 27);
			this->HomePage->Name = L"HomePage";
			this->HomePage->Size = System::Drawing::Size(1102, 538);
			this->HomePage->TabIndex = 1;
			// 
			// pictureBox30
			// 
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(570, 250);
			this->pictureBox30->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(38, 41);
			this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox30->TabIndex = 17;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowEquipmentListPage);
			// 
			// pictureBox16
			// 
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(333, 250);
			this->pictureBox16->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(40, 41);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox16->TabIndex = 16;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsListPage);
			// 
			// HomePage_ExitFromPageButton
			// 
			this->HomePage_ExitFromPageButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HomePage_ExitFromPageButton->BackColor = System::Drawing::Color::DarkRed;
			this->HomePage_ExitFromPageButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HomePage_ExitFromPageButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->HomePage_ExitFromPageButton->FlatAppearance->BorderSize = 2;
			this->HomePage_ExitFromPageButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HomePage_ExitFromPageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_ExitFromPageButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->HomePage_ExitFromPageButton->Location = System::Drawing::Point(296, 378);
			this->HomePage_ExitFromPageButton->Name = L"HomePage_ExitFromPageButton";
			this->HomePage_ExitFromPageButton->Size = System::Drawing::Size(523, 38);
			this->HomePage_ExitFromPageButton->TabIndex = 15;
			this->HomePage_ExitFromPageButton->Text = L"Назад";
			this->HomePage_ExitFromPageButton->UseVisualStyleBackColor = false;
			this->HomePage_ExitFromPageButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowMainPage);
			// 
			// HomePage_EquipmentButton
			// 
			this->HomePage_EquipmentButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->HomePage_EquipmentButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_EquipmentButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HomePage_EquipmentButton->FlatAppearance->BorderSize = 2;
			this->HomePage_EquipmentButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HomePage_EquipmentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->HomePage_EquipmentButton->Location = System::Drawing::Point(562, 217);
			this->HomePage_EquipmentButton->Name = L"HomePage_EquipmentButton";
			this->HomePage_EquipmentButton->Size = System::Drawing::Size(257, 105);
			this->HomePage_EquipmentButton->TabIndex = 7;
			this->HomePage_EquipmentButton->Text = L"Оборудование";
			this->HomePage_EquipmentButton->UseVisualStyleBackColor = false;
			this->HomePage_EquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowEquipmentListPage);
			// 
			// HomePage_Label
			// 
			this->HomePage_Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->HomePage_Label->AutoSize = true;
			this->HomePage_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->HomePage_Label->Location = System::Drawing::Point(302, 145);
			this->HomePage_Label->Name = L"HomePage_Label";
			this->HomePage_Label->Size = System::Drawing::Size(520, 51);
			this->HomePage_Label->TabIndex = 6;
			this->HomePage_Label->Text = L"Режим редактирования";
			this->HomePage_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePage_DetailsButton
			// 
			this->HomePage_DetailsButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->HomePage_DetailsButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HomePage_DetailsButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HomePage_DetailsButton->FlatAppearance->BorderSize = 2;
			this->HomePage_DetailsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HomePage_DetailsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->HomePage_DetailsButton->Location = System::Drawing::Point(296, 217);
			this->HomePage_DetailsButton->Name = L"HomePage_DetailsButton";
			this->HomePage_DetailsButton->Size = System::Drawing::Size(253, 105);
			this->HomePage_DetailsButton->TabIndex = 5;
			this->HomePage_DetailsButton->Text = L"Детали";
			this->HomePage_DetailsButton->UseVisualStyleBackColor = false;
			this->HomePage_DetailsButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowDetailsListPage);
			// 
			// MainPage_UsersGuidButton
			// 
			this->MainPage_UsersGuidButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->MainPage_UsersGuidButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->MainPage_UsersGuidButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MainPage_UsersGuidButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->MainPage_UsersGuidButton->FlatAppearance->BorderSize = 2;
			this->MainPage_UsersGuidButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_UsersGuidButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold));
			this->MainPage_UsersGuidButton->Location = System::Drawing::Point(296, 422);
			this->MainPage_UsersGuidButton->Name = L"MainPage_UsersGuidButton";
			this->MainPage_UsersGuidButton->Size = System::Drawing::Size(489, 44);
			this->MainPage_UsersGuidButton->TabIndex = 8;
			this->MainPage_UsersGuidButton->Text = L"Руководство пользователя";
			this->MainPage_UsersGuidButton->UseVisualStyleBackColor = false;
			this->MainPage_UsersGuidButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowGuidOnClick);
			// 
			// DetailsListPage
			// 
			this->DetailsListPage->Controls->Add(this->pictureBox14);
			this->DetailsListPage->Controls->Add(this->pictureBox13);
			this->DetailsListPage->Controls->Add(this->label7);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SearchInput);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_AddingButton);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SortTypeComboBox);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_SortTypeMessage);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_ExitButton);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_Title);
			this->DetailsListPage->Controls->Add(this->DetailsListPage_DataGrid);
			this->DetailsListPage->Controls->Add(this->pictureBox15);
			this->DetailsListPage->Controls->Add(this->pictureBox4);
			this->DetailsListPage->Location = System::Drawing::Point(3, 26);
			this->DetailsListPage->Name = L"DetailsListPage";
			this->DetailsListPage->Size = System::Drawing::Size(1102, 539);
			this->DetailsListPage->TabIndex = 15;
			this->DetailsListPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_DetailsListPage);
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(410, 66);
			this->pictureBox14->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(68, 32);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox14->TabIndex = 22;
			this->pictureBox14->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(1032, 405);
			this->pictureBox13->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(56, 61);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox13->TabIndex = 21;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsAddingWindow);
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(16, 66);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 31);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Поиск:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DetailsListPage_SearchInput
			// 
			this->DetailsListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_SearchInput->Location = System::Drawing::Point(114, 67);
			this->DetailsListPage_SearchInput->Margin = System::Windows::Forms::Padding(2);
			this->DetailsListPage_SearchInput->Name = L"DetailsListPage_SearchInput";
			this->DetailsListPage_SearchInput->Size = System::Drawing::Size(364, 32);
			this->DetailsListPage_SearchInput->TabIndex = 18;
			this->DetailsListPage_SearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_SearchInput_TextChanged);
			// 
			// DetailsListPage_AddingButton
			// 
			this->DetailsListPage_AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->DetailsListPage_AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsListPage_AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->DetailsListPage_AddingButton->Location = System::Drawing::Point(865, 401);
			this->DetailsListPage_AddingButton->Name = L"DetailsListPage_AddingButton";
			this->DetailsListPage_AddingButton->Size = System::Drawing::Size(228, 69);
			this->DetailsListPage_AddingButton->TabIndex = 17;
			this->DetailsListPage_AddingButton->Text = L"Добавить";
			this->DetailsListPage_AddingButton->UseVisualStyleBackColor = false;
			this->DetailsListPage_AddingButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsAddingWindow);
			// 
			// DetailsListPage_SortTypeComboBox
			// 
			this->DetailsListPage_SortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->DetailsListPage_SortTypeComboBox->FormattingEnabled = true;
			this->DetailsListPage_SortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали", L"Названию детали",
					L"Стоимости детали"
			});
			this->DetailsListPage_SortTypeComboBox->Location = System::Drawing::Point(866, 144);
			this->DetailsListPage_SortTypeComboBox->Name = L"DetailsListPage_SortTypeComboBox";
			this->DetailsListPage_SortTypeComboBox->Size = System::Drawing::Size(228, 32);
			this->DetailsListPage_SortTypeComboBox->TabIndex = 16;
			this->DetailsListPage_SortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onSelectDetailsListSortType);
			// 
			// DetailsListPage_SortTypeMessage
			// 
			this->DetailsListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_SortTypeMessage->AutoSize = true;
			this->DetailsListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsListPage_SortTypeMessage->Location = System::Drawing::Point(892, 108);
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
			this->DetailsListPage_ExitButton->Location = System::Drawing::Point(865, 477);
			this->DetailsListPage_ExitButton->Name = L"DetailsListPage_ExitButton";
			this->DetailsListPage_ExitButton->Size = System::Drawing::Size(228, 38);
			this->DetailsListPage_ExitButton->TabIndex = 14;
			this->DetailsListPage_ExitButton->Text = L"Назад";
			this->DetailsListPage_ExitButton->UseVisualStyleBackColor = false;
			this->DetailsListPage_ExitButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::goBackToMainMenuFromDetailsList);
			// 
			// DetailsListPage_Title
			// 
			this->DetailsListPage_Title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsListPage_Title->AutoSize = true;
			this->DetailsListPage_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsListPage_Title->Location = System::Drawing::Point(15, 10);
			this->DetailsListPage_Title->Name = L"DetailsListPage_Title";
			this->DetailsListPage_Title->Size = System::Drawing::Size(316, 44);
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
			this->DetailsListPage_DataGrid->Size = System::Drawing::Size(825, 407);
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
			this->DetailId->Width = 125;
			// 
			// DetailName
			// 
			this->DetailName->Frozen = true;
			this->DetailName->HeaderText = L"Название детали";
			this->DetailName->MinimumWidth = 6;
			this->DetailName->Name = L"DetailName";
			this->DetailName->Width = 750;
			// 
			// DetailPrice
			// 
			this->DetailPrice->Frozen = true;
			this->DetailPrice->HeaderText = L"Стоимость детали, р/шт";
			this->DetailPrice->MinimumWidth = 6;
			this->DetailPrice->Name = L"DetailPrice";
			this->DetailPrice->Width = 150;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(868, 216);
			this->pictureBox15->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(227, 160);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox15->TabIndex = 23;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(708, 56);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(227, 169);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 20;
			this->pictureBox4->TabStop = false;
			// 
			// EquipmentListPage
			// 
			this->EquipmentListPage->Controls->Add(this->pictureBox34);
			this->EquipmentListPage->Controls->Add(this->pictureBox17);
			this->EquipmentListPage->Controls->Add(this->pictureBox33);
			this->EquipmentListPage->Controls->Add(this->label8);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_SearchInput);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage__AddingButton);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage__SortTypeComboBox);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_SortTypeMessage);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_ExitButton);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_Title);
			this->EquipmentListPage->Controls->Add(this->EquipmentListPage_DataGrid);
			this->EquipmentListPage->Location = System::Drawing::Point(0, 26);
			this->EquipmentListPage->Name = L"EquipmentListPage";
			this->EquipmentListPage->Size = System::Drawing::Size(1102, 541);
			this->EquipmentListPage->TabIndex = 19;
			this->EquipmentListPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_EquipmentListPage);
			// 
			// pictureBox34
			// 
			this->pictureBox34->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(872, 216);
			this->pictureBox34->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(181, 158);
			this->pictureBox34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox34->TabIndex = 26;
			this->pictureBox34->TabStop = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(403, 70);
			this->pictureBox17->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(68, 32);
			this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox17->TabIndex = 25;
			this->pictureBox17->TabStop = false;
			// 
			// pictureBox33
			// 
			this->pictureBox33->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.Image")));
			this->pictureBox33->Location = System::Drawing::Point(1017, 406);
			this->pictureBox33->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(56, 61);
			this->pictureBox33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox33->TabIndex = 24;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowAddingEquipmentListPage);
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 71);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(100, 31);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Поиск:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// EquipmentListPage_SearchInput
			// 
			this->EquipmentListPage_SearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->EquipmentListPage_SearchInput->Location = System::Drawing::Point(110, 70);
			this->EquipmentListPage_SearchInput->Margin = System::Windows::Forms::Padding(2);
			this->EquipmentListPage_SearchInput->Name = L"EquipmentListPage_SearchInput";
			this->EquipmentListPage_SearchInput->Size = System::Drawing::Size(364, 35);
			this->EquipmentListPage_SearchInput->TabIndex = 18;
			this->EquipmentListPage_SearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::EquipmentListPage_SearchInput_TextChanged);
			// 
			// EquipmentListPage__AddingButton
			// 
			this->EquipmentListPage__AddingButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage__AddingButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->EquipmentListPage__AddingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->EquipmentListPage__AddingButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->EquipmentListPage__AddingButton->Location = System::Drawing::Point(851, 399);
			this->EquipmentListPage__AddingButton->Name = L"EquipmentListPage__AddingButton";
			this->EquipmentListPage__AddingButton->Size = System::Drawing::Size(226, 73);
			this->EquipmentListPage__AddingButton->TabIndex = 17;
			this->EquipmentListPage__AddingButton->Text = L"Добавить";
			this->EquipmentListPage__AddingButton->UseVisualStyleBackColor = false;
			this->EquipmentListPage__AddingButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowAddingEquipmentListPage);
			// 
			// EquipmentListPage__SortTypeComboBox
			// 
			this->EquipmentListPage__SortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->EquipmentListPage__SortTypeComboBox->FormattingEnabled = true;
			this->EquipmentListPage__SortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id оборудования", L"Названию оборудования",
					L"Стоимости оборудования"
			});
			this->EquipmentListPage__SortTypeComboBox->Location = System::Drawing::Point(875, 157);
			this->EquipmentListPage__SortTypeComboBox->Name = L"EquipmentListPage__SortTypeComboBox";
			this->EquipmentListPage__SortTypeComboBox->Size = System::Drawing::Size(178, 33);
			this->EquipmentListPage__SortTypeComboBox->TabIndex = 16;
			this->EquipmentListPage__SortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onSelectEquipmentsListSortType);
			// 
			// EquipmentListPage_SortTypeMessage
			// 
			this->EquipmentListPage_SortTypeMessage->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EquipmentListPage_SortTypeMessage->AutoSize = true;
			this->EquipmentListPage_SortTypeMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->EquipmentListPage_SortTypeMessage->Location = System::Drawing::Point(871, 124);
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
			this->EquipmentListPage_ExitButton->Location = System::Drawing::Point(851, 477);
			this->EquipmentListPage_ExitButton->Name = L"EquipmentListPage_ExitButton";
			this->EquipmentListPage_ExitButton->Size = System::Drawing::Size(226, 38);
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
			this->EquipmentListPage_Title->Location = System::Drawing::Point(11, 21);
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
			this->EquipmentListPage_DataGrid->Location = System::Drawing::Point(16, 124);
			this->EquipmentListPage_DataGrid->Name = L"EquipmentListPage_DataGrid";
			this->EquipmentListPage_DataGrid->RowHeadersWidth = 51;
			this->EquipmentListPage_DataGrid->Size = System::Drawing::Size(826, 391);
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
			this->dataGridViewTextBoxColumn1->Width = 70;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Frozen = true;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Название Оборудования";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 190;
			// 
			// StartPage
			// 
			this->StartPage->AllowDrop = true;
			this->StartPage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->StartPage->Controls->Add(this->pictureBox29);
			this->StartPage->Controls->Add(this->pictureBox27);
			this->StartPage->Controls->Add(this->pictureBox25);
			this->StartPage->Controls->Add(this->StartPage_CreateFileButton);
			this->StartPage->Controls->Add(this->StartPage_OpenFileButton);
			this->StartPage->Controls->Add(this->button1);
			this->StartPage->Controls->Add(this->label1);
			this->StartPage->Location = System::Drawing::Point(3, 27);
			this->StartPage->Name = L"StartPage";
			this->StartPage->Size = System::Drawing::Size(1102, 541);
			this->StartPage->TabIndex = 10;
			// 
			// pictureBox29
			// 
			this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.Image")));
			this->pictureBox29->Location = System::Drawing::Point(216, 408);
			this->pictureBox29->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(75, 69);
			this->pictureBox29->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox29->TabIndex = 16;
			this->pictureBox29->TabStop = false;
			this->pictureBox29->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowGuidOnClick);
			// 
			// pictureBox27
			// 
			this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.Image")));
			this->pictureBox27->Location = System::Drawing::Point(218, 271);
			this->pictureBox27->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(75, 69);
			this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox27->TabIndex = 14;
			this->pictureBox27->TabStop = false;
			this->pictureBox27->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::StartPage_OpenFileButton_Click);
			// 
			// pictureBox25
			// 
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(218, 201);
			this->pictureBox25->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(75, 58);
			this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox25->TabIndex = 12;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::StartPage_CreateFileButton_Click);
			// 
			// StartPage_CreateFileButton
			// 
			this->StartPage_CreateFileButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->StartPage_CreateFileButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->StartPage_CreateFileButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StartPage_CreateFileButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->StartPage_CreateFileButton->FlatAppearance->BorderSize = 2;
			this->StartPage_CreateFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StartPage_CreateFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->StartPage_CreateFileButton->Location = System::Drawing::Point(186, 199);
			this->StartPage_CreateFileButton->Name = L"StartPage_CreateFileButton";
			this->StartPage_CreateFileButton->Size = System::Drawing::Size(736, 63);
			this->StartPage_CreateFileButton->TabIndex = 9;
			this->StartPage_CreateFileButton->Text = L"Создать новый";
			this->StartPage_CreateFileButton->UseVisualStyleBackColor = false;
			this->StartPage_CreateFileButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::StartPage_CreateFileButton_Click);
			// 
			// StartPage_OpenFileButton
			// 
			this->StartPage_OpenFileButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->StartPage_OpenFileButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->StartPage_OpenFileButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StartPage_OpenFileButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->StartPage_OpenFileButton->FlatAppearance->BorderSize = 2;
			this->StartPage_OpenFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StartPage_OpenFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->StartPage_OpenFileButton->Location = System::Drawing::Point(186, 268);
			this->StartPage_OpenFileButton->Name = L"StartPage_OpenFileButton";
			this->StartPage_OpenFileButton->Size = System::Drawing::Size(736, 75);
			this->StartPage_OpenFileButton->TabIndex = 10;
			this->StartPage_OpenFileButton->Text = L"Открыть файл";
			this->StartPage_OpenFileButton->UseVisualStyleBackColor = false;
			this->StartPage_OpenFileButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::StartPage_OpenFileButton_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(186, 405);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(736, 76);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Руководство пользователя";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowGuidOnClick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
				static_cast<System::Int32>(static_cast<System::Byte>(121)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)));
			this->label1->Location = System::Drawing::Point(122, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(934, 51);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Калькулятор себестоимости оборудования";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->MainTopMenu->Size = System::Drawing::Size(1105, 24);
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
			this->создатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::MainTopMenu_CreateNewProjectButton);
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
			this->окноToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->главнаяToolStripMenuItem,
					this->деталиToolStripMenuItem, this->добавитьДеталиToolStripMenuItem, this->оборудованиеToolStripMenuItem, this->добавитьОборудованиеToolStripMenuItem,
					this->заказToolStripMenuItem
			});
			this->окноToolStripMenuItem->Name = L"окноToolStripMenuItem";
			this->окноToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->окноToolStripMenuItem->Text = L"Окно";
			// 
			// главнаяToolStripMenuItem
			// 
			this->главнаяToolStripMenuItem->Name = L"главнаяToolStripMenuItem";
			this->главнаяToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->главнаяToolStripMenuItem->Text = L"Главная";
			this->главнаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowMainPage);
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
			this->добавитьДеталиToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::DetailsListPage_DataGrid_OpeningDetailsAddingWindow);
			// 
			// оборудованиеToolStripMenuItem
			// 
			this->оборудованиеToolStripMenuItem->Name = L"оборудованиеToolStripMenuItem";
			this->оборудованиеToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->оборудованиеToolStripMenuItem->Text = L"Оборудование";
			this->оборудованиеToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowEquipmentListPage);
			// 
			// добавитьОборудованиеToolStripMenuItem
			// 
			this->добавитьОборудованиеToolStripMenuItem->Name = L"добавитьОборудованиеToolStripMenuItem";
			this->добавитьОборудованиеToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->добавитьОборудованиеToolStripMenuItem->Text = L"Добавить оборудование";
			this->добавитьОборудованиеToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowAddingEquipmentListPage);
			// 
			// заказToolStripMenuItem
			// 
			this->заказToolStripMenuItem->Name = L"заказToolStripMenuItem";
			this->заказToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->заказToolStripMenuItem->Text = L"Заказ";
			this->заказToolStripMenuItem->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowOrderPage);
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
			this->AddingEquipmentPage->BackColor = System::Drawing::SystemColors::Window;
			this->AddingEquipmentPage->Controls->Add(this->pictureBox1);
			this->AddingEquipmentPage->Controls->Add(this->pictureBox3);
			this->AddingEquipmentPage->Controls->Add(this->pictureBox2);
			this->AddingEquipmentPage->Controls->Add(this->groupBox2);
			this->AddingEquipmentPage->Controls->Add(this->groupBox1);
			this->AddingEquipmentPage->Controls->Add(this->label4);
			this->AddingEquipmentPage->Controls->Add(this->label3);
			this->AddingEquipmentPage->Controls->Add(this->AddingEquipmentPage_EquipmentNameInput);
			this->AddingEquipmentPage->Location = System::Drawing::Point(3, 27);
			this->AddingEquipmentPage->Name = L"AddingEquipmentPage";
			this->AddingEquipmentPage->Size = System::Drawing::Size(1102, 541);
			this->AddingEquipmentPage->TabIndex = 21;
			this->AddingEquipmentPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OnLoad_AddingEquipmentPage);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(897, 121);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(75, 80);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(956, 171);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(82, 93);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 31;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(838, 67);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(76, 90);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 30;
			this->pictureBox2->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox2->Controls->Add(this->pictureBox21);
			this->groupBox2->Controls->Add(this->pictureBox18);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->pictureBox19);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ComponentsListSortTypeLabel);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ComponemtsListSortTypeComboBox);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_AddingEquipmentButton);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ComponentsListSearchInput);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ComponentsListLabel);
			this->groupBox2->Controls->Add(this->AddingEquipmentPage_ComponentsListDataGrid);
			this->groupBox2->Controls->Add(this->pictureBox23);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->groupBox2->Location = System::Drawing::Point(11, 268);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(1082, 258);
			this->groupBox2->TabIndex = 28;
			this->groupBox2->TabStop = false;
			// 
			// pictureBox21
			// 
			this->pictureBox21->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.Image")));
			this->pictureBox21->Location = System::Drawing::Point(514, 32);
			this->pictureBox21->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(56, 30);
			this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox21->TabIndex = 33;
			this->pictureBox21->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(359, -244);
			this->pictureBox18->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(68, 32);
			this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox18->TabIndex = 33;
			this->pictureBox18->TabStop = false;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(5, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 26);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Поиск:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox19
			// 
			this->pictureBox19->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(1010, 154);
			this->pictureBox19->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(22, 44);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox19->TabIndex = 32;
			this->pictureBox19->TabStop = false;
			this->pictureBox19->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_AddingEquipmentButton_Click);
			// 
			// AddingEquipmentPage_ComponentsListSortTypeLabel
			// 
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->AutoSize = true;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Location = System::Drawing::Point(881, 67);
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Name = L"AddingEquipmentPage_ComponentsListSortTypeLabel";
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Size = System::Drawing::Size(176, 26);
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->TabIndex = 15;
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->Text = L"Сортировка по";
			this->AddingEquipmentPage_ComponentsListSortTypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_ComponemtsListSortTypeComboBox
			// 
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->FormattingEnabled = true;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Id компонента",
					L"Названию компонента", L"Стоимости компонента", L"Количеству компонетов", L"Полной стоимоти компонетов"
			});
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Location = System::Drawing::Point(886, 96);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Name = L"AddingEquipmentPage_ComponemtsListSortTypeComboBox";
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->Size = System::Drawing::Size(153, 32);
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->TabIndex = 16;
			this->AddingEquipmentPage_ComponemtsListSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponemtsListSortTypeComboBox_SelectedIndexChanged);
			// 
			// AddingEquipmentPage_AddingEquipmentButton
			// 
			this->AddingEquipmentPage_AddingEquipmentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_AddingEquipmentButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->AddingEquipmentPage_AddingEquipmentButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddingEquipmentPage_AddingEquipmentButton->FlatAppearance->BorderSize = 2;
			this->AddingEquipmentPage_AddingEquipmentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_AddingEquipmentButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->AddingEquipmentPage_AddingEquipmentButton->Location = System::Drawing::Point(886, 150);
			this->AddingEquipmentPage_AddingEquipmentButton->Name = L"AddingEquipmentPage_AddingEquipmentButton";
			this->AddingEquipmentPage_AddingEquipmentButton->Size = System::Drawing::Size(154, 52);
			this->AddingEquipmentPage_AddingEquipmentButton->TabIndex = 17;
			this->AddingEquipmentPage_AddingEquipmentButton->Text = L"Добавить";
			this->AddingEquipmentPage_AddingEquipmentButton->UseVisualStyleBackColor = false;
			this->AddingEquipmentPage_AddingEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_AddingEquipmentButton_Click);
			// 
			// AddingEquipmentPage_ExitfromAddingEquipmentPageButton
			// 
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->BackColor = System::Drawing::Color::DarkRed;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F,
				System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Location = System::Drawing::Point(886, 208);
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Name = L"AddingEquipmentPage_ExitfromAddingEquipmentPageButton";
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Size = System::Drawing::Size(154, 38);
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->TabIndex = 14;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Text = L"Назад";
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->UseVisualStyleBackColor = false;
			this->AddingEquipmentPage_ExitfromAddingEquipmentPageButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ExitfromAddingEquipmentPageButton_Click);
			// 
			// AddingEquipmentPage_ComponentsListSearchInput
			// 
			this->AddingEquipmentPage_ComponentsListSearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_ComponentsListSearchInput->Location = System::Drawing::Point(87, 32);
			this->AddingEquipmentPage_ComponentsListSearchInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_ComponentsListSearchInput->Name = L"AddingEquipmentPage_ComponentsListSearchInput";
			this->AddingEquipmentPage_ComponentsListSearchInput->Size = System::Drawing::Size(484, 32);
			this->AddingEquipmentPage_ComponentsListSearchInput->TabIndex = 18;
			this->AddingEquipmentPage_ComponentsListSearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_ComponentsListSearchInput_TextChanged);
			// 
			// AddingEquipmentPage_ComponentsListLabel
			// 
			this->AddingEquipmentPage_ComponentsListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_ComponentsListLabel->AutoSize = true;
			this->AddingEquipmentPage_ComponentsListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_ComponentsListLabel->Location = System::Drawing::Point(5, 1);
			this->AddingEquipmentPage_ComponentsListLabel->Name = L"AddingEquipmentPage_ComponentsListLabel";
			this->AddingEquipmentPage_ComponentsListLabel->Size = System::Drawing::Size(407, 26);
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
			this->AddingEquipmentPage_ComponentsListDataGrid->Location = System::Drawing::Point(5, 67);
			this->AddingEquipmentPage_ComponentsListDataGrid->Name = L"AddingEquipmentPage_ComponentsListDataGrid";
			this->AddingEquipmentPage_ComponentsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_ComponentsListDataGrid->Size = System::Drawing::Size(860, 179);
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
			this->Column4->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"+";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 50;
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
			this->dataGridViewTextBoxColumn5->Width = 300;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Требуемое количество деталей, шт.";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 200;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Стоимоть детали, р/шт";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Полная стоимоть деталей";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 220;
			// 
			// pictureBox23
			// 
			this->pictureBox23->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.Image")));
			this->pictureBox23->Location = System::Drawing::Point(813, 33);
			this->pictureBox23->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(111, 102);
			this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox23->TabIndex = 33;
			this->pictureBox23->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->pictureBox22);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeComboBox);
			this->groupBox1->Controls->Add(this->AddingEquipmentPage_DetailsListSortTypeLabel);
			this->groupBox1->Controls->Add(this->AddingEquipmentPage_DetailsListSearchInput);
			this->groupBox1->Controls->Add(this->AddingEquipmentPage_DetailsListDataGrid);
			this->groupBox1->Controls->Add(this->AddingEquipmentPage_DetailsListLabel);
			this->groupBox1->Location = System::Drawing::Point(11, 67);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(754, 196);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			// 
			// pictureBox22
			// 
			this->pictureBox22->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(514, 41);
			this->pictureBox22->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(56, 30);
			this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox22->TabIndex = 34;
			this->pictureBox22->TabStop = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(5, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(80, 26);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Поиск:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_DetailsListSortTypeComboBox
			// 
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->FormattingEnabled = true;
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id детали",
					L"Названию детали", L"Стоимости детали"
			});
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Location = System::Drawing::Point(586, 105);
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Name = L"AddingEquipmentPage_DetailsListSortTypeComboBox";
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->Size = System::Drawing::Size(153, 32);
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->TabIndex = 22;
			this->AddingEquipmentPage_DetailsListSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSortTypeComboBox_SelectedIndexChanged);
			// 
			// AddingEquipmentPage_DetailsListSortTypeLabel
			// 
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->AutoSize = true;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Location = System::Drawing::Point(581, 76);
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Name = L"AddingEquipmentPage_DetailsListSortTypeLabel";
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Size = System::Drawing::Size(176, 26);
			this->AddingEquipmentPage_DetailsListSortTypeLabel->TabIndex = 21;
			this->AddingEquipmentPage_DetailsListSortTypeLabel->Text = L"Сортировка по";
			this->AddingEquipmentPage_DetailsListSortTypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_DetailsListSearchInput
			// 
			this->AddingEquipmentPage_DetailsListSearchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_DetailsListSearchInput->Location = System::Drawing::Point(87, 41);
			this->AddingEquipmentPage_DetailsListSearchInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_DetailsListSearchInput->Name = L"AddingEquipmentPage_DetailsListSearchInput";
			this->AddingEquipmentPage_DetailsListSearchInput->Size = System::Drawing::Size(484, 32);
			this->AddingEquipmentPage_DetailsListSearchInput->TabIndex = 23;
			this->AddingEquipmentPage_DetailsListSearchInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_DetailsListSearchInput_TextChanged);
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
			this->AddingEquipmentPage_DetailsListDataGrid->Location = System::Drawing::Point(5, 76);
			this->AddingEquipmentPage_DetailsListDataGrid->Name = L"AddingEquipmentPage_DetailsListDataGrid";
			this->AddingEquipmentPage_DetailsListDataGrid->ReadOnly = true;
			this->AddingEquipmentPage_DetailsListDataGrid->RowHeadersWidth = 51;
			this->AddingEquipmentPage_DetailsListDataGrid->Size = System::Drawing::Size(565, 114);
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
			this->dataGridViewTextBoxColumn8->Width = 480;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->Frozen = true;
			this->dataGridViewTextBoxColumn9->HeaderText = L"Стоимость детали, р/шт";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->ReadOnly = true;
			this->dataGridViewTextBoxColumn9->Width = 150;
			// 
			// AddingEquipmentPage_DetailsListLabel
			// 
			this->AddingEquipmentPage_DetailsListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddingEquipmentPage_DetailsListLabel->AutoSize = true;
			this->AddingEquipmentPage_DetailsListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->AddingEquipmentPage_DetailsListLabel->Location = System::Drawing::Point(5, 12);
			this->AddingEquipmentPage_DetailsListLabel->Name = L"AddingEquipmentPage_DetailsListLabel";
			this->AddingEquipmentPage_DetailsListLabel->Size = System::Drawing::Size(269, 26);
			this->AddingEquipmentPage_DetailsListLabel->TabIndex = 20;
			this->AddingEquipmentPage_DetailsListLabel->Text = L"Общий список деталей";
			this->AddingEquipmentPage_DetailsListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(3, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(421, 29);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Введите навание оборудования:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label3->Location = System::Drawing::Point(666, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(436, 39);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Создание оборудования";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddingEquipmentPage_EquipmentNameInput
			// 
			this->AddingEquipmentPage_EquipmentNameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->AddingEquipmentPage_EquipmentNameInput->Location = System::Drawing::Point(421, 21);
			this->AddingEquipmentPage_EquipmentNameInput->Margin = System::Windows::Forms::Padding(2);
			this->AddingEquipmentPage_EquipmentNameInput->Name = L"AddingEquipmentPage_EquipmentNameInput";
			this->AddingEquipmentPage_EquipmentNameInput->Size = System::Drawing::Size(233, 32);
			this->AddingEquipmentPage_EquipmentNameInput->TabIndex = 24;
			this->AddingEquipmentPage_EquipmentNameInput->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::AddingEquipmentPage_EquipmentNameInput_TextChanged);
			// 
			// OrderPage
			// 
			this->OrderPage->Controls->Add(this->pictureBox20);
			this->OrderPage->Controls->Add(this->pictureBox10);
			this->OrderPage->Controls->Add(this->label12);
			this->OrderPage->Controls->Add(this->OrderPage_NameTextBox);
			this->OrderPage->Controls->Add(this->pictureBox8);
			this->OrderPage->Controls->Add(this->label11);
			this->OrderPage->Controls->Add(this->pictureBox6);
			this->OrderPage->Controls->Add(this->label10);
			this->OrderPage->Controls->Add(this->label9);
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
			this->OrderPage->Controls->Add(this->pictureBox24);
			this->OrderPage->Controls->Add(this->pictureBox26);
			this->OrderPage->Location = System::Drawing::Point(0, 26);
			this->OrderPage->Name = L"OrderPage";
			this->OrderPage->Size = System::Drawing::Size(1105, 542);
			this->OrderPage->TabIndex = 22;
			this->OrderPage->VisibleChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_VisibleChanged);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(403, 303);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(68, 32);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 30;
			this->pictureBox8->TabStop = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(6, 303);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(100, 31);
			this->label11->TabIndex = 29;
			this->label11->Text = L"Поиск:";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(403, 97);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(68, 32);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 28;
			this->pictureBox6->TabStop = false;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(6, 97);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 31);
			this->label10->TabIndex = 27;
			this->label10->Text = L"Поиск:";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(983, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(110, 37);
			this->label9->TabIndex = 26;
			this->label9->Text = L"Заказ";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_TotalPrice
			// 
			this->OrderPage_TotalPrice->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_TotalPrice->AutoSize = true;
			this->OrderPage_TotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_TotalPrice->Location = System::Drawing::Point(916, 401);
			this->OrderPage_TotalPrice->Name = L"OrderPage_TotalPrice";
			this->OrderPage_TotalPrice->Size = System::Drawing::Size(154, 31);
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
					this->dataGridViewTextBoxColumn10, this->Column5
			});
			this->OrderPage_EquipmentDataGrid->Location = System::Drawing::Point(11, 133);
			this->OrderPage_EquipmentDataGrid->Name = L"OrderPage_EquipmentDataGrid";
			this->OrderPage_EquipmentDataGrid->RowHeadersWidth = 51;
			this->OrderPage_EquipmentDataGrid->Size = System::Drawing::Size(884, 134);
			this->OrderPage_EquipmentDataGrid->TabIndex = 24;
			this->OrderPage_EquipmentDataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentGrid_MouseClick);
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
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->Frozen = true;
			this->dataGridViewTextBoxColumn10->HeaderText = L"Название Оборудования";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->ReadOnly = true;
			this->dataGridViewTextBoxColumn10->Width = 170;
			// 
			// Column5
			// 
			this->Column5->Frozen = true;
			this->Column5->HeaderText = L"Стоимость за штуку, р/шт";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 125;
			// 
			// OrderPage_EquipmentSearchTextBox
			// 
			this->OrderPage_EquipmentSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->OrderPage_EquipmentSearchTextBox->Location = System::Drawing::Point(107, 97);
			this->OrderPage_EquipmentSearchTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OrderPage_EquipmentSearchTextBox->Name = L"OrderPage_EquipmentSearchTextBox";
			this->OrderPage_EquipmentSearchTextBox->Size = System::Drawing::Size(364, 32);
			this->OrderPage_EquipmentSearchTextBox->TabIndex = 23;
			this->OrderPage_EquipmentSearchTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentSearchTextBox_TextChanged);
			// 
			// OrderPage_EquipmentSortTypeComboBox
			// 
			this->OrderPage_EquipmentSortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->OrderPage_EquipmentSortTypeComboBox->FormattingEnabled = true;
			this->OrderPage_EquipmentSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Id оборудования", L"Названию оборудования",
					L"Стоимости оборудования"
			});
			this->OrderPage_EquipmentSortTypeComboBox->Location = System::Drawing::Point(912, 124);
			this->OrderPage_EquipmentSortTypeComboBox->Name = L"OrderPage_EquipmentSortTypeComboBox";
			this->OrderPage_EquipmentSortTypeComboBox->Size = System::Drawing::Size(153, 32);
			this->OrderPage_EquipmentSortTypeComboBox->TabIndex = 22;
			this->OrderPage_EquipmentSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_EquipmentSortTypeComboBox_SelectedIndexChanged);
			// 
			// OrderPage_EquipmentSortTypeTitle
			// 
			this->OrderPage_EquipmentSortTypeTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_EquipmentSortTypeTitle->AutoSize = true;
			this->OrderPage_EquipmentSortTypeTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_EquipmentSortTypeTitle->Location = System::Drawing::Point(909, 101);
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
			this->OrderPage_WholeEquipmentListLabel->Location = System::Drawing::Point(7, 69);
			this->OrderPage_WholeEquipmentListLabel->Name = L"OrderPage_WholeEquipmentListLabel";
			this->OrderPage_WholeEquipmentListLabel->Size = System::Drawing::Size(378, 29);
			this->OrderPage_WholeEquipmentListLabel->TabIndex = 20;
			this->OrderPage_WholeEquipmentListLabel->Text = L"Общий список оборудования";
			this->OrderPage_WholeEquipmentListLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_OrderedEquipmentSearchTextBox
			// 
			this->OrderPage_OrderedEquipmentSearchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->OrderPage_OrderedEquipmentSearchTextBox->Location = System::Drawing::Point(107, 302);
			this->OrderPage_OrderedEquipmentSearchTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OrderPage_OrderedEquipmentSearchTextBox->Name = L"OrderPage_OrderedEquipmentSearchTextBox";
			this->OrderPage_OrderedEquipmentSearchTextBox->Size = System::Drawing::Size(364, 32);
			this->OrderPage_OrderedEquipmentSearchTextBox->TabIndex = 18;
			this->OrderPage_OrderedEquipmentSearchTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentSearchTextBox_TextChanged);
			// 
			// OrderPage_MakeOrderButton
			// 
			this->OrderPage_MakeOrderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_MakeOrderButton->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->OrderPage_MakeOrderButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->OrderPage_MakeOrderButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->OrderPage_MakeOrderButton->Location = System::Drawing::Point(912, 430);
			this->OrderPage_MakeOrderButton->Name = L"OrderPage_MakeOrderButton";
			this->OrderPage_MakeOrderButton->Size = System::Drawing::Size(161, 52);
			this->OrderPage_MakeOrderButton->TabIndex = 17;
			this->OrderPage_MakeOrderButton->Text = L"Заказать";
			this->OrderPage_MakeOrderButton->UseVisualStyleBackColor = false;
			this->OrderPage_MakeOrderButton->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_MakeOrderButton_Click);
			// 
			// OrderPage_OrderedEquipmentSortTypeComboBox
			// 
			this->OrderPage_OrderedEquipmentSortTypeComboBox->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->OrderPage_OrderedEquipmentSortTypeComboBox->FormattingEnabled = true;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Id оборудования",
					L"Названию оборудования", L"Стоимости одного оборудования", L"Количеству заказанного оборудования", L"Полной стоимоти оборудования"
			});
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Location = System::Drawing::Point(912, 361);
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Name = L"OrderPage_OrderedEquipmentSortTypeComboBox";
			this->OrderPage_OrderedEquipmentSortTypeComboBox->Size = System::Drawing::Size(161, 32);
			this->OrderPage_OrderedEquipmentSortTypeComboBox->TabIndex = 16;
			this->OrderPage_OrderedEquipmentSortTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged);
			// 
			// OrderPage_OrderedEquipmentSortTypeTitle
			// 
			this->OrderPage_OrderedEquipmentSortTypeTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_OrderedEquipmentSortTypeTitle->AutoSize = true;
			this->OrderPage_OrderedEquipmentSortTypeTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_OrderedEquipmentSortTypeTitle->Location = System::Drawing::Point(915, 336);
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
			this->OrderPage_GoToMainMenuButton->Location = System::Drawing::Point(912, 484);
			this->OrderPage_GoToMainMenuButton->Name = L"OrderPage_GoToMainMenuButton";
			this->OrderPage_GoToMainMenuButton->Size = System::Drawing::Size(161, 38);
			this->OrderPage_GoToMainMenuButton->TabIndex = 14;
			this->OrderPage_GoToMainMenuButton->Text = L"Назад";
			this->OrderPage_GoToMainMenuButton->UseVisualStyleBackColor = false;
			// 
			// OrderPage_OrderedEquipmentListLabel
			// 
			this->OrderPage_OrderedEquipmentListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrderPage_OrderedEquipmentListLabel->AutoSize = true;
			this->OrderPage_OrderedEquipmentListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->OrderPage_OrderedEquipmentListLabel->Location = System::Drawing::Point(7, 274);
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
			this->OrderPage_OrderedEquipmentDataGrid->Location = System::Drawing::Point(12, 337);
			this->OrderPage_OrderedEquipmentDataGrid->Name = L"OrderPage_OrderedEquipmentDataGrid";
			this->OrderPage_OrderedEquipmentDataGrid->RowHeadersWidth = 51;
			this->OrderPage_OrderedEquipmentDataGrid->Size = System::Drawing::Size(884, 185);
			this->OrderPage_OrderedEquipmentDataGrid->TabIndex = 0;
			this->OrderPage_OrderedEquipmentDataGrid->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_CellBeginEdit);
			this->OrderPage_OrderedEquipmentDataGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_CellContentClick);
			this->OrderPage_OrderedEquipmentDataGrid->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EquipmentPriceCalculator::OrderPage_OrderedEquipmentDataGrid_MouseClick);
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
			// MainPage
			// 
			this->MainPage->Controls->Add(this->pictureBox11);
			this->MainPage->Controls->Add(this->pictureBox9);
			this->MainPage->Controls->Add(this->pictureBox7);
			this->MainPage->Controls->Add(this->MainPage_UsersGuidButton);
			this->MainPage->Controls->Add(this->button2);
			this->MainPage->Controls->Add(this->label2);
			this->MainPage->Controls->Add(this->button3);
			this->MainPage->Controls->Add(this->pictureBox5);
			this->MainPage->Controls->Add(this->pictureBox12);
			this->MainPage->Location = System::Drawing::Point(3, 27);
			this->MainPage->Name = L"MainPage";
			this->MainPage->Size = System::Drawing::Size(1102, 540);
			this->MainPage->TabIndex = 9;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(322, 219);
			this->pictureBox11->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(40, 48);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox11->TabIndex = 16;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowHomePage);
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(322, 313);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(40, 48);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 14;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowOrderPage);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(327, 429);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(28, 32);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 12;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowGuidOnClick);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->BorderSize = 2;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(296, 296);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(486, 78);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Сделать заказ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowOrderPage);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->label2->Location = System::Drawing::Point(130, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(934, 51);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Калькулятор себестоимости оборудования";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->BorderSize = 2;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->button3->Location = System::Drawing::Point(296, 199);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(486, 90);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Редактировать";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &EquipmentPriceCalculator::ShowHomePage);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(942, 79);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(107, 92);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 10;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(152, 84);
			this->pictureBox12->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(127, 128);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox12->TabIndex = 17;
			this->pictureBox12->TabStop = false;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(9, 21);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(248, 31);
			this->label12->TabIndex = 32;
			this->label12->Text = L"Введите свое имя:";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OrderPage_NameTextBox
			// 
			this->OrderPage_NameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->OrderPage_NameTextBox->Location = System::Drawing::Point(262, 23);
			this->OrderPage_NameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OrderPage_NameTextBox->Name = L"OrderPage_NameTextBox";
			this->OrderPage_NameTextBox->Size = System::Drawing::Size(364, 32);
			this->OrderPage_NameTextBox->TabIndex = 31;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(912, 163);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(155, 105);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 33;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(924, 10);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(53, 37);
			this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox20->TabIndex = 34;
			this->pictureBox20->TabStop = false;
			// 
			// pictureBox24
			// 
			this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.Image")));
			this->pictureBox24->Location = System::Drawing::Point(809, 299);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(155, 105);
			this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox24->TabIndex = 35;
			this->pictureBox24->TabStop = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(799, 85);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(155, 105);
			this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox26->TabIndex = 36;
			this->pictureBox26->TabStop = false;
			// 
			// EquipmentPriceCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1105, 557);
			this->Controls->Add(this->MainTopMenu);
			this->Controls->Add(this->OrderPage);
			this->Controls->Add(this->HomePage);
			this->Controls->Add(this->MainPage);
			this->Controls->Add(this->EquipmentListPage);
			this->Controls->Add(this->DetailsListPage);
			this->Controls->Add(this->AddingEquipmentPage);
			this->Controls->Add(this->StartPage);
			this->MainMenuStrip = this->MainTopMenu;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EquipmentPriceCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EquipmentPriceCalculator";
			this->Load += gcnew System::EventHandler(this, &EquipmentPriceCalculator::onAppLoad);
			this->HomePage->ResumeLayout(false);
			this->HomePage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			this->DetailsListPage->ResumeLayout(false);
			this->DetailsListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DetailsListPage_DataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->EquipmentListPage->ResumeLayout(false);
			this->EquipmentListPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EquipmentListPage_DataGrid))->EndInit();
			this->StartPage->ResumeLayout(false);
			this->StartPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			this->MainTopMenu->ResumeLayout(false);
			this->MainTopMenu->PerformLayout();
			this->AddingEquipmentPage->ResumeLayout(false);
			this->AddingEquipmentPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_ComponentsListDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddingEquipmentPage_DetailsListDataGrid))->EndInit();
			this->OrderPage->ResumeLayout(false);
			this->OrderPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_EquipmentDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrderPage_OrderedEquipmentDataGrid))->EndInit();
			this->MainPage->ResumeLayout(false);
			this->MainPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
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
	private: System::Void onAppLoad(System::Object^ sender, System::EventArgs^ e) {
	};

	private: void OnKeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->Control && e->KeyCode == Keys::S) {
			this->GlobalStorage.SaveAllInFile();
		}
	}
	private: void SelectRow(DataGridView^ dataGridView, int rowIndex) {
		if (rowIndex >= 0 && rowIndex < dataGridView->Rows->Count) {
			dataGridView->ClearSelection();
			dataGridView->Rows[rowIndex]->Selected = true;
			dataGridView->CurrentCell = dataGridView->Rows[rowIndex]->Cells[0];
		}
	}
		   //StartPage 
	private: System::Void StartPage_OpenFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenExtraFileDialog();
		HideStartPage();
	}

	private: System::Void StartPage_CreateFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		HideStartPage();
	}
		   //MainTopMenu

	private: System::Void OpenExtraFileDialog();
	private: System::Void MainTopMenu_CreateNewProjectButton(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateNewProject(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainTopMenu_OpenExtraFileDialog(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainTopMenu_SaveFile(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainTopMenu_SaveFileAs(System::Object^ sender, System::EventArgs^ e);

		   //MainPage
	private: System::Void ShowGuidOnClick(System::Object^ sender, System::EventArgs^ e);

		   //PagesManipulations
	private: System::Void HideStartPage();
	private: System::Void ShowMainPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowHomePage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowEquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowAddingEquipmentListPage(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShowOrderPage(System::Object^ sender, System::EventArgs^ e);
		   

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
	private: System::Void OrderPage_CalculateTotalOrdersPrice();
	private: System::Void OrderPage_ShowEquipmentListInOrderedEquipmentGrid();
	private: System::Void OrderPage_OrderedEquipmentSearchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentSortTypeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

	String^ ValueBeforeEdit_OrderPage_OrderedEquipment_DataGrid;
	private: System::Void OrderPage_OrderedEquipmentGrid_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentDataGrid_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentDataGrid_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentDataGrid_RemovingEquipmentFromOrderContextMenu_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void removeEquipmentsFromOrder_onClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrderPage_OrderedEquipmentDataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void OrderPage_MakeOrderButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
