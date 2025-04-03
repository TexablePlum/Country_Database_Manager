#pragma once

#include "Country.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <locale>
#include <sstream>
#include <conio.h>

using namespace std;

/**
 * @brief Klasa reprezentujaca baze danych krajow.
 *
 * Klasa CountryDatabase dziedziczy po klasie Country i reprezentuje baze danych
 * zawierajaca informacje o roznych krajach. Udostepnia metody do dodawania, pobierania,
 * wczytywania, drukowania i modyfikowania danych dotyczacych krajow.
 */
class CountryDatabase : public Country {
private:
    map<string, Country> countries; /**< Mapa przechowujaca kraje, gdzie kluczem jest nazwa kraju. */
public:
    /**
     * @brief Dodaje kraj do bazy danych.
     *
     * @param country Kraj do dodania.
     */
    void addCountry(Country country);

    /**
     * @brief Pobiera kraj o podanej nazwie.
     *
     * @param countryName Nazwa kraju.
     * @return Kraj o podanej nazwie lub pusty kraj, jesli nie znaleziono pasujacego kraju.
     */
    Country getCountry(string countryName);

    /**
     * @brief Wczytuje dane krajow z pliku.
     *
     * @param filename Nazwa pliku.
     */
    void loadFromFile(string filename);

    /**
     * @brief Wyswietla wszystkie kraje z bazy danych.
     */
    void printAllCountries();

    /**
     * @brief Sprawdza, czy kraj o podanej nazwie nalezy do okreslonego kontynentu.
     *
     * @param countryName Nazwa kraju.
     * @param continentName Nazwa kontynentu.
     * @return Wartosc logiczna - true, jesli kraj nalezy do kontynentu, false w przeciwnym razie.
     */
    bool isCountryOnContinent(string countryName, string continentName);

    /**
     * @brief Sprawdza, czy podane miasto jest stolica podanego kraju.
     *
     * @param cityName Nazwa miasta.
     * @param countryName Nazwa kraju.
     * @return Wartosc logiczna - true, jesli miasto jest stolica kraju, false w przeciwnym razie.
     */
    bool isCityCapitalOfCountry(string cityName, string countryName);

    /**
     * @brief Sprawdza, czy kraj o podanej nazwie nalezy do okreslonej organizacji.
     *
     * @param countryName Nazwa kraju.
     * @param organizationName Nazwa organizacji.
     * @return Wartosc logiczna - true, jesli kraj nalezy do organizacji, false w przeciwnym razie.
     */
    bool isCountryInOrganization(string countryName, string organizationName);

    /**
     * @brief Zapisuje dane krajow do pliku.
     *
     * @param filename Nazwa pliku.
     */
    void saveToFile(string filename);

    /**
     * @brief Usuwa kraj z bazy danych.
     */
    void deleteCountry();

    /**
     * @brief Edytuje dane krajow w bazie danych.
     */
    void editData();
};
