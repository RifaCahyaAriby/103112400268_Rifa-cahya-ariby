#include <iostream>
using namespace std;

// Fungsi untuk mengubah angka menjadi teks
string angkaKeTeks(int angka) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", 
                        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", 
                        "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka < 10) {
        return satuan[angka];
    } 
    else if (angka < 20) {
        return belasan[angka - 10];
    } 
    else if (angka < 100) {
        int p = angka / 10;  // puluhan
        int s = angka % 10;  // satuan
        if (s == 0)
            return puluhan[p];
        else
            return puluhan[p] + " " + satuan[s];
    } 
    else if (angka == 100) {
        return "seratus";
    } 
    else {
        return "harus diantara 0 dan 100!";
    }
}

int main() {
    int angka;
    cout << "masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "angka harus diantara 0 dan 100!.";
        
    } else {
        cout << angka << " : " << angkaKeTeks(angka);
    }

    return 0;
}
