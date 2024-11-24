#include "EquipmentPriceCalculator.h"
#include "HomePage.h"
#include "GlobalList.h"
#include "DetailsPage.h"
#include "DetailsListPage.h"
#include "EquipmentListPage.h"
#include "MainTopMenu.h"
#include "AddingEquipmentPage.h"
#include "OrderPage.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
	GlobalList globalStorage;

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	EquipmentPriseCalculator::EquipmentPriceCalculator^ App = gcnew EquipmentPriseCalculator::EquipmentPriceCalculator(globalStorage);
	Application::Run(App);
}