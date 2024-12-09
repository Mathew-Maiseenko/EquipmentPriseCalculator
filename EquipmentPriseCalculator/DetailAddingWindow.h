#pragma once
#include <msclr/marshal.h>
#include <cctype>
#include "GlobalList.h"
using namespace System;
using namespace System::Windows::Forms;

public ref class GivingNewDetailsInfoEventArgs : System::EventArgs
{
public:
	GivingNewDetailsInfoEventArgs(String^ name, double cost)
		: m_name(name), m_cost(cost)
	{
	}

	property String^ Name
	{
		String^ get()
		{
			return m_name;
		}
	}

	property double Cost
	{
		double get()
		{
			return m_cost;
		}
	}

private:
	String^ m_name;
	double m_cost;
};


namespace EquipmentPriseCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DetailAddingWindow
	/// </summary>
	public ref class DetailAddingWindow : public System::Windows::Forms::Form
	{


	public:
		delegate System::Void GivingNewDetailsInfo(Object^ sender, GivingNewDetailsInfoEventArgs^ e);
		event System::EventHandler<GivingNewDetailsInfoEventArgs^>^ GivingNewDetailsInfoEvent;


		DetailAddingWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DetailAddingWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ DetailsAddingWindow_NameLabel;
	private: System::Windows::Forms::TextBox^ DetailsAddingWindow_NameInput;
	protected:

	protected:

	private: System::Windows::Forms::Label^ DetailsAddingWindow_MainTitle;
	private: System::Windows::Forms::TextBox^ DetailsAddingWindow_CostInput;
	private: System::Windows::Forms::Label^ DetailsAddingWindow_CostLabel;
	private: System::Windows::Forms::Button^ DetailsAddingWindow_ApplingAddingDetailsButton;





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
			this->DetailsAddingWindow_NameLabel = (gcnew System::Windows::Forms::Label());
			this->DetailsAddingWindow_NameInput = (gcnew System::Windows::Forms::TextBox());
			this->DetailsAddingWindow_MainTitle = (gcnew System::Windows::Forms::Label());
			this->DetailsAddingWindow_CostInput = (gcnew System::Windows::Forms::TextBox());
			this->DetailsAddingWindow_CostLabel = (gcnew System::Windows::Forms::Label());
			this->DetailsAddingWindow_ApplingAddingDetailsButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DetailsAddingWindow_NameLabel
			// 
			this->DetailsAddingWindow_NameLabel->AutoSize = true;
			this->DetailsAddingWindow_NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->DetailsAddingWindow_NameLabel->Location = System::Drawing::Point(37, 70);
			this->DetailsAddingWindow_NameLabel->Name = L"DetailsAddingWindow_NameLabel";
			this->DetailsAddingWindow_NameLabel->Size = System::Drawing::Size(215, 29);
			this->DetailsAddingWindow_NameLabel->TabIndex = 0;
			this->DetailsAddingWindow_NameLabel->Text = L"Название детали";
			// 
			// DetailsAddingWindow_NameInput
			// 
			this->DetailsAddingWindow_NameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->DetailsAddingWindow_NameInput->Location = System::Drawing::Point(42, 102);
			this->DetailsAddingWindow_NameInput->Name = L"DetailsAddingWindow_NameInput";
			this->DetailsAddingWindow_NameInput->Size = System::Drawing::Size(180, 33);
			this->DetailsAddingWindow_NameInput->TabIndex = 1;
			// 
			// DetailsAddingWindow_MainTitle
			// 
			this->DetailsAddingWindow_MainTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsAddingWindow_MainTitle->AutoSize = true;
			this->DetailsAddingWindow_MainTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->DetailsAddingWindow_MainTitle->Location = System::Drawing::Point(85, 9);
			this->DetailsAddingWindow_MainTitle->Name = L"DetailsAddingWindow_MainTitle";
			this->DetailsAddingWindow_MainTitle->Size = System::Drawing::Size(358, 39);
			this->DetailsAddingWindow_MainTitle->TabIndex = 11;
			this->DetailsAddingWindow_MainTitle->Text = L"Добавление детали";
			this->DetailsAddingWindow_MainTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DetailsAddingWindow_CostInput
			// 
			this->DetailsAddingWindow_CostInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->DetailsAddingWindow_CostInput->Location = System::Drawing::Point(304, 102);
			this->DetailsAddingWindow_CostInput->Name = L"DetailsAddingWindow_CostInput";
			this->DetailsAddingWindow_CostInput->Size = System::Drawing::Size(180, 33);
			this->DetailsAddingWindow_CostInput->TabIndex = 13;
			// 
			// DetailsAddingWindow_CostLabel
			// 
			this->DetailsAddingWindow_CostLabel->AutoSize = true;
			this->DetailsAddingWindow_CostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->DetailsAddingWindow_CostLabel->Location = System::Drawing::Point(299, 70);
			this->DetailsAddingWindow_CostLabel->Name = L"DetailsAddingWindow_CostLabel";
			this->DetailsAddingWindow_CostLabel->Size = System::Drawing::Size(161, 29);
			this->DetailsAddingWindow_CostLabel->TabIndex = 12;
			this->DetailsAddingWindow_CostLabel->Text = L"Цена детали";
			// 
			// DetailsAddingWindow_ApplingAddingDetailsButton
			// 
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DetailsAddingWindow_ApplingAddingDetailsButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Location = System::Drawing::Point(131, 156);
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Name = L"DetailsAddingWindow_ApplingAddingDetailsButton";
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Size = System::Drawing::Size(240, 69);
			this->DetailsAddingWindow_ApplingAddingDetailsButton->TabIndex = 14;
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Text = L"Добавить деталь";
			this->DetailsAddingWindow_ApplingAddingDetailsButton->UseVisualStyleBackColor = false;
			this->DetailsAddingWindow_ApplingAddingDetailsButton->Click += gcnew System::EventHandler(this, &DetailAddingWindow::DetailsAddingWindow_ApplingAddingDetailsButton_Click);
			// 
			// DetailAddingWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(518, 237);
			this->Controls->Add(this->DetailsAddingWindow_ApplingAddingDetailsButton);
			this->Controls->Add(this->DetailsAddingWindow_CostInput);
			this->Controls->Add(this->DetailsAddingWindow_CostLabel);
			this->Controls->Add(this->DetailsAddingWindow_MainTitle);
			this->Controls->Add(this->DetailsAddingWindow_NameInput);
			this->Controls->Add(this->DetailsAddingWindow_NameLabel);
			this->Name = L"DetailAddingWindow";
			this->Text = L"DetailAddingWindow";
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

	double stringToDouble(const std::string& str) {
		std::stringstream ss(str);
		double value;
		ss >> value;
		return value;
	}

	// Преобразование double в std::string
	std::string doubleToString(double value) {
		std::stringstream ss;
		ss << value;
		return ss.str();
	}

	//String^ formatDouble(const std::string& str) {

	//	double valueDouble = stringToDouble(str);
	//	string value = doubleToString(valueDouble);

	//	std::ostringstream out;
	//	out << std::fixed << std::setprecision(15) << value; 

	//	std::string strOut = out.str();
	//	strOut.erase(strOut.find_last_not_of('0') + 1, std::string::npos);
	//	if (strOut.back() == '.') {
	//		strOut.pop_back();
	//	}

	//	return str;
	//}

	private: System::Void DetailsAddingWindow_ApplingAddingDetailsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ newDetailsName = this->DetailsAddingWindow_NameInput->Text;
		String^ newDetailsCost = this->DetailsAddingWindow_CostInput->Text;

		newDetailsName->Trim();
		newDetailsCost->Trim();

		bool isCorrect = true;
		msclr::interop::marshal_context context;

		const char* newDetailsNameChars = context.marshal_as<const char*>(newDetailsName);
		const char* newDetailsCostChars = context.marshal_as<const char*>(newDetailsCost);

		std::string newDetailsNameStr(newDetailsNameChars);
		std::string newDetailsCostStr(newDetailsCostChars);

		//awdMessageBox::Show(gcnew String(newDetailsCostStr.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));

		if (newDetailsCostStr.size() == 0) {
			isCorrect = false;
			string errorMessage = "Цена детали не может быть пуста!";
			MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
		}
		else if (newDetailsNameStr.size() == 0) {
			isCorrect = false;
			string errorMessage = "У детали должно быть имя!";
			MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
		}
		else if (!is_number(newDetailsCostStr))
		{
			isCorrect = false;
			string errorMessage = "Цена обязана быть числом!";
			MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
		}
		else if (stringToDouble(newDetailsCostStr) < 0 )
		{
			isCorrect = false;
			string errorMessage = "Цена не может быть отрицательной!";
			MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
		}
		else if (stringToDouble(newDetailsCostStr) == 0)
		{
			isCorrect = false;
			string errorMessage = "Цена не может быть нулевой!";
			MessageBox::Show(gcnew String(errorMessage.c_str()), "Error", static_cast<MessageBoxButtons>(MessageBoxButtons::OK), static_cast<MessageBoxIcon>(MessageBoxIcon::Error));
		}


		if (isCorrect)
		{

			double newDetailsCostDouble = stringToDouble(newDetailsCostStr);
			GivingNewDetailsInfoEventArgs^ args = gcnew GivingNewDetailsInfoEventArgs(newDetailsName, newDetailsCostDouble);
			System::EventArgs^ eventArgs = static_cast<System::EventArgs^>(args);
			GivingNewDetailsInfoEvent(this, args); // Используйте this вместо sender, так как sender обычно указывает на текущий объект
			this->Close();
		}
	} 
};
}
