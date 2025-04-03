#include "CountryDatabase.h"

using namespace std;

// Dodaje nowy kraj do bazy danych lub aktualizuje istniejacy wpis
void CountryDatabase::addCountry(Country country) {
    countries[country.name] = country;
}

// Metoda sluzaca do pobrania informacji o kraju
Country CountryDatabase::getCountry(string countryName) {
    return countries[countryName];
}

// Odczytuje linijka po linijce informacje z pliku, wstawia je do obiektu Country, a nastepnie dodaje do bazy danych
void CountryDatabase::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Nie mo¿na otworzyæ pliku!" << endl;
        return;
    }

    string line;
    Country current_country;
    while (getline(file, line)) {
        if (line.empty()) {
            // Dodaje biezacy kraj do bazy danych
            addCountry(current_country);

            // Reset biezacego kraju
            current_country = Country();
        }
        else {
            if (current_country.name.empty()) {
                current_country.name = line;
            }
            else if (current_country.capital.empty()) {
                current_country.capital = line;
            }
            else if (current_country.continent.empty()) {
                current_country.continent = line;
            }
            else {
                // Podziel linijke na poszczegolne organizacje i dodaj je do biezacego kraju
                stringstream ss(line);
                string org;
                while (getline(ss, org, ',')) {
                    // Dodaj organizacje do biezacego kraju
                    current_country.organizations.insert(org);
                }
            }
        }
    }
    // Dodaj ostatni kraj do bazy danych
    addCountry(current_country);
    file.close();
}

// Wyœwietla informacje o panstwach znajdujacych sie w mapie countries
void CountryDatabase::printAllCountries() {
    auto it = countries.find("");
    if (it != countries.end())
        countries.erase(it);
    for (auto& i : countries) {
        Country country = i.second;
        cout << "Pañstwo: " << country.name << endl;
        cout << "Stolica: " << country.capital << endl;
        cout << "Kontynent: " << country.continent << endl;
        cout << "Organizacje miêdzynarodowe: " << endl;
        for (string organization : country.organizations) {
            cout << "- " << organization << endl;
        }
        cout << endl;
    }
}

// Zwraca prawde jesli podane panstwo znajduje sie na podanym kontynencie z bazy danych
bool CountryDatabase::isCountryOnContinent(string countryName, string continentName) {
    Country country = countries[countryName];
    return (country.continent == continentName);
}

// Zwraca prawde jesli podana nazwa miasta jest stolica podanego panstwa z bazy danych
bool CountryDatabase::isCityCapitalOfCountry(string cityName, string countryName) {
    Country country = countries[countryName];
    return (country.capital == cityName);
}

// Zwraca prawde jesli w podanym panstwie znajduje sie podana organizacja miedzynarodowa z bazy danych
bool CountryDatabase::isCountryInOrganization(string countryName, string organizationName) {
    Country country = countries[countryName];
    return (country.organizations.find(organizationName) != country.organizations.end());
}

// Zapisuje informacje z mapy countries do pliku tekstowego
void CountryDatabase::saveToFile(string filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Nie mo¿na otworzyæ pliku!" << endl;
        return;
    }

    for (auto& i : countries) {
        Country country = i.second;
        file << country.name << endl;
        file << country.capital << endl;
        file << country.continent << endl;
        for (string organization : country.organizations) {
            file << organization << ",";
        }
        auto last = countries.end();
        --last; // Przesuniecie iteratora na ostatni element
        if (i.first != last->first) {
            file << endl << endl; // Dodawaj dodatkowe puste linie na koncu segmmentu
        }
    }
    file.close();
}

// Jesli podana nazwa kraju znajduje siê w mapie countries to go usuwa wraz z jego informacjami
void CountryDatabase::deleteCountry() {
    cout << "Podaj nazwê kraju do usuniêcia: ";
    string name;
    cin >> name;

    if (countries.find(name) != countries.end()) {
        countries.erase(name);
        cout << "Kraj zosta³ usuniêty z bazy danych!" << endl;
    }
    else {
        cout << "Nie ma kraju o takiej nazwie w bazie danych!" << endl;
    }
}

// Metoda sluzaca do edycji informacji o kraju w bazie danych
void CountryDatabase::editData() {
    string countryName;
    cout << "Podaj nazwê kraju, który chcesz edytowaæ: ";
    cin >> countryName;

    if (countries.find(countryName) != countries.end()) {
        Country& country = countries[countryName];
        cout << "Opcje edycji: 1 - nazwa | 2 - stolica | 3 - kontynent | 4 - organizacje\nOpcja: ";
        char choice;
        choice = _getch();
        country.edit(choice);
        if (choice == '1') {
            saveToFile("database.txt");
            countries.clear();
            loadFromFile("database.txt");
        }
    }
    else {
        cout << "Nie ma kraju o takiej nazwie w bazie danych!" << endl;
    }
}