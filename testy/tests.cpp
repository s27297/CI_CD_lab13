#include <cassert>
#include <iostream>
#include "../funkcje.hpp"

using namespace std;

void test_dodaj() {
    assert(dodaj(2, 3) == 5);
    assert(dodaj(-2, 5) == 3);
    assert(dodaj(0, 0) == 0);
    assert(dodaj(-3, -4) == -7);
}

void test_razy() {
    assert(razy(2, 3) == 6);
    assert(razy(-2, 5) == -10);
    assert(razy(0, 7) == 0);
    assert(razy(-3, -4) == 12);
}

int main() {
    test_dodaj();
    test_razy();
    cout << "✅ Wszystkie testy przeszły pomyślnie." << endl;
    return 0;
}
