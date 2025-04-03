#include "Country.h"

using namespace std;

// Dodaje kraj do bazy danych
void Country::add() {
    cout << "Podaj nazwê kraju: ";
    cin.ignore();
    getline(cin, name);
    cout << "Podaj nazwê stolicy: ";
    getline(cin, capital);
    cout << "Podaj nazwê kontynentu: ";
    getline(cin, continent);
    cout << "Podaj organizacje miêdzynarodowe oddzielone przecinkami (bez spacji pomiêdzy nimi): ";
    string orgs;
    getline(cin, orgs);
    stringstream ss(orgs);
    string org;
    while (getline(ss, org, ',')) {
        organizations.insert(org);
    }
    cout << "Kraj zosta³ dodany do bazy danych!" << endl;
}

// W zaleznosci od przeslanej decyzji, funkcja edytuje wskazane pole
void Country::edit(char choice) {
    cout << endl;
    cin.ignore();
    if (choice == '1') {
        cout << "Podaj now¹ nazwê kraju (" << name << "): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            name = newName;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo¿e byæ pusta!" << endl;
        }
    }
    else if (choice == '2') {
        cout << "Podaj now¹ nazwê stolicy (" << capital << "): ";
        string newCapital;
        getline(cin, newCapital);
        if (!newCapital.empty()) {
            capital = newCapital;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo¿e byæ pusta!" << endl;
        }
    }
    else if (choice == '3') {
        cout << "Podaj now¹ nazwê kontynentu (" << continent << "): ";
        string newContinent;
        getline(cin, newContinent);
        if (!newContinent.empty()) {
            continent = newContinent;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo¿e byæ pusta!" << endl;
        }
    }
    else if (choice == '4') {
        cout << "Podaj nowe organizacje miêdzynarodowe oddzielone przecinkami (bez spacji pomiêdzy nimi): ";
        string newOrgs;
        getline(cin, newOrgs);
        if (!newOrgs.empty()) {
            organizations.clear();
            stringstream ss(newOrgs);
            string org;
            while (getline(ss, org, ',')) {
                organizations.insert(org);
            }
        }
        else {
            organizations.clear();
        }
        cout << "Zaaktualizowano dane!" << endl;
    }
    else {
        cout << "Nieznany wybór!\n";
    }
}
