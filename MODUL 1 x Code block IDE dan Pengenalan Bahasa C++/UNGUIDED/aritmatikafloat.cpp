#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "masukkan bilangan pertama: ";
    cin >> a;
    cout << "masukkan bilangan kedua: ";
    cin >> b;

    cout << "penjumlahan: " << a + b << endl;
    cout << "pengurangan: " << a - b << endl;
    cout << "perkalian: " << a * b << endl;

    if (b != 0)
        cout << "pembagian: " << a / b << endl;
    else
        cout << "pembagian: tidak dapat dibagi nol" << endl;

    return 0;
}
