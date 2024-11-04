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


class GlobalList {

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

public:
    GlobalList() {
        fstream DetailFile;
        DetailFile.open("DetailSpisok.csv");

        fstream EquipmentFile;
        EquipmentFile.open("EquipmentSpisok.csv");

        fileName = "GlobalSpisok.csv";


        //this->readDetailsFile(DetailFile, *this, "DetailSpisok.csv");
        //this->readEquipmentFile(EquipmentFile, *this, "EquipmentSpisok.csv");

        readFile();
        DetailFile.close();
        EquipmentFile.close();

    }
    ~GlobalList() {};

    vector<Detail> getDetailList() {
        return this->DetailList;
    }

    vector<Equipment> getEquipmentList() {
        return this->EquipmentList;
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
                    //while (!detailsInfo.empty()) {
                    //    detail = unescapeName(detailsInfo);
                    //    detailsInfo = detailsInfo.substr(detail.size() + 2);
                    //    
                    //    detailCount = unescapeCount(detailsInfo);
                    //    detailsInfo = detailCount.substr(detail.size() + 2);
                    //    int NeedCount = stoi(detailCount);
                    //    curEquipment.DetailsCount[detail] = NeedCount;
                    //};
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
            //while (getline(iss, detail, ',') && !detail.empty()) {
            //    getline(iss, detailCount, ',');
            //    int NeedCount = stoi(detailCount);
            //    curEquipment.DetailsCount[detail] = NeedCount;
            //}
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
    //void mainPage() {
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Материалы\n";
    //    cout << "2. Оборудование\n";
    //    cout << "3. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                MaterialPage();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                EquipmentPage();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                exit(0);
    //                break;
    //            }
    //        }
    //    }
    //}

    //void EquipmentPage() {
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Смотреть весь список\n";
    //    cout << "2. Редактировать список\n";
    //    cout << "3. Поиск\n";
    //    cout << "4. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                LookWholeEquipmentListPage();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                EditEquipmentListPage();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                outputFindingEquipment();
    //                break;
    //            }
    //            else if (ch == 52) { //4
    //                system("cls");
    //                mainPage();
    //                break;
    //            }
    //        }
    //    }
    //}

    //void MaterialPage() {
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Смотреть весь список\n";
    //    cout << "2. Редактировать список\n";
    //    cout << "3. Поиск\n";
    //    cout << "4. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                LookWholeDetailListPage();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                EditMaterialListPage();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                outputFindingDetail();
    //                break;
    //            }
    //            else if (ch == 52) { //4
    //                system("cls");
    //                mainPage();
    //                break;
    //            }
    //        }
    //    }
    //}

    //void EditMaterialListPage() {
    //    cout << "Выберете способ редактирования:\n";
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Добавить элемент\n";
    //    cout << "2. Редактировать элемент по имени\n";
    //    cout << "3. Удалить элемент по имени\n";
    //    cout << "4. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                addDetailByName();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                editDetailByName();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                removeDetailByName();
    //                break;
    //            }
    //            else if (ch == 52) { //4
    //                system("cls");
    //                mainPage();
    //                break;
    //            }
    //        }
    //    }
    //}

    //void EditEquipmentListPage() {
    //    cout << "Выберете способ редактирования:\n";
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Добавить элемент\n";
    //    cout << "2. Редактировать элемент по имени\n";
    //    cout << "3. Удалить элемент по имени\n";
    //    cout << "4. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                addEquipmentByName();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                editEquipmentByName();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                removeEquipmentByName();
    //                break;
    //            }
    //            else if (ch == 52) { //4
    //                system("cls");
    //                EquipmentPage();
    //                break;
    //            }
    //        }
    //    }
    //}


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


    //////////////////////////////////////////////

    void LookWholeEquipmentListById() {
        sort(EquipmentList.begin(), EquipmentList.end(), [](Equipment a, Equipment b) {
            return a.id < b.id;
            });

        //cout << left << "|" << "Id оборудования"
        //    << "|" << setw(30) << "Название оборудования"
        //    << "|" << "Стоимость оборудования, p" << "|" << endl;

        //for (Equipment element : EquipmentList)
        //{
        //    cout << left
        //        << "|" << setw(15) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(25) << GetEquipmentPrice(element) << "|" << endl;
        //}

        //cout << "Нажмите на любую клавишу для выхода в гланое меню...";
        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;
        //    }
        //}

    }

    void LookWholeEquipmentListByName() {
        sort(EquipmentList.begin(), EquipmentList.end(), [](Equipment a, Equipment b) {
            return a.Name < b.Name;
            });

        //cout << left << "|" << "Id оборудования"
        //    << "|" << setw(30) << "Название оборудования"
        //    << "|" << "Стоимость оборудования, p" << "|" << endl;

        //for (Equipment element : EquipmentList)
        //{
        //    //cout << element.id << " " << element.Name << " " << GetEquipmentPrice(element) << "p" << endl;
        //    cout << left
        //        << "|" << setw(15) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(25) << GetEquipmentPrice(element) << "|" << endl;
        //}

        //cout << "Нажмите на любую клавишу для выхода в гланое меню...";
        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;
        //    }
        //}

    }

    void LookWholeEquipmentListByPrice() {
        sort(EquipmentList.begin(), EquipmentList.end(), [this](Equipment a, Equipment b) {
            return GetEquipmentPrice(a) < GetEquipmentPrice(b);
            });


        /*       cout << left << "|" << "Id оборудования"
                   << "|" << setw(30) << "Название оборудования"
                   << "|" << "Стоимость оборудования, p" << "|" << endl;

               for (Equipment element : EquipmentList)
               {

                   cout << left
                       << "|" << setw(15) << element.id
                       << "|" << setw(30) << element.Name
                       << "|" << setw(25) << GetEquipmentPrice(element) << "|" << endl;

               }

               cout << "Нажмите на любую клавишу для выхода в гланое меню...";
               while (true) {
                   if (_kbhit()) {
                       system("cls");
                       mainPage();
                       break;
                   }
               }*/

    }

    //////////////////////////////////////////////////////////

    //void LookWholeDetailListPage() {
    //    cout << "Введите номер пункта:\n";
    //    cout << "1. Отсортироват по id\n";
    //    cout << "2. Отсортироват по названию\n";
    //    cout << "3. Отсортироват по стоимости\n";
    //    cout << "4. Выход\n";
    //    while (true) {
    //        if (_kbhit()) {
    //            char ch = _getch();
    //            if (ch == 49) { //1
    //                system("cls");
    //                LookWholeDetailListById();
    //                break;
    //            }
    //            else if (ch == 50) { //2
    //                system("cls");
    //                LookWholeDetailListByName();
    //                break;
    //            }
    //            else if (ch == 51) { //3
    //                system("cls");
    //                LookWholeDetailListByPrice();
    //                break;
    //            }
    //            else if (ch == 52) { //3
    //                system("cls");
    //                askToGoToMainMenu();
    //                break;
    //            }
    //        }
    //    }

    //}

    void LookWholeDetailListById() {
        sort(DetailList.begin(), DetailList.end(), [](Detail a, Detail b) {
            return a.id < b.id;
            });

        //cout << left << "|" << "Id детали"
        //    << "|" << setw(30) << "Название детали"
        //    << "|" << "Стоимость детали, р/шт" << "|" << endl;

        //for (auto element : DetailList)
        //{

        //    cout << left
        //        << "|" << setw(9) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(22) << element.costs << "|" << endl;
        //}


        //cout << "Нажмите на любую клавишу для выхода в гланое меню...";

        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;

        //    }
        //}

    }

    void LookWholeDetailListByName() {
        sort(DetailList.begin(), DetailList.end(), [](Detail a, Detail b) {
            return a.Name < b.Name;
            });

        //cout << left << "|" << "Id детали"
        //    << "|" << setw(30) << "Название детали"
        //    << "|" << "Стоимость детали, р/шт" << "|" << endl;

        //for (auto element : DetailList)
        //{

        //    cout << left
        //        << "|" << setw(9) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(22) << element.costs << "|" << endl;
        //}


        //cout << "Нажмите на любую клавишу для выхода в гланое меню...";

        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;

        //    }
        //}

    }

    void LookWholeDetailListByPrice() {
        sort(DetailList.begin(), DetailList.end(), [](Detail a, Detail b) {
            return a.costs < b.costs;
            });

        //cout << left << "|" << "Id детали"
        //    << "|" << setw(30) << "Название детали"
        //    << "|" << "Стоимость детали, р/шт" << "|" << endl;

        //for (auto element : DetailList)
        //{

        //    cout << left
        //        << "|" << setw(9) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(22) << element.costs << "|" << endl;
        //}


        //cout << "Нажмите на любую клавишу для выхода в гланое меню...";

        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;

        //    }
        //}

    }

    //void LookWholeDetailList() {
    //    for (auto element : DetailsNameMap)
    //    {
    //        cout << element.second.id << " " << element.first << " " << element.second.costs << endl;
    //    }


    //    cout << "Нажмите на любую клавишу для выхода в гланое меню...";

    //    while (true) {
    //        if (_kbhit()) {
    //            system("cls");
    //            mainPage();
    //            break;

    //        }
    //    }

    //}

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


    /*    bool is_number(const std::string& s) {
        for (char const& c : s) {
            if (!std::isdigit(c) && c != '.' && c != '-') {
                return false;
            }
            else if (!std::isdigit(c)) {
                return false;
            }
        }
        return !s.empty();
        for (char c : s) {
            if (c = s[0])
            {
                if (!std::isdigit(c) && s[0] != '-') {
                    return false;
                }
            }
            else if (!std::isdigit(c)) {
                return false;
            }
        }
        return !s.empty();
    }*/
    //void askToGoToMainMenu() {
    //    cout << "\nНажмите на любую клавишу для выхода в гланое меню...";
    //    while (true) {
    //        if (_kbhit()) {
    //            system("cls");
    //            mainPage();
    //            break;
    //        }
    //    }
    //}


    //валидация
   /* void getInfo(string& str, string message) {
        cout << message;
        do
        {
            getline(cin, str);
            if (str.size() == 0) {
                cout << "\nОшибка: Ничего не было введено"
                    << "\nВыберете пункт:"
                    << "\n1.Выйти в главное меню"
                    << "\n2.Ввести еще раз";

                while (true) {
                    if (_kbhit()) {
                        char ch = _getch();
                        if (ch == 49) { //1
                            system("cls");
                            str = "";
                            return;
                        }
                        else if (ch == 50) { //2
                            cout << endl << message;
                            break;
                        }
                    }
                }

            }
            else if (str.size() > 30) {
                cout << "\nОшибка: Слишком большой ввод"
                    << "\nВыберете пункт:"
                    << "\n1.Выйти в главное меню"
                    << "\n2.Ввести еще раз";

                while (true) {
                    if (_kbhit()) {
                        char ch = _getch();
                        if (ch == 49) { //1
                            str = "";
                            return;
                        }
                        else if (ch == 50) { //2
                            cout << endl << message;
                            break;
                        }
                    }
                }
            }
            else if (str.size() < 30)
            {
                break;
            }
        } while (true);
    }*/

    //валидация
   /* void getInfoWithoutChoise(string& str, string message) {
        cout << message;
        do
        {
            getline(cin, str);
            if (str.size() == 0) {
                cout << "\nОшибка: Ничего не было введено";
                cout << endl << message;
                break;

            }
            else if (str.size() > 30) {
                cout << "\nОшибка: Слишком большой ввод";
                cout << endl << message;

            }
            else if (str.size() < 30)
            {
                break;
            }
        } while (true);
    }*/

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

    void outputFindingDetail() {
        vector<string> strings;
        for (Detail element : DetailList)
        {
            strings.push_back(element.Name);
        }
        string subStr;
        vector<string> FindingEquipment;
        bool isGoing = true;
        do
        {
            isGoing = true;
            //getInfo(subStr, "Введите название оборудования: ");
            subStr = convertToLowerCase(subStr);

            FindingEquipment = findEquipmentsByNameWithLower(subStr, strings);

            if (FindingEquipment.empty()) {
                //cout << "Такого оборудования нет в наличии...";
                //cout << "\nВыберете пункт:"
                //    << "\n1.Выйти в главное меню"
                //    << "\n2.Продолжить поиск\n";

                while (true) {
                    if (_kbhit()) {
                        char ch = _getch();
                        if (ch == 49) { //1
                            //askToGoToMainMenu();
                            return;
                        }
                        else if (ch == 50) { //2
                            break;
                        }
                    }
                }
            }
            else
            {
                isGoing = false;
            }
        } while (isGoing);
        if (FindingEquipment.size() != 0)
        {
            //cout << left << setw(20)
            //    << "Id " << setw(40)
            //    << "Название оборудования" << setw(40)
            //    << "стоимость, p/шт." << endl;
            //for (string element : FindingEquipment)
            //{
            //    Detail curDetail = DetailsNameMap[element];
            //    cout << left << setw(20)
            //        << curDetail.id << setw(40)
            //        << curDetail.Name << setw(40)
            //        << curDetail.costs << endl;

            //}
        }


        //cout << "\nНажмите на любую клавишу для выхода в гланое меню...";

        //while (true) {
        //    if (_kbhit()) {
        //        system("cls");
        //        mainPage();
        //        break;
        //    }
        //}
    }

    void outputFindingEquipment() {
        vector<string> strings;
        for (Equipment element : EquipmentList)
        {
            strings.push_back(element.Name);
        }

        string subStr;
        vector<string> FindingEquipment;
        bool isGoing = true;
        do
        {
            isGoing = true;
            //getInfo(subStr, "Введите название оборудования: ");
            subStr = convertToLowerCase(subStr);

            FindingEquipment = findEquipmentsByNameWithLower(subStr, strings);

            //if (FindingEquipment.empty()) {
            //    cout << "Такого оборудования нет в наличии...";
            //    cout << "\nВыберете пункт:"
            //        << "\n1.Выйти в главное меню"
            //        << "\n2.Продолжить поиск\n";

            //    while (true) {
            //        if (_kbhit()) {
            //            char ch = _getch();
            //            if (ch == 49) { //1
            //                askToGoToMainMenu();
            //                return;
            //            }
            //            else if (ch == 50) { //2
            //                break;
            //            }
            //        }
            //    }
            //}
            //else
            //{
            //    isGoing = false;
            //}
        } while (isGoing);

        if (!FindingEquipment.empty())
        {
            //cout << left << setw(20)
            //    << "Id " << setw(40)
            //    << "Название оборудования" << setw(40)
            //    << "Компоненты" << setw(80) << endl << endl;

            int maxDetalCount = 0;

            for (string element : FindingEquipment)
            {
                Equipment curEquip = EquipmentNameMap[element];
                int curDetailCount = 0;
                for (auto elemMap : curEquip.DetailsCount)
                {
                    curDetailCount++;
                }

                if (curDetailCount > maxDetalCount)
                {
                    maxDetalCount = curDetailCount;
                }
            }

            for (string element : FindingEquipment)
            {
                Equipment curEquip = EquipmentNameMap[element];
                //cout << left << setw(20)
                //    << curEquip.id << setw(40)
                //    << curEquip.Name << setw(20);

                double Total = 0;
                int detailCount = 0;
                //for (auto elemMap : curEquip.DetailsCount)
                //{
                //    detailCount++;
                //    double DetCost = DetailsNameMap[elemMap.first].costs * elemMap.second;
                //    Total += DetCost;
                //    cout << left << setw(20) << DetCost << "р за " << elemMap.second << "шт. " << setw(20) << elemMap.first;
                //    cout << setw(20);
                //}

                //cout << left << setw(50) << " итого: " << Total << "р" << endl;
            }
        }



        //cout << "\nНажмите на любую клавишу для выхода в гланое меню...";

       /* while (true) {
            if (_kbhit()) {
                system("cls");
                mainPage();
                break;
            }
        }*/
    }

    //////////////////////////////////////////////////////////


    fstream& editDetailByNameAlg(fstream& out) {
        string DetailNameToEdit;
        //getInfo(DetailNameToEdit, "Введите название детали которую вы хотите изменить: ");
        DetailNameToEdit = convertToLowerCase(DetailNameToEdit);
        //if (DetailNameToEdit.empty())
        //{
        //    cout << "Ошибка: ничего не было введено...\n";
        //    askToGoToMainMenu();
        //    return out;
        //}
        out.clear();
        for (Detail element : DetailList) {
            if (convertToLowerCase(element.Name) != DetailNameToEdit)
            {
                out << element.id << ',' << element.Name << ',' << element.costs << endl;
            }
            else
            {
                string newName;
                //getInfo(newName, "Введите новое название детали: ");

                if (!newName.empty()) {

                    string newCostStr;
                    bool isGood = true;
                    do
                    {
                        isGood = true;
                        //getInfoWithoutChoise(newCostStr, "\nВведите новую стоимость детали : ");
                        // валидация
                        //if (!is_number(newCostStr))
                        //{
                        //    cout << "\nОшибка ввода, было введено не числовое значение..." << "\nПовторите попытку:\n";
                        //    continue;
                        //}
                        //else if (newCostStr.empty())
                        //{
                        //    cout << "\nОшибка ввода, ничего не было введено..." << "\nПовторите попытку:\n";
                        //    continue;
                        //}
                        //if (stod(newCostStr) < 0) {
                        //    cout << "Ошибка: Стоимость не может быть отрицательной...\n" << "\nПовторите попытку:\n";
                        //    isGood = false;
                        //}
                        //else if (stod(newCostStr) == 0)
                        //{
                        //    cout << "Ошибка: Не может быть бесплатного товара...\n" << "\nПовторите попытку:\n";
                        //    isGood = false;
                        //}

                    } while (!is_number(newCostStr) || newCostStr.empty() || !isGood);
                    double newCost = stod(newCostStr);
                    if (newCost != 0)
                    {
                        //cout << "Деталь " << element.Name << " Была успешно редактирована\n"
                        //    << "(Теперь она имеет название " << newName
                        //    << " и стоит " << newCost << "р за штуку\n";
                        Detail newDetail;
                        newDetail.id = element.id;
                        newDetail.costs = newCost;
                        newDetail.Name = newName;

                        DetailsNameMap.erase(element.Name);
                        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
                            if (it->Name == DetailNameToEdit) {
                                DetailList.erase(it);
                                break;
                            }
                        }

                        DetailList.push_back(newDetail);
                        DetailsNameMap[newName] = newDetail;



                        out << element.id << ',' << newName << ',' << newCost << endl;
                    }
                }
                else {
                    //cout << "Ошибка: Новое название не было введено...\n";
                    out << element.id << ',' << element.Name << ',' << element.costs << endl;
                }
            }
        }

        return out;
    }

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
    /*
     fstream& editDetailsInfoByOldName(int collumnIndex, int rowIndex, string newValue) {
        std::fstream OldDetailFile("DetailSpisok.csv", std::ios::in | std::ios::out);

        string oldName = DetailList.at(rowIndex).Name;

        Detail curDetail = DetailList.at(rowIndex);

        string curDetailsId = std::to_string(curDetail.id);
        string curDetailsName = curDetail.Name;
        string curDetailsCost = std::to_string(curDetail.costs);

        if (collumnIndex == 0) {
            curDetailsId = newValue;
        }
        else if (collumnIndex == 1) {
            curDetailsName = newValue;
        }
        else if (collumnIndex == 2) {
            curDetailsCost = newValue;
        }

        std::string line;
        int lineNumber = 0;
        while (std::getline(OldDetailFile, line)) {
            lineNumber++;

            // Split the line into id, name, and cost
            std::istringstream iss(line);
            std::string id, currentName, cost;
            if (std::getline(iss, id, ',') && std::getline(iss, currentName, ',') && std::getline(iss, cost)) {
                // Check if the name matches the old name
                if (currentName == oldName) {
                    // Clear the line
                    line.clear();

                    // Fill the line with new data
                    line = curDetailsId + "," + curDetailsName + "," + curDetailsCost + "\n";

                    // Replace the current line with the new line
                    OldDetailFile.seekp(OldDetailFile.tellg() - static_cast<std::streamoff>(line.length()) - static_cast<std::streamoff>(1));
                    OldDetailFile << line;

                    // Exit the loop
                    break;
                }
            }
        }

        if (collumnIndex == 0) {
            DetailList.at(rowIndex).id = stoi(newValue);
        }
        else if (collumnIndex == 1) {
            DetailList.at(rowIndex).Name = newValue;
        }
        else if (collumnIndex == 2) {
            DetailList.at(rowIndex).costs = stod(newValue);
        }

        // Close the file
        OldDetailFile.close();

        return OldDetailFile;
    }
    */

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
    void editDetailByName() {
        fstream File;
        File.open(DetailFileName);
        editDetailByNameAlg(File);
        //askToGoToMainMenu();
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


    /*
    *     ofstream& removeDetailById(int elementIndexToDelete) {
        int idToDelete = DetailList.at(elementIndexToDelete).id;
        ofstream UpgradedDetailFile;
        UpgradedDetailFile.open("DetailSpisok.csv");

        // Удаляем элемент из DetailList и DetailsNameMap
        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
            if (it->id == idToDelete) {
                DetailsNameMap.erase(it->Name);
                DetailList.erase(it);
                break;
            }
        }

        // Сортируем оставшиеся элементы
        vector<Detail> sortedDetailList = sortDetailsById(DetailList);

        // Записываем оставшиеся элементы в файл
        for (Detail element : sortedDetailList) {
            UpgradedDetailFile << element.id << ',' << element.Name << ',' << element.costs << endl;
        }

        return UpgradedDetailFile;
    }
    */

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
    void removeDetailById(int elementIndexToDelete) {
        int idToDelete = DetailList.at(elementIndexToDelete).id;

        // Удаляем элемент из DetailList и DetailsNameMap
        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
            if (it->id == idToDelete) {
                DetailsNameMap.erase(it->Name);
                DetailList.erase(it);
                break;
            }
        }
    }

    void removeEquipmentById(int elementIndexToDelete) {
        int idToDelete = EquipmentList.at(elementIndexToDelete).id;

        for (auto it = EquipmentList.begin(); it != EquipmentList.end(); ++it) {
            if (it->id == idToDelete) {
                EquipmentNameMap.erase(it->Name);
                EquipmentList.erase(it);
                break;
            }
        }
    }

    /*
    *     ofstream& removeDetailById(int elementIndexToDelete) {
        int idToDelete = DetailList.at(elementIndexToDelete).id;
        ofstream UpgradedDetailFile;
        UpgradedDetailFile.open("DetailSpisok.csv");

        // Удаляем элемент из DetailList и DetailsNameMap
        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
            if (it->id == idToDelete) {
                DetailsNameMap.erase(it->Name);
                DetailList.erase(it);
                break;
            }
        }

        // Сортируем оставшиеся элементы
        vector<Detail> sortedDetailList = sortDetailsById(DetailList);

        // Записываем оставшиеся элементы в файл
        for (Detail element : sortedDetailList) {
            UpgradedDetailFile << element.id << ',' << element.Name << ',' << element.costs << endl;
        }

        return UpgradedDetailFile;
    }
    */

    fstream& removeDetailByNameAlg(fstream& out) {
        string DetailNameToEdit;
        sort(DetailList.begin(), DetailList.end(), [](Detail a, Detail b) {
            return a.id < b.id;
            });

        //cout << left << "|" << "Id детали"
        //    << "|" << setw(30) << "Название детали"
        //    << "|" << "Стоимость детали, р/шт" << "|" << endl;
        //;

        //for (Detail element : DetailList)
        //{

        //    cout << left
        //        << "|" << setw(9) << element.id
        //        << "|" << setw(30) << element.Name
        //        << "|" << setw(22) << element.costs << "|" << endl;
        //}

        //getInfo(DetailNameToEdit, "Введите название детали которую вы хотите удалить: ");

        vector<Detail> detailsMarkedToRemove;


        if (DetailNameToEdit.empty())
        {

            for (Detail element : DetailList) {
                out << element.id << ',' << element.Name << ',' << element.costs << endl;
            }
            return out;
        }
        out.clear();
        try
        {
            for (Detail element : DetailList) {
                if (containsSubString(element.Name, DetailNameToEdit))
                {
                    detailsMarkedToRemove.push_back(element);
                }
            }
            if (detailsMarkedToRemove.size() == 0)
            {
                //cout << "Ошибка: такого элемента уже нет...\n";
                return out;
            }
            /*cout << "Преценденты на удаление: \n";
            for (int i = 0; i < detailsMarkedToRemove.size(); i++) {
                int index = i + 1;
                cout << left << index << ")"
                    << setw(5) << detailsMarkedToRemove.at(i).id
                    << setw(20) << detailsMarkedToRemove.at(i).Name
                    << setw(20) << detailsMarkedToRemove.at(i).costs
                    << endl;

            }*/
        }
        catch (const std::out_of_range& e)
        {
            //cout << "\nПроизошла ошибка обработки\n";
            for (Detail element : DetailList) {
                out << element.id << ',' << element.Name << ',' << element.costs << endl;
            }
            return out;
        }
        string idToDelete;
        bool isCompleate = false;////
        do
        {
            //getInfo(idToDelete, "\nВведите id детали, которую вы хотите удалить: ");
            //валидация
            /*if (!is_number(idToDelete))
            {
                cout << "\nОшибка ввода, было введено не числовое значение...";
            }*/
            for (Detail element : detailsMarkedToRemove) {
                if (element.id == stoi(idToDelete))
                {
                    isCompleate = true;
                    break;
                }
            }
            //if (!isCompleate)
            //{
            //    cout << "\nОшибка ввода, было введено несуществующее значение id...";
            //}
        } while (!is_number(idToDelete) || !isCompleate);




        for (Detail element : DetailList) {
            if (element.id == stoi(idToDelete))
            {
                DetailsNameMap.erase(element.Name);
                //cout << "\nДеталь " << element.Name << " была успешно удалена\n";
                break;
            }
        }

        for (auto it = DetailList.begin(); it != DetailList.end(); ++it) {
            if (it->id == stoi(idToDelete)) {
                DetailList.erase(it);
                break;
            }
        }

        for (Detail element : DetailList) {
            out << element.id << ',' << element.Name << ',' << element.costs << endl;
        }
        return out;
    }

    void removeDetailByName() {
        fstream File;
        File.open(DetailFileName, std::ios_base::out | std::ios_base::trunc);
        removeDetailByNameAlg(File);
        //askToGoToMainMenu();
    }
    fstream& addDetailByNameAlg(fstream& out) {
        out.clear();

        for (Detail element : DetailList)
        {
            out << element.id << ',' << element.Name << ',' << element.costs << endl;
        }

        string newName;
        //getInfo(newName, "Введите название новой детали: ");
        //валидация
        //if (newName.empty()) {
        //    cout << "Ошибка: ничего не было введено...";
        //    return out;
        //}



        //for (Detail element : DetailList)
        //{
        //    if (element.Name == newName)
        //    {
        //        cout << "Такая деталь уже существует...\n";
        //        return out;
        //    }
        //}


        string newCost;

        //ввод
        //do
        //{
        //    getInfoWithoutChoise(newCost, "\nВведите стоимость новой детали : ");
        //    if (!is_number(newCost))
        //    {
        //        cout << "\nОшибка ввода, было введено не числовое значение..." << "\nПовторите попытку:\n";
        //    }
        //    else if (newCost.empty())
        //    {
        //        cout << "\nОшибка ввода, ничего не было введено..." << "\nПовторите попытку:\n";
        //    }

        //} while (!is_number(newCost) || newCost.empty());


        DetailCount++;

        Detail newDetail;
        auto itSize = DetailList.end() - 1;
        int size = itSize->id;
        string newIdStr = to_string(++size);
        newDetail.id = stoi("1" + newIdStr);
        int newId = stoi("1" + newIdStr);
        newDetail.Name = newName;
        newDetail.costs = stod(newCost);

        out << newId << ',' << newName << ',' << newCost << endl;
        DetailList.push_back(newDetail);
        DetailsNameMap[newName] = newDetail;
        //cout << "Деталь " << newName << " успешно добавлена\n";
        return out;
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

    //fstream& addDetailByNameAlg(fstream& out) {
    //    out.clear();

    //    for (Detail element : DetailList)
    //    {
    //        out << element.id << ',' << element.Name << ',' << element.costs << endl;
    //    }

    //    string newName;
    //    //getInfo(newName, "Введите название новой детали: ");
    //    //валидация
    //    //if (newName.empty()) {
    //    //    cout << "Ошибка: ничего не было введено...";
    //    //    return out;
    //    //}



    //    //for (Detail element : DetailList)
    //    //{
    //    //    if (element.Name == newName)
    //    //    {
    //    //        cout << "Такая деталь уже существует...\n";
    //    //        return out;
    //    //    }
    //    //}


    //    string newCost;
    //     
    //    //ввод
    //    //do
    //    //{
    //    //    getInfoWithoutChoise(newCost, "\nВведите стоимость новой детали : ");
    //    //    if (!is_number(newCost))
    //    //    {
    //    //        cout << "\nОшибка ввода, было введено не числовое значение..." << "\nПовторите попытку:\n";
    //    //    }
    //    //    else if (newCost.empty())
    //    //    {
    //    //        cout << "\nОшибка ввода, ничего не было введено..." << "\nПовторите попытку:\n";
    //    //    }

    //    //} while (!is_number(newCost) || newCost.empty());


    //    DetailCount++;

    //    Detail newDetail;
    //    auto itSize = DetailList.end() - 1;
    //    int size = itSize->id;
    //    string newIdStr = to_string(++size);
    //    newDetail.id = stoi("1" + newIdStr);
    //    int newId = stoi("1" + newIdStr);
    //    newDetail.Name = newName;
    //    newDetail.costs = stod(newCost);

    //    out << newId << ',' << newName << ',' << newCost << endl;
    //    DetailList.push_back(newDetail);
    //    DetailsNameMap[newName] = newDetail;
    //    //cout << "Деталь " << newName << " успешно добавлена\n";
    //    return out;
    //}

    //void addDetailByName() {
    //    fstream File;
    //    File.open(DetailFileName, std::ios_base::out | std::ios_base::trunc);
    //    addDetailByNameAlg(File);
    //    //askToGoToMainMenu();
    //}

    /////////////////////////////////////////////////////////// 

    ofstream& editEquipmentByNameAlg(ofstream& out) {
        string EquipmentNameToEdit;
        //getInfo(EquipmentNameToEdit, "Введите название оборудования, которое вы хотите изменить: ");

        if (EquipmentNameToEdit.empty())
        {
            for (Equipment element : EquipmentList) {
                out << element.id << ',' << element.Name;

                for (const auto& curEquipsDetail : element.DetailsCount) {
                    out << ',' << curEquipsDetail.first << ',' << curEquipsDetail.second;
                }

                out << endl;
            }
            return out;
        }

        int isExist = 0;
        for (Equipment element : EquipmentList) {
            if (element.Name == EquipmentNameToEdit) {
                ++isExist;
                break;
            }
        }
        //if (isExist == 0)
        //{
        //    cout << "Ошибка: такого оборудования нет в списке...\n";
        //    return out;
        //}
        out.clear();
        int iteratorCounter = 0;
        for (Equipment element : EquipmentList) {
            if (element.Name != EquipmentNameToEdit && !element.Name.empty())
            {
                iteratorCounter++;
            }
            else
            {
                Equipment editingEquip;
                int id = element.id;
                string newName;
                //cout << "Введите новое название оборудования: ";

                //getline(cin, newName);

                editingEquip.id = id;
                editingEquip.Name = newName;
                vector<Equipment>::iterator it = EquipmentList.begin();
                if (!newName.empty()) {
                    it += iteratorCounter;
                }

                if (!newName.empty()) {
                    EquipmentList.erase(it);
                    int counter = 0;
                    while (true)
                    {
                        string newEquipmentsDetail;

                        //getInfoWithoutChoise(newEquipmentsDetail, "Введите название делали или нажмите Enter, если вы добавили достаточно деталей: ");
                       /* if (newEquipmentsDetail.empty()) {
                            cout << "\nОборудование " << element.Name << " было успешно изменено...\n";
                            break;
                        }*/
                        string newDetailsCount;
                        bool isGood = true;
                        do
                        {
                            isGood = true;
                            //getInfoWithoutChoise(newDetailsCount, "\nВведите новое требуемое количество делалей : ");
                            //валидация
                            /*if (!is_number(newDetailsCount))
                            {
                                cout << "\nОшибка ввода, было введено не числовое значение..." << "\nПовторите попытку:\n";
                                continue;
                            }
                            else if (newDetailsCount.empty())
                            {
                                cout << "\nОшибка ввода, ничего не было введено..." << "\nПовторите попытку:\n";
                                continue;
                            }
                            if (stoi(newDetailsCount) < 0) {
                                cout << "Ошибка: Количество не может быть отрицательным...\n" << "\nПовторите попытку:\n";
                                isGood = false;
                            }
                            else if (stoi(newDetailsCount) == 0)
                            {
                                cout << "Ошибка: Количество не может быть  нулевым...\n" << "\nПовторите попытку:\n";
                                isGood = false;
                            }*/

                        } while (!is_number(newDetailsCount) || newDetailsCount.empty() || !isGood);

                        int newEquipmentsDetailsCount = stoi(newDetailsCount);
                        //////////////
                        if (newEquipmentsDetailsCount > 0)
                        {
                            counter++;
                            editingEquip.DetailsCount[newEquipmentsDetail] = newEquipmentsDetailsCount;
                        }
                    }

                    /*if (counter == 0)
                    {
                        cout << "Было изменено только имя оборудования...\n";
                    }*/

                    EquipmentNameMap.erase(element.Name);
                    EquipmentNameMap[editingEquip.Name] = editingEquip;
                    EquipmentList.push_back(editingEquip);
                }
                /*else {
                    cout << "Ошибка: Новое название не было введено...\n";
                }*/


            }
        }
        for (Equipment element : EquipmentList) {
            out << element.id << ',' << element.Name;

            for (const auto& curEquipsDetail : element.DetailsCount) {
                out << ',' << curEquipsDetail.first << ',' << curEquipsDetail.second;
            }

            out << endl;
        }

        return out;
    }

    void editEquipmentByName() {
        ofstream File;
        File.open(EquipmentFileName, std::ios_base::out | std::ios_base::trunc);
        editEquipmentByNameAlg(File);
        //askToGoToMainMenu();
    }

    ofstream& addEquipmentByNameAlg(ofstream& out) {

        for (Equipment element : EquipmentList) {
            out << element.id << ',' << element.Name;

            for (const auto& curEquipsDetail : element.DetailsCount) {
                out << ',' << curEquipsDetail.first << ',' << curEquipsDetail.second;
            }

            out << endl;
        }

        Equipment editingEquip;

        string newName;
        //getInfo(newName, "Введите название нового оборудования: ");
        //валидация
        /*if (newName.empty())
        {
            cout << "\nОшибка: ничего не было введено...\n";
            return out;
        }*/
        int size = EquipmentList.size();
        editingEquip.id = ++size;
        editingEquip.Name = newName;

        if (!newName.empty()) {
            int counter = 0;
            while (true)
            {
                string newEquipmentsDetail;
                //cout << "Введите название делали или нажмите Enter, если вы добавили достаточно деталей: ";
                bool is_newEquipmentsDetail_Correct = true;
                do
                {
                    //валидация
                    //getline(cin, newEquipmentsDetail);
                    //if (newEquipmentsDetail.size() == 0) {
                    //    cout << "\nОшибка: Ничего не было введено"
                    //        << "\nВыберете пункт:"
                    //        << "\n1.Закончить добавление деталей"
                    //        << "\n2.Ввести название детали еще раз";

                    //    while (true) {
                    //        if (_kbhit()) {
                    //            char ch = _getch();
                    //            if (ch == 49) { //1
                    //                cout << endl;
                    //                newEquipmentsDetail = "";
                    //                is_newEquipmentsDetail_Correct = false;
                    //                break;
                    //            }
                    //            else if (ch == 50) { //2
                    //                cout << endl << "Введите название делали или нажмите Enter, если вы добавили достаточно деталей: ";
                    //                break;
                    //            }
                    //        }
                    //    }

                    //}
                    //else if (newEquipmentsDetail.size() > 30) {
                    //    cout << "\nОшибка: Слишком большой ввод"
                    //        << "\nВыберете пункт:"
                    //        << "\n1.Закончить добавление деталей"
                    //        << "\n2.Ввести название детали еще раз";

                    //    while (true) {
                    //        if (_kbhit()) {
                    //            char ch = _getch();
                    //            if (ch == 49) { //1
                    //                cout << endl;
                    //                newEquipmentsDetail = "";
                    //                is_newEquipmentsDetail_Correct = false;
                    //                break;
                    //            }
                    //            else if (ch == 50) { //2
                    //                cout << endl << "Введите название делали или нажмите Enter, если вы добавили достаточно деталей: ";
                    //                break;
                    //            }
                    //        }
                    //    }
                    //}
                    //else if (newEquipmentsDetail.size() < 30)
                    //{
                    //    break;
                    //}
                } while (is_newEquipmentsDetail_Correct);
                /*if (newEquipmentsDetail.empty()) {
                    cout << "\nОборудование " << newName << " было успешно добавлено...\n";
                    break;
                }*/
                string newEquipmentsDetailsCountStr;
                bool isGood = true;
                do
                {
                    isGood = true;
                    //валидация
                    //getInfoWithoutChoise(newEquipmentsDetailsCountStr, "\nВведите новое требуемое количество делалей: ");
                    /*if (!is_number(newEquipmentsDetailsCountStr))
                    {
                        cout << "\nОшибка ввода, было введено не числовое значение..." << "\nПовторите попытку:\n";
                        continue;
                    }
                    else if (newEquipmentsDetailsCountStr.empty())
                    {
                        cout << "\nОшибка ввода, ничего не было введено..." << "\nПовторите попытку:\n";
                        continue;
                    }
                    if (stoi(newEquipmentsDetailsCountStr) < 0) {
                        cout << "Ошибка: Количество не может быть отрицательным...\n";
                        cout << "\nПожалуйста повторите попытку";
                        isGood = false;
                    }
                    else if (stoi(newEquipmentsDetailsCountStr) == 0)
                    {
                        cout << "Ошибка: Количество не может быть нулевым...\n";
                        cout << "\nПожалуйста повторите попытку";
                        isGood = false;
                    }
                    else if (stoi(newEquipmentsDetailsCountStr) >= 2147483647)
                    {
                        cout << "\nОшибка: введенное количество слишком большое";
                        cout << "\nПожалуйста повторите попытку";
                    }*/

                } while (!is_number(newEquipmentsDetailsCountStr) || newEquipmentsDetailsCountStr.empty() || !isGood);

                int newEquipmentsDetailsCount = stoi(newEquipmentsDetailsCountStr);

                if (newEquipmentsDetailsCount > 0)
                {
                    counter++;
                    editingEquip.DetailsCount[newEquipmentsDetail] = newEquipmentsDetailsCount;
                }
            }

            //if (counter == 0)
            //{
            //    cout << "Было изменено только имя оборудования...\n";
            //}

            EquipmentNameMap[editingEquip.Name] = editingEquip;
            EquipmentList.push_back(editingEquip);
        }
        //else {
        //    cout << "Ошибка: Новое название не было введено...\n";
        //}
        out << editingEquip.id << ',' << editingEquip.Name;

        for (const auto& curEquipsDetail : editingEquip.DetailsCount) {
            out << ',' << curEquipsDetail.first << ',' << curEquipsDetail.second;
        }

        out << endl;

        return out;
    }

    void addEquipmentByName() {
        ofstream File;
        File.open(EquipmentFileName, std::ios_base::out | std::ios_base::trunc);
        addEquipmentByNameAlg(File);
        //askToGoToMainMenu();
    }

    ofstream& removeEquipmentByNameAlg(ofstream& out) {

        string newName;
        //cout << "Введите название оборудования, которое вы хотите удалить: ";

        //getInfo(newName, "Введите название оборудования, которое вы хотите удалить: ");
        //валидация
        //if (newName.empty())
        //{
        //    cout << "Ошибка: ничего не было введено...\n";
        //    return out;
        //}
        vector<Equipment>::iterator it = EquipmentList.begin();
        int iteratorCounter = 0;
        for (Equipment element : EquipmentList) {
            if (newName != element.Name) {
                iteratorCounter++;
            }
            else {
                break;
            }
        }
        it += iteratorCounter;
        EquipmentNameMap.erase(newName);
        EquipmentList.erase(it);

        for (Equipment element : EquipmentList) {

            out << element.id << ',' << element.Name;

            for (const auto& curEquipsDetail : element.DetailsCount) {
                out << ',' << curEquipsDetail.first << ',' << curEquipsDetail.second;
            }

            out << endl;
        }

        return out;
    }

    void removeEquipmentByName() {
        ofstream File;
        File.open(EquipmentFileName, std::ios_base::out | std::ios_base::trunc);
        removeEquipmentByNameAlg(File);
        //askToGoToMainMenu();
    }
};