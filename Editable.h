#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <locale>
#include <sstream>
#include <conio.h>

/**
 * @brief Klasa abstrakcyjna reprezentujaca edytowalne elementy.
 *
 * Klasa Editable jest klasa abstrakcyjna, ktora definiuje interfejs dla
 * edytowalnych elementow. Elementy dziedziczace po tej klasie musza
 * implementowac metody add() oraz edit(char).
 */
class Editable {
public:
    /**
     * @brief Dodaje nowy element.
     *
     * Metoda czysto wirtualna, ktora musi byc zaimplementowana przez klasy
     * dziedziczace. Sluzy do dodawania nowego elementu.
     */
    virtual void add() = 0;

    /**
     * @brief Edytuje element o podanym identyfikatorze.
     *
     * Metoda czysto wirtualna, ktora musi byc zaimplementowana przez klasy
     * dziedziczace. Sluzy do edytowania istniejacego elementu o podanym
     * identyfikatorze.
     *
     * @param id Identyfikator elementu do edycji.
     */
    virtual void edit(char id) = 0;
};
