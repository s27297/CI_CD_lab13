#include <iostream>
using namespace std;

int dodaj(int a, int b) {
    return a + b;
}

int razy(int a, int b) {
    return a * b;
}

int main() {
    cout << "Suma 5+7 = " << dodaj(5, 7) << ", mnożenie 5*7 = " << razy(5, 7) << endl;
    return 0;
}
