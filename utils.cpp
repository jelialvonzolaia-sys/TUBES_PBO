#include "utils.h"

string formatRupiah(double *nominal) { // pointer
    string angka = to_string((long long)*nominal);
    string hasil = "";
    int hitung = 0;

    for (int i = angka.length() - 1; i >= 0; i--) {
        hasil = angka[i] + hasil;
        hitung++;
        if (hitung % 3 == 0 && i != 0) {
            hasil = "," + hasil;
        }
    }
    return hasil;
}