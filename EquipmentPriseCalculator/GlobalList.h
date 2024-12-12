#pragma once
//Майсеенко Матвей Андреевич

#include <conio.h>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <regex>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <numeric>
#include <chrono>
#include <ctime>
//using namespace std;
//#pragma warning(disable : 4996)
//#define _CRT_SECURE_NO_WARNINGS
using std::string;
using std::map;
using std::vector;
using std::istream;
using std::istringstream;
using std::fstream;
using std::ofstream;
using std::to_string;
using std::endl;

using namespace System;
using namespace System::Windows::Forms;

struct Equipment {                      //оборудование
    int id;                             //id оборудования
    string Name;                        //название оборудования
    map<string, int> DetailsCount;      //взаимосвя
};

struct Detail {     //Деталь
    int id;         //id детали
    string Name;    //название детали
    double costs;   //цена детали
};


struct EquipmentComponents {
    Detail detail;
    int detailCount;
};

struct OrderedEquipment {
    Equipment equip;
    int equipmentsCount;
};

class GlobalList {

    double NDS = 0.2;
    double NacenkaOnPrise = 0.1;

    string fileName;

    double WhalePrice;

    int EquipmentCount;
    int DetailCount;

    string DetailFileName;
    string EquipmentFileName;

    vector<Equipment> EquipmentList;
    std::vector<Detail> DetailList;
    map<string, Detail> DetailsNameMap;
    map<string, Equipment> EquipmentNameMap;

    Equipment curEquipmentToAdd;

    map<string, OrderedEquipment> OrderedEquipmentList;

public:
    GlobalList() {
        //fstream DetailFile;
        //DetailFile.open("DetailSpisok.csv");

        //fstream EquipmentFile;
        //EquipmentFile.open("EquipmentSpisok.csv");

        ///////////////////fileName = "GlobalSpisok.csv"; ///базовый


        //this->readDetailsFile(DetailFile, *this, "DetailSpisok.csv");
        //this->readEquipmentFile(EquipmentFile, *this, "EquipmentSpisok.csv");

        ///////////////////////readFile(); ///базовый

        //DetailFile.close();
        //EquipmentFile.close();

    }
    ~GlobalList() {};

    vector<Detail> getDetailList() {
        return this->DetailList;
    }

    vector<Equipment> getEquipmentList() {
        return this->EquipmentList;
    }

    double getNacenkaOnPrice() {
        return this->NacenkaOnPrise;
    }

    double getNDS() {
        return this->NDS;
    }

    vector<OrderedEquipment> getOrderedEquipmentList(){
        vector<OrderedEquipment> components;
        for (auto equip : OrderedEquipmentList)
        {
            components.push_back(equip.second);
        }
        std::sort(components.begin(), components.end(), [](OrderedEquipment a, OrderedEquipment b) {
            return a.equip.id < b.equip.id;
            });

        return components;
    }

    int getMaxEquipmentsDetailsCount() {
        int count = 0;
        for (Equipment curEquipment : this->EquipmentList) {
            int curDetailsCount = curEquipment.DetailsCount.size();
            if (curDetailsCount > count)
            {
                count = curDetailsCount;
            }
        }
        return count;
    }

    void readExternalFile(string externalFileName) {
        fileName = externalFileName;
        DetailList.clear();
        DetailsNameMap.clear();
        EquipmentList.clear();
        EquipmentNameMap.clear();
        readFile();
    }

    void createNewProject() {
        fileName.clear();
        EquipmentList.clear();
        DetailList.clear();
        DetailsNameMap.clear();
        EquipmentNameMap.clear();
        OrderedEquipmentList.clear();

        Equipment emptyEquipment;
        curEquipmentToAdd = emptyEquipment;
    }

    void readFile() {
        fstream GlobalFile;

        GlobalFile.open(fileName);


        string line;
        bool isDetailsSection = false;

        while (getline(GlobalFile, line)) {
            if (line.find("########################Details##############################") != string::npos) {
                isDetailsSection = true;
            }
            else if (line.find("########################Equipment############################") != string::npos) {
                isDetailsSection = false;
            }
            else if (!line.empty()) {
                istringstream iss(line);
                if (isDetailsSection) {
                    // Read details
                    Detail curDetail;
                    string curId;
                    getline(iss, curId, ',');
                    curDetail.id = stoi(curId);

                    string curNameAndOtherInfo;
                    getline(iss, curNameAndOtherInfo, '\n');
                    string curName = unescapeName(curNameAndOtherInfo);
                    curDetail.Name = curName;


                    curDetail.costs = stod(curNameAndOtherInfo.substr(curName.size() + 1));
                    DetailsNameMap[curName] = curDetail;
                    DetailList.push_back(curDetail);
                }
                else {
                    // Read equipment
                    Equipment curEquipment;

                    string curId;
                    getline(iss, curId, ',');
                    curEquipment.id = stoi(curId);

                    string curNameAndOtherInfo;
                    getline(iss, curNameAndOtherInfo, '\n');
                    string curName = unescapeName(curNameAndOtherInfo);
                    curEquipment.Name = curName;

                    string curOtherInfo = curNameAndOtherInfo.substr(curName.size() + 1);

                    //string curInfo;
                    //getline(iss, curInfo);
                    istringstream issEquip(curOtherInfo);


                    string detailsInfo;
                    getline(issEquip, detailsInfo);

                    string detail;
                    string detailCount;

                    while (!detailsInfo.empty()) {
                        detail = unescapeName(detailsInfo);
                        if (detailsInfo.size() > detail.size() + 1) {
                            detailsInfo = detailsInfo.substr(detail.size() + 1);
                        }
                        else {
                            detailsInfo.clear();
                        }

                        if (!detailsInfo.empty()) {
                            detailCount = unescapeCount(detailsInfo);
                            if (detailsInfo.size() > detailCount.size() + 1) {
                                detailsInfo = detailsInfo.substr(detailCount.size() + 1);
                            }
                            else {
                                detailsInfo.clear();
                            }
                        }

                        if (!detailCount.empty()) {
                            int NeedCount = stoi(detailCount);
                            curEquipment.DetailsCount[detail] = NeedCount;
                        }
                    }
                    EquipmentNameMap[curName] = curEquipment;
                    EquipmentList.push_back(curEquipment);
                }
            }
        }
    }

    string unescapeName(const string& escapedString) {
        string unescapedString;
        bool escaped = false;
        for (int i = 0; i < escapedString.size(); i++) {
            char c = escapedString[i];
            if (escaped) {
                if (c == ',') {
                    unescapedString.push_back(c);
                    escaped = false;
                }
                else {
                    if (i > 0)
                    {
                        unescapedString.push_back(escapedString[i - 1]);
                    }
                    unescapedString.push_back(c);
                    escaped = false;
                }
            }
            else if (c == '|') {
                escaped = true;
            }
            else if (c == ',') {
                return unescapedString;
            }
            else {
                unescapedString.push_back(c);
            }
        }
        return unescapedString;
    }

    vector<EquipmentComponents> getCurEquipmentToAddComponents() {
        vector<EquipmentComponents> components;
        for (auto det : curEquipmentToAdd.DetailsCount)
        {
            EquipmentComponents curComponent;
            curComponent.detail = DetailsNameMap[det.first];
            curComponent.detailCount = det.second;
            components.push_back(curComponent);
        }
        return components;
    }

    vector<EquipmentComponents> getEquipmentsComponentList(Equipment curEquipment) {
        vector<EquipmentComponents> components;
        for (auto det : curEquipment.DetailsCount)
        {
            EquipmentComponents curComponent;
            curComponent.detail = DetailsNameMap[det.first];
            curComponent.detailCount = det.second;
            components.push_back(curComponent);
        }
        std::sort(components.begin(), components.end(), [](EquipmentComponents a, EquipmentComponents b) {
            return a.detail.id < b.detail.id;
            });
        return components;
    }

    void clearEquipmentToAdd() {
        curEquipmentToAdd.id = 0;
        curEquipmentToAdd.Name = "";
        curEquipmentToAdd.DetailsCount.clear();
    }

    void addNewEquipmentToList() {
        curEquipmentToAdd.id = EquipmentList.size() + 1;
        EquipmentList.push_back(curEquipmentToAdd);
        clearEquipmentToAdd();
    }

    vector<EquipmentComponents> getSortedCurEquipmentToAddComponents(String^ SelectedSortType) {
        vector<EquipmentComponents> SortComponentList = getCurEquipmentToAddComponents();
        if (SelectedSortType == "Id компонента")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](EquipmentComponents a, EquipmentComponents b) {
                return a.detail.id < b.detail.id;
                });
        }
        else if (SelectedSortType == "Названию компонета")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](EquipmentComponents a, EquipmentComponents b) {
                return a.detail.Name < b.detail.Name;
                });
        }
        else if (SelectedSortType == "Стоимости компонета")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](EquipmentComponents a, EquipmentComponents b) {
                return a.detail.costs < b.detail.costs;
                });
        }
        else if (SelectedSortType == "Количеству компонетов")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](EquipmentComponents a, EquipmentComponents b) {
                return a.detailCount < b.detailCount;
                });
        }
        else if (SelectedSortType == "Полной стоимоти компонетов")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](EquipmentComponents a, EquipmentComponents b) {
                return  (a.detailCount * a.detail.costs) < (b.detailCount * b.detail.costs);
                });
        }
        return SortComponentList;
    }

    vector<OrderedEquipment> getSortedOrderedEquipmentList(String^ SelectedSortType) {
        vector<OrderedEquipment> SortComponentList = getOrderedEquipmentList();
        if (SelectedSortType == "Id оборудования")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](OrderedEquipment a, OrderedEquipment b) {
                return a.equip.id < b.equip.id;
                });
        }
        else if (SelectedSortType == "Названию оборудования")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](OrderedEquipment a, OrderedEquipment b) {
                return a.equip.Name < b.equip.Name;
                });
        }
        else if (SelectedSortType == "Стоимости одного оборудования")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [this](OrderedEquipment a, OrderedEquipment b) {
                return sortEquipmentByPricePred(a.equip, b.equip, this);
                });
        }
        else if (SelectedSortType == "Количеству заказанного оборудования")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [](OrderedEquipment a, OrderedEquipment b) {
                return a.equipmentsCount < b.equipmentsCount;
                });
        }
        else if (SelectedSortType == "Полной стоимоти оборудования")
        {
            std::sort(SortComponentList.begin(), SortComponentList.end(), [this](OrderedEquipment a, OrderedEquipment b) {
                return  (getTotalEquipmentPrice(a.equip, this) * a.equipmentsCount) < (getTotalEquipmentPrice(b.equip, this) * b.equipmentsCount);
                });
        }
        return SortComponentList;
    }

    vector<EquipmentComponents> getFilteredComponentsListBySubStr(string subStr, vector<EquipmentComponents> details) {
        vector<EquipmentComponents> CorrectComponents;
        for (EquipmentComponents det : details) {

            if (containsSubString(convertToLowerCase(det.detail.Name), convertToLowerCase(subStr))) {
                CorrectComponents.push_back(det);
            }
        }

        return CorrectComponents;
    }

    vector<OrderedEquipment> getFilteredOrderedEquipmentListBySubStr(string subStr, vector<OrderedEquipment> OrderedEquipmentList) {
        vector<OrderedEquipment> CorrectComponents;
        for (OrderedEquipment det : OrderedEquipmentList) {
            if (containsSubString(convertToLowerCase(det.equip.Name), convertToLowerCase(subStr))) {
                CorrectComponents.push_back(det);
            }
        }

        return CorrectComponents;
    }

    void addNewComponentToCurEquipmentToAdd(string name) {
        curEquipmentToAdd.DetailsCount[name] = 1;
    }

    void removeComponentFromCurEquipmentToAddByName(string compName) {
        curEquipmentToAdd.DetailsCount.erase(compName);
    }

    void changeComponentsCountInCurEquipmentToAdd(int index, int count) {
        curEquipmentToAdd.DetailsCount[DetailList.at(index).Name] = count;
    }

    void setNameToCurEquipmentToAdd(string newName) {
        curEquipmentToAdd.Name = newName;
    }

    Equipment getCurEquipmentToAdd() {
        return curEquipmentToAdd;
    }

    string unescapeCount(const string& escapedString) {
        string unescapedString;
        for (int i = 0; i < escapedString.size(); i++) {
            char c = escapedString[i];
            if (c == ',') {
                return unescapedString;
            }
            else {
                unescapedString.push_back(c);
            }
        }
        return unescapedString;
    }

    void readDetailsFile(istream& DetailFile, GlobalList& List, string DetailFileTitle) {
        DetailFileName = DetailFileTitle;
        int DetailCounter = 0;
        string curDetailInfo;

        while (getline(DetailFile, curDetailInfo)) {
            istringstream iss(curDetailInfo);
            Detail curDetail;
            string curId;
            getline(iss, curId, ',');
            curDetail.id = stoi(curId);

            string curName;
            getline(iss, curName, ',');
            curDetail.Name = curName;

            string detailCost;
            getline(iss, detailCost);
            curDetail.costs = stod(detailCost);
            DetailsNameMap[curName] = curDetail;
            DetailList.push_back(curDetail);
            DetailCounter++;
        }
    }
    void readEquipmentFile(istream& EquipmentFile, GlobalList& List, string EquipmentFileTitle) {
        EquipmentFileName = EquipmentFileTitle;
        int EquipmentCounter = 0;
        string curEquipmentInfo;

        while (getline(EquipmentFile, curEquipmentInfo)) {
            istringstream issEquip(curEquipmentInfo);
            Equipment curEquipment;

            string curId;
            getline(issEquip, curId, ',');
            curEquipment.id = stoi(curId);

            string curName;
            getline(issEquip, curName, ',');
            curEquipment.Name = curName;

            string curInfo;
            getline(issEquip, curInfo);
            istringstream iss(curInfo);

            string detail;
            string detailCount;
            EquipmentNameMap[curName] = curEquipment;
            EquipmentList.push_back(curEquipment);

            EquipmentCounter++;
        }


        EquipmentCount = EquipmentCounter;

    }

    //////////////////////////////////////////////////////////////////////////////


    vector<Detail> SortDetailsList(String^ SelectedSortType) {
        std::vector<Detail> SortDetailList = this->DetailList;
        if (SelectedSortType == "Id детали")
        {
            std::sort(SortDetailList.begin(), SortDetailList.end(), [](Detail a, Detail b) {
                return a.id < b.id;
                });
        }
        else if (SelectedSortType == "Названию детали")
        {
            std::sort(SortDetailList.begin(), SortDetailList.end(), [](Detail a, Detail b) {
                return a.Name < b.Name;
                });
        }
        else if (SelectedSortType == "Стоимости детали")
        {
            std::sort(SortDetailList.begin(), SortDetailList.end(), [](Detail a, Detail b) {
                return a.costs < b.costs;
                });
        }
        return SortDetailList;
    }

    vector<Equipment> SortEquipmentList(String^ SelectedSortType) {
        std::vector<Equipment> SortEquipmentList = this->EquipmentList;
        if (SelectedSortType == "Id оборудования")
        {
            std::sort(SortEquipmentList.begin(), SortEquipmentList.end(), [](Equipment a, Equipment b) {
                return a.id < b.id;
                });
        }
        else if (SelectedSortType == "Названию оборудования")
        {
            std::sort(SortEquipmentList.begin(), SortEquipmentList.end(), [](Equipment a, Equipment b) {
                return a.Name < b.Name;
                });
        }
        else if (SelectedSortType == "Стоимости оборудования")
        {
            std::sort(SortEquipmentList.begin(), SortEquipmentList.end(), [this](const Equipment& a, const Equipment& b) {
                return sortEquipmentByPricePred(a, b, this);
                });
        }
        return SortEquipmentList;
    }

    static double getTotalEquipmentPrice(Equipment curEquipment, GlobalList* manager) {
        double totalPrice = 0;
        for (auto det : curEquipment.DetailsCount)
        {
            totalPrice += manager->DetailsNameMap[det.first].costs * det.second;
        }
        return totalPrice;
    }

    static bool sortEquipmentByPricePred(Equipment a, Equipment b, GlobalList* manager) {
        return getTotalEquipmentPrice(a, manager) < getTotalEquipmentPrice(b, manager);
    }


public:

    double GetEquipmentPrice(Equipment& Equip) {
        double Price = 0;
        for (auto element : Equip.DetailsCount)
        {
            double PriceForADetail = DetailsNameMap[element.first].costs;
            int DetailCount = element.second;
            Price += PriceForADetail * DetailCount;
        }

        return Price;
    }

    ////////////////////////////////////////////////////////////

    string convertToLowerCase(const string& input) {
        if (input.empty())
        {
            return input;
        }
        string result = input;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    bool is_number(const std::string& s) {
        for (char const& c : s) {
            if (!std::isdigit(c) && c != '.' && c != '-') {
                return false;
            }
            else if (!std::isdigit(c)) {
                return false;
            }
        }
        return !s.empty();
    }

    //////////////////////////////////////////////////////////////

    bool containsSubString(string str, string substr) {
        return str.find(substr) != std::string::npos;
    }

    vector<Equipment> getFilteredEquipmentListBySubStr(string subStr, vector<Equipment> equipments) {
        vector<Equipment> CorrectDetails;
        for (Equipment equip : equipments) {

            if (containsSubString(convertToLowerCase(equip.Name), convertToLowerCase(subStr))) {
                CorrectDetails.push_back(equip);
            }
        }

        return CorrectDetails;
    }

    vector<Detail> getFilteredDetailsListBySubStr(string subStr, vector<Detail> details) {
        vector<Detail> CorrectDetails;
        for (Detail det : details) {

            if (containsSubString(convertToLowerCase(det.Name), convertToLowerCase(subStr))) {
                CorrectDetails.push_back(det);
            }
        }

        return CorrectDetails;
    }

    vector<string> findEquipmentsByName(string subStr, vector<string> strings) {
        vector<string> CorrectStrings;
        for (string str : strings) {

            if (containsSubString(str, subStr)) {
                CorrectStrings.push_back(str);
            }
        }

        return CorrectStrings;
    }

    vector<string> findEquipmentsByNameWithLower(string subStr, vector<string> strings) {
        vector<string> CorrectStrings;
        for (string str : strings) {
            string curElemNameLow = convertToLowerCase(str);
            if (containsSubString(curElemNameLow, subStr)) {
                CorrectStrings.push_back(str);
            }
        }

        return CorrectStrings;
    }

    //////////////////////////////////////////////////////////

    std::string formatDouble(double value) {
        std::ostringstream out;
        out << std::fixed << std::setprecision(15) << value; // Устанавливаем большую точность

        std::string str = out.str();
        // Удаляем лишние нули в конце строки после запятой
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        if (str.back() == '.') {
            str.pop_back(); // Удаляем точку, если она осталась в конце строки
        }

        return str;
    }

    void editCountOfTheEquipmentsComponentByName(string componentsName, int componentsCount) {
        curEquipmentToAdd.DetailsCount[componentsName] = componentsCount;
    }

    void editCountOfOrderedEquipmentByName(string componentsName, int componentsCount) {
        OrderedEquipmentList[componentsName].equipmentsCount = componentsCount;
        //for (auto curEquip : OrderedEquipmentList)
        //{
        //    if (curEquip.equip.Name == componentsName)
        //    {
        //        curEquip.equipmentsCount = componentsCount;
        //    }
        //}
    }

    void incrementCountOfTheEquipmentsComponentByName(string componentsName) {
        curEquipmentToAdd.DetailsCount[componentsName] = curEquipmentToAdd.DetailsCount[componentsName] + 1;
    }

    void decrementCountOfTheEquipmentsComponentByName(string componentsName) {
        curEquipmentToAdd.DetailsCount[componentsName] = curEquipmentToAdd.DetailsCount[componentsName] - 1;
    }

    void decrementCountOfOrderedEquipmentByName(string equipmentName) {
        OrderedEquipmentList[equipmentName].equipmentsCount = OrderedEquipmentList[equipmentName].equipmentsCount - 1;
    }

    void incrementCountOfOrderedEquipmentByName(string equipmentName) {
        OrderedEquipmentList[equipmentName].equipmentsCount = OrderedEquipmentList[equipmentName].equipmentsCount + 1;
    }

    void removeOrderedEquipmentByName(string equipmentName) {
        OrderedEquipmentList.erase(equipmentName);
    }

    std::string getOldDetailsValue(int collumnIndex, int rowIndex) {
        Detail curDetail = DetailList.at(rowIndex);
        if (collumnIndex == 0)
        {
            return std::to_string(curDetail.id);
        }
        else if (collumnIndex == 1) {
            return curDetail.Name;
        }
        else if (collumnIndex == 2) {
            return formatDouble(curDetail.costs);
        }
    }

    void setNewComponentsValue(int collumnIndex, int rowIndex, string oldValue, string newValue) {
        Equipment curEquipment = EquipmentList.at(rowIndex);
        if (collumnIndex == 0) {
            curEquipment.id = stoi(newValue);
        }
        else if (collumnIndex == 1) {
            curEquipment.Name = newValue;
        }
        else if (collumnIndex >= 2 && (collumnIndex - 2) % 2 == 0) {
            int countOfEquipmentComp = curEquipment.DetailsCount[oldValue];
            curEquipment.DetailsCount.erase(oldValue);

            curEquipment.DetailsCount[newValue] = countOfEquipmentComp;

            Detail editedComponent = DetailsNameMap[oldValue];
            DetailsNameMap.erase(oldValue);

            editedComponent.Name = newValue;
            DetailsNameMap[newValue] = editedComponent;
        }
        else if (collumnIndex >= 3 && (collumnIndex - 2) % 2 == 1) {
            curEquipment.DetailsCount[oldValue] = stoi(newValue);
        }
        EquipmentList.at(rowIndex) = curEquipment;
    }

    std::string getOldComponentsValue(string componentName, int collumnIndex) {
        Detail curComponent = DetailsNameMap[componentName];
        if (collumnIndex == 2) {
            return std::to_string(curComponent.id);
        }
        else if (collumnIndex == 3) {
            return curComponent.Name;
        }
        else if (collumnIndex == 5) {
            return formatDouble(curComponent.costs);
        }
    }

    std::string getOldEquipmentsValue(int collumnIndex, int rowIndex) {
        Equipment curEquipment = EquipmentList.at(rowIndex);
        if (collumnIndex == 0)
        {
            return std::to_string(curEquipment.id);
        }
        else if (collumnIndex == 1) {
            return curEquipment.Name;
        }
    }

    void editDetailsInfoByOldName(int collumnIndex, int rowIndex, string newValue) {
        if (collumnIndex == 0) {
            DetailList.at(rowIndex).id = stoi(newValue);
        }
        else if (collumnIndex == 1) {
            DetailList.at(rowIndex).Name = newValue;
        }
        else if (collumnIndex == 2) {
            DetailList.at(rowIndex).costs = stod(newValue);
        }
        else
        {
            return;
        }
    }

    std::vector<Detail> sortDetailsById(const std::vector<Detail>& details) {
        // Создаем копию входного вектора
        std::vector<Detail> sortedDetails = details;

        // Сортируем копию по возрастанию id
        std::sort(sortedDetails.begin(), sortedDetails.end(), [](Detail a, Detail b) {
            return a.id < b.id;
            });

        return sortedDetails;
    }
    string ecraningStringWithCommas(const string& escapedString) {
        string unescapedString;
        for (int i = 0; i < escapedString.size(); i++) {
            char c = escapedString[i];
            if (c == ',') {
                unescapedString.push_back('|');
                unescapedString.push_back(c);
            }
            else {
                unescapedString.push_back(c);
            }
        }
        return unescapedString;
    }

    void SaveAllInFileAs(string externalFileName) {
        fileName = externalFileName;
        SaveAllInFile();
    }

    bool getIsFilePathEmpty() {
        return fileName.empty();
    }

    ofstream& SaveAllInFile() {
        std::ofstream file(fileName);
        if (file.is_open()) {
            file << "########################Details##############################\n";
            for (const auto& detail : DetailList) {
                file << detail.id << "," << ecraningStringWithCommas(detail.Name) << "," << detail.costs << "\n";
            }
            file << "\n########################Equipment############################\n";
            for (const auto& equip : EquipmentList) {
                file << equip.id << "," << ecraningStringWithCommas(equip.Name);
                for (const auto& component : equip.DetailsCount) {
                    file << "," << ecraningStringWithCommas(component.first) << "," << component.second;
                }
                file << "\n";
            }
            file.close();
        }
        return file;

    }

    string getCurrentTime() {
        // Получение текущего времени
        auto now = std::chrono::system_clock::now();

        // Преобразование времени в тип time_t для работы с ctime
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Преобразование времени в человекочитаемый формат
        std::tm* localTime = std::localtime(&currentTime);

        // Использование stringstream для форматирования времени в std::string
        std::ostringstream oss;
        oss << std::put_time(localTime, "%d-%m-%Y_%H-%M");
        std::string formattedTime = oss.str();

        return formattedTime;

    }


    ofstream& SaveOrderInFile(string orderName) {
        std::ofstream file(orderName);
        if (file.is_open()) {
            std::vector<std::string> headerTexts = {
                "Заказ от " + orderName,
                "Время:" + getCurrentTime(),
                "Через приложение",
                "Equipment Price Calculator",
                "___________________________________________________________________________________________"
            };

            for (const auto& text : headerTexts) {
                int padding = (92 - text.length()) / 2;
                if (padding < 0) padding = 0;
                file << std::setw(padding + text.length()) << std::right << text << std::endl;
            }

            file << std::right << "Товар\t Цена\t Кол-во\t Стоимость\t" << std::endl;

            double TotalOrderPrice = 0;

            for (auto curOrderedEquipment : OrderedEquipmentList) {

                double curEquipmentPrice = GetEquipmentPrice(curOrderedEquipment.second.equip);
                int countOfOrderedEquipment = curOrderedEquipment.second.equipmentsCount;
                double curEquipmentTotalPrice = countOfOrderedEquipment * curEquipmentPrice;
                double curEquipmentTotalPriceWithNDS = countOfOrderedEquipment * (
                    curEquipmentPrice + 
                    countOfOrderedEquipment * curEquipmentPrice * NDS +
                    countOfOrderedEquipment * curEquipmentPrice * NacenkaOnPrise
                );

                TotalOrderPrice += curEquipmentTotalPriceWithNDS;

                file << curOrderedEquipment.first << "\t"
                    << curEquipmentPrice << "BYN\t"
                    << countOfOrderedEquipment << "\t"
                    << curEquipmentTotalPrice << "BYN\n";

                file << "НДС: " << 100 * NDS << "%\n"
                    << "Итого получено: " << curEquipmentTotalPriceWithNDS << "BYN\n";

            }
            file << "___________________________________________________________________________________________\n";

            file << "ИТОГО ДЛЯ ВЫПОЛНЕНИЯ ЗАКАЗА ТРЕБУЕТСЯ :\n";

            std::map<string, int> necessaryDetailsMap;

            for (auto curOrderedEquipment : OrderedEquipmentList) {
                for (auto curDet : curOrderedEquipment.second.equip.DetailsCount) {
                    if (necessaryDetailsMap.find(curDet.first) != necessaryDetailsMap.end())
                    {
                        necessaryDetailsMap[curDet.first] += curDet.second * curOrderedEquipment.second.equipmentsCount;
                    }
                    else
                    {
                        necessaryDetailsMap[curDet.first] = curDet.second * curOrderedEquipment.second.equipmentsCount;
                    }
                }
            }

            for (auto curDet : necessaryDetailsMap) {
                file << "\t" << curDet.first << "\t" << curDet.second << "\n";
            }

            file << "\n";
            file << "ИТОГОВАЯ ПРИБЫЛЬ: " << TotalOrderPrice * NacenkaOnPrise;

            file.close();
        }
        return file;

    }

    ofstream& SaveCheckInFileByFilename(string checkSavePath) {
        std::ofstream file(checkSavePath);
        if (file.is_open()) {
            std::vector<std::string> headerTexts = { 
                "Чек",
                "Покупки оборудование",
                "Через приложение",
                "Equipment Price Calculator",
                "___________________________________________________________________________________________" 
            };

            for (const auto& text : headerTexts) {
                int padding = (92 - text.length()) / 2; 
                if (padding < 0) padding = 0; 
                file << std::setw(padding + text.length()) << std::right << text << std::endl; 
            }
            
            file << std::right << "Товар\t Цена\t Кол-во\t Стоимость\t" << std::endl;

            double TotalOrderPrice = 0;
       
            for (auto curOrderedEquipment : OrderedEquipmentList) {

                double curEquipmentPrice = GetEquipmentPrice(curOrderedEquipment.second.equip);
                int countOfOrderedEquipment = curOrderedEquipment.second.equipmentsCount;
                double curEquipmentTotalPrice = countOfOrderedEquipment * curEquipmentPrice;
                double curEquipmentTotalPriceWithNDS = countOfOrderedEquipment * curEquipmentPrice + countOfOrderedEquipment * curEquipmentPrice * NDS;

                TotalOrderPrice += curEquipmentTotalPriceWithNDS;

                file << curOrderedEquipment.first << "\t" 
                    << curEquipmentPrice << "BYN\t" 
                    << countOfOrderedEquipment << "\t"
                    << curEquipmentTotalPrice << "BYN\n";

                file << "НДС: " << 100 * NDS << "%\n"
                    << "Итого: " << curEquipmentTotalPriceWithNDS << "BYN\n";
                
            }
            file << "___________________________________________________________________________________________\n";

            file << "ИТОГО К ОПЛАТЕ: " << TotalOrderPrice;

            file.close();
        }
        return file;

    }

    void removeDetailByName(string elementNameToDelete) {

        // Удаляем элемент из DetailList и DetailsNameMap
        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
            if (it->Name == elementNameToDelete) {

                for (auto itE = EquipmentList.begin(); itE != EquipmentList.end(); ++itE) {
                    if (itE->DetailsCount.find(elementNameToDelete) != itE->DetailsCount.end()) {
                        EquipmentNameMap.erase(itE->Name);
                        EquipmentList.erase(itE);
                        break;
                    }
                }

                DetailsNameMap.erase(it->Name);
                DetailList.erase(it);
                break;
            }
        }
    }

    void removeEquipmentByName(string elementNameToDelete) {

        for (auto it = EquipmentList.begin(); it != EquipmentList.end(); ++it) {
            if (it->Name == elementNameToDelete) {
                EquipmentNameMap.erase(it->Name);
                EquipmentList.erase(it);
                break;
            }
        }
    }

    void addEquipmentToOrderListByName(string equipmentNameToAdd) {

        for (auto curEquipment : EquipmentList) {
            if (curEquipment.Name == equipmentNameToAdd) {
                bool isAlreadyOrdered = false;
                

                if (OrderedEquipmentList.find(equipmentNameToAdd) != OrderedEquipmentList.end()) {
                    OrderedEquipmentList[equipmentNameToAdd].equipmentsCount = OrderedEquipmentList[equipmentNameToAdd].equipmentsCount + 1;
                }
                else {
                    OrderedEquipment equipmentToAdd;
                    equipmentToAdd.equip = curEquipment;
                    equipmentToAdd.equipmentsCount = 1;
                    OrderedEquipmentList[equipmentNameToAdd] = equipmentToAdd;
                }
               

                break;
            }
        }
    }

    fstream& addDetailByNameAndCost(string name, double cost) {
        fstream UpgradedDetailFile;
        UpgradedDetailFile.open("DetailSpisok.csv", std::ios::app);


        int maxId = 0;
        for (Detail element : DetailList)
        {
            if (element.id > maxId)
            {
                maxId = element.id;
            }
        }


        DetailCount++;

        Detail newDetail;
        int newId = ++maxId;
        newDetail.id = newId;
        newDetail.Name = name;
        newDetail.costs = cost;

        UpgradedDetailFile << newId << ',' << name << ',' << cost << endl;

        DetailList.push_back(newDetail);
        DetailsNameMap[name] = newDetail;
        return UpgradedDetailFile;
    }


    /////////////////////////////////////////////////////////// 

};
