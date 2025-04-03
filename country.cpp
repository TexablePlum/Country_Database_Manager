#include "Country.h"

using namespace std;

// Dodaje kraj do bazy danych
void Country::add() {
    cout << "Podaj nazw� kraju: ";
    cin.ignore();
    getline(cin, name);
    cout << "Podaj nazw� stolicy: ";
    getline(cin, capital);
    cout << "Podaj nazw� kontynentu: ";
    getline(cin, continent);
    cout << "Podaj organizacje mi�dzynarodowe oddzielone przecinkami (bez spacji pomi�dzy nimi): ";
    string orgs;
    getline(cin, orgs);
    stringstream ss(orgs);
    string org;
    while (getline(ss, org, ',')) {
        organizations.insert(org);
    }
    cout << "Kraj zosta� dodany do bazy danych!" << endl;
}

// W zaleznosci od przeslanej decyzji, funkcja edytuje wskazane pole
void Country::edit(char choice) {
    cout << endl;
    cin.ignore();
    if (choice == '1') {
        cout << "Podaj now� nazw� kraju (" << name << "): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            name = newName;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo�e by� pusta!" << endl;
        }
    }
    else if (choice == '2') {
        cout << "Podaj now� nazw� stolicy (" << capital << "): ";
        string newCapital;
        getline(cin, newCapital);
        if (!newCapital.empty()) {
            capital = newCapital;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo�e by� pusta!" << endl;
        }
    }
    else if (choice == '3') {
        cout << "Podaj now� nazw� kontynentu (" << continent << "): ";
        string newContinent;
        getline(cin, newContinent);
        if (!newContinent.empty()) {
            continent = newContinent;
            cout << "Zaaktualizowano dane!" << endl;
        }
        else {
            cout << "Nazwa nie mo�e by� pusta!" << endl;
        }
    }
    else if (choice == '4') {
        cout << "Podaj nowe organizacje mi�dzynarodowe oddzielone przecinkami (bez spacji pomi�dzy nimi): ";
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
        cout << "Nieznany wyb�r!\n";
    }
}
