#pragma once
#include "EquipmentPriceCalculator.h"

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowHomePage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Hide();
	HomePage->Show();
	DetailsListPage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Hide();
	DetailsListPage->Show();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowEquipmentListPage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Hide();
	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Show();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowAddingEquipmentListPage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Hide();
	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Show();
	OrderPage->Hide();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowOrderPage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Hide();
	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Show();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowMainPage(System::Object^ sender, System::EventArgs^ e)
{
	MainPage->Show();
	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();
	AboutProgramPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::HideStartPage()
{
	StartPage->Hide();	

	MainTopMenu->Show();
	MainPage->Show();

	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();
	AboutProgramPage->Hide();

	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowAboutProgramPage(System::Object^ sender, System::EventArgs^ e)
{
	StartPage->Hide();
	MainPage->Hide();

	DetailsListPage->Hide();
	HomePage->Hide();
	EquipmentListPage->Hide();
	AddingEquipmentPage->Hide();
	OrderPage->Hide();

	AboutProgramPage->Show();

	return System::Void();
	return System::Void();
}