#pragma once
#include "EquipmentPriceCalculator.h"

System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowDetailsPage(System::Object^ sender, System::EventArgs^ e)
{
	DetailsPage->Show();
	HomePage->Hide();
	return System::Void();
}
System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowGuidOnClick(System::Object^ sender, System::EventArgs^ e) {
	system("cls");
	system("guide.pdf");
	return System::Void();
}
System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowEquipmentPage(System::Object^ sender, System::EventArgs^ e)
{
	EquipmentPage->Show();
	HomePage->Hide();
	return System::Void();
}