# 🌍 Country Database Manager - Projekt Studencki

**Projekt bazy danych krajów** stworzony w ramach zajęć Informatyka i podstawy programowanie na pierwszym semestrze studiów informatycznych w 2022 roku. Aplikacja umożliwia zarządzanie informacjami o krajach, ich stolicach, kontynentach oraz organizacjach międzynarodowych w prosty i intuicyjny sposób.

---

## ✨ Funkcje

- **Dodawanie krajów** z pełnymi informacjami (nazwa, stolica, kontynent, organizacje).
- **Edycja i usuwanie** istniejących wpisów.
- **Sprawdzanie relacji** między krajami, miastami, kontynentami i organizacjami.
- **Zapis i odczyt danych** do/z pliku tekstowego.
- **Przejrzyste menu** z obsługą klawiszy numerycznych.

---

## 📦 Wymagania

- Kompilator C++ obsługujący standard C++11 (np. g++, clang).
- System operacyjny: Windows (wykorzystano `conio.h` dla `_getch()`).

---

## 🚀 Jak uruchomić?

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/twoja_nazwa_użytkownika/CountryDatabase.git
   ```

2. Skompiluj pliki źródłowe:
   ```bash
   g++ main.cpp country.cpp countrydatabase.cpp -o CountryDB
   ```

3. Uruchom program:
   ```bash
   ./CountryDB
   ```

## 🖥️ Interfejs użytkownika

Program oferuje przyjazne menu tekstowe z opcjami:
  ```
  1. Sprawdź, czy kraj należy do kontynentu
  2. Sprawdź, czy miasto jest stolicą kraju
  3. Sprawdź członkostwo w organizacji
  4. Dodaj nowy kraj
  5. Usuń kraj
  6. Edytuj dane kraju
  7. Wyświetl wszystkie kraje
  0. Wyjście
  ```

## 📊 Przykładowe dane

Dane zapisywane są w pliku database.txt w formacie:

  ```
  Argentyna
  Buenos Aires
  Ameryka Poludniowa
  G20,Unia Poludniowoamerykanska,
  ```

## 📌 Uwagi

  - Projekt nie zawiera zaawansowanej walidacji danych – zakłada poprawne użycie przez użytkownika.
  - Kod został napisany w języku polskim (nazwy zmiennych, komentarze).
  - W folderze html znajduje się dokumentacja projektu utworzona z użyciem Doxygen.

## 📜 Licencja
Projekt jest otwarty i dostępny dla wszystkich. Można go dowolnie modyfikować i wykorzystywać.
