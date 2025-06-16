#include <iostream>


use namespace:std;
int main() {
    // Deklaracja zmiennych
    double liczba1, liczba2, suma;

    // Powitanie użytkownika
    cout << "Witaj! To prosta aplikacja do obliczania sumy dwóch liczb.\n";

    // Pobranie danych od użytkownika
    cout << "Podaj pierwszą liczbę: ";
    cin >> liczba1;

    cout << "Podaj drugą liczbę: ";
    cin >> liczba2;

    // Obliczenie sumy
    suma = liczba1 + liczba2;

    // Wyświetlenie wyniku
    cout << "Suma podanych liczb wynosi: " << suma << "\n";

    // Zakończenie programu
    cout << "Dziękujemy za skorzystanie z aplikacji!\n";
    return 0;
}