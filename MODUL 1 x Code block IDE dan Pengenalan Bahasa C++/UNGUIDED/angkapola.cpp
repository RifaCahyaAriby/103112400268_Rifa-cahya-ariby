#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        // Cetak spasi di awal baris
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }

        // Cetak angka menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Cetak bintang
        cout << "* ";

        // Cetak angka menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // Cetak baris terakhir hanya bintang (dengan spasi di awal)
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
