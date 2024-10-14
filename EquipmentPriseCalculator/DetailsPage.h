#pragma once
#include "EquipmentPriceCalculator.h"

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::GoBackFromDetailsPageToHomePage(System::Object^ sender, System::EventArgs^ e)
{
	HomePage->Show();
	DetailsPage->Hide();
	return System::Void();
}

inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowDetailsListPage(System::Object^ sender, System::EventArgs^ e)
{
	DetailsListPage->Show();
	DetailsPage->Hide();
	return System::Void();
}