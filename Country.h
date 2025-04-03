#pragma once

#include "Editable.h"
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
 * @brief Klasa reprezentujaca kraj.
 *
 * Klasa Country dziedziczy po klasie Editable i reprezentuje informacje
 * o konkretnym kraju. Zawiera pola takie jak nazwa, stolica, kontynent
 * oraz zbior organizacji, do ktorych kraj nalezy.
 */
class Country : public Editable {
public:
    string name; /**< Nazwa kraju. */
    string capital; /**< Stolica kraju. */
    string continent; /**< Kontynent, na ktorym lezy kraj. */
    set<string> organizations; /**< Zbior organizacji, do ktorych kraj nalezy. */

    /**
     * @brief Konstruktor klasy Country.
     *
     * Konstruktor tworzy obiekt kraju z opcjonalnymi wartosciami dla
     * nazwy, stolicy, kontynentu i zbioru organizacji.
     *
     * @param name Nazwa kraju.
     * @param capital Stolica kraju.
     * @param continent Kontynent, na ktorym lezy kraj.
     * @param organizations Zbior organizacji, do ktorych kraj nalezy.
     */
    Country(string name = "", string capital = "", string continent = "", set<string> organizations = {})
        : name(name), capital(capital), continent(continent), organizations(organizations) {}

    // Implementacja metod interfejsu Editable
    void add() override;

    void edit(char choice) override;
};
