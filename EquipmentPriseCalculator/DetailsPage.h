#pragma once
#include "EquipmentPriceCalculator.h"

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::GoBackFromDetailsPageToHomePage(System::Object^ sender, System::EventArgs^ e)
{
	HomePage->Show();
	DetailsListPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e)
{
	DetailsListPage->Show();
	HomePage->Hide();
	return System::Void();
}