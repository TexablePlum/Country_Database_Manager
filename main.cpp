#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <locale>
#include <sstream>
#include <conio.h>
#include "CountryDatabase.h"

using namespace std;

/**
 * @brief Funkcja obslugujaca menu i komunikacje z uzytkownikiem.
 *
 * Funkcja wyswietla menu i oczekuje na wybor uzytkownika.
 * Na podstawie wyboru wykonuje odpowiednie operacje na bazie danych.
 *
 * @param database Referencja do obiektu bazy danych.
 */

void obsluga_switcha(CountryDatabase& database) {
    string name, property;
    char choice;
    do {
        database.loadFromFile("database.txt");
        cout << "Menu:" << endl;
        cout << "1. Sprawdz czy kraj nalezy do kontynentu" << endl;
        cout << "2. Sprawdz czy miasto jest stolica danego kraju" << endl;
        cout << "3. Sprawdz czy kraj nalezy do organizacji" << endl;
        cout << "4. Dodaj nowe panstwo" << endl;
        cout << "5. Usun wybrane panstwo" << endl;
        cout << "6. Edytuj dane panstwo" << endl;
        cout << "7. Wyswietl dane" << endl;
        cout << "0. Zakoncz dzialanie programu" << endl;

        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case '1':
            system("cls");
            cout << "Podaj nazwe kraju: ";
            cin.ignore();
            getline(cin, name);
            cout << "Podaj nazwe kontynentu: ";
            getline(cin, property);
            if (name == "" || property == "")
            {
                cout << "Podano pusta wartosc!\n";
                break;
            }
            if (database.isCountryOnContinent(name, property)) {
                cout << name << " nalezy do kontynentu: " << property << endl;
            }
            else {
                cout << name << " nie nalezy do kontynentu: " << property << endl;
            }
            break;

        case '2':
            system("cls");
            cout << "Podaj nazwe miasta: ";
            cin.ignore();
            getline(cin, property);
            cout << "Podaj nazwe kraju: ";
            getline(cin, name);
            if (name == "" || property == "")
            {
                cout << "Podano pusta wartosc!\n";
                break;
            }
            if (database.isCityCapitalOfCountry(property, name)) {
                cout << property << " jest stolica kraju " << name << endl;
            }
            else {
                cout << property << " nie jest stolica kraju " << name << endl;
            }
            break;

        case '3':
            system("cls");
            cout << "Podaj nazwe kraju: ";
            cin.ignore();
            getline(cin, name);
            cout << "Podaj nazwe organizacji miedzynarodowej: ";
            getline(cin, property);
            if (name == "" || property == "")
            {
                cout << "Podano pusta wartosc!\n";
                break;
            }
            if (database.isCountryInOrganization(name, property)) {
                cout << name << " nalezy do organizacji miedzynarodowej " << property << endl;
            }
            else {
                cout << name << " nie nalezy do organizacji miedzynarodowej " << property << endl;
            }
            break;

        case '4':
        {
            system("cls");
            Country country;
            country.add();
            database.addCountry(country);
            database.saveToFile("database.txt");
            break;
        }

        case '5':
        {
            system("cls");
            database.deleteCountry();
            database.saveToFile("database.txt");
            break;
        }

        case '6':
        {
            system("cls");
            database.editData();
            database.saveToFile("database.txt");
            break;
        }

        case '7':
            system("cls");
            // Pokaz informacje o wszystkich krajach
            database.printAllCountries();
            break;

        default:
            if (choice != '0')
            {
                cout << "Nieprawidlowy wybor opcji!" << endl;
                //system("cls");
            }
            else
                cout << "Zamykanie..." << endl;
            break;
        }
    } while (choice != '0');
}

/**
 * @brief Funkcja glowna programu.
 *
 * Funkcja inicjalizuje obiekt bazy danych i wywoluje funkcje obslugi switcha.
 *
 * @return Kod zakonczenia programu.
 */

int main()
{
    locale::global(locale("polish"));

    CountryDatabase database;

    obsluga_switcha(database);

    return 0;
}
