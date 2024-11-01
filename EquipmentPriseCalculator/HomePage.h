#pragma once
#include "EquipmentPriceCalculator.h"

System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowGuidOnClick(System::Object^ sender, System::EventArgs^ e) {
	system("cls");
	system("guide.pdf");
	return System::Void();
}
inline System::Void EquipmentPriseCalculator::EquipmentPriceCalculator::ShowEquipmentListPage(System::Object^ sender, System::EventArgs^ e)
{
	HomePage->Hide();
	EquipmentListPage->Show();
	return System::Void();
}