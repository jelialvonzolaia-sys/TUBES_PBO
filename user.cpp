#include "User.h"

User::User() { nama = ""; nim = ""; } // constructor 

void User::inputData() { 
    while (true) { // perulangan
        cout << "Masukkan Nama : ";
        getline(cin, nama);
        if (nama.empty())
            cout << RED << BOLD << "[!] Nama tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
        else break;
    }
    while (true) { // perulangan
        cout << "Masukkan NIM  : ";
        getline(cin, nim);
        if (nim.empty())
            cout << RED << BOLD << "[!] NIM tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
        else break;
    }
}

void User::tampilData() { 
    cout << CYAN << BOLD << "\n=========================================" << RESET << endl;
    cout << CYAN << BOLD << "                DATA DIRI                " << RESET << endl;
    cout << CYAN << BOLD << "=========================================" << RESET << endl;
    cout << "Nama\t: " << BOLD << nama << RESET << endl;
    cout << "NIM\t: " << BOLD << nim << RESET << endl;
    cout << CYAN << "-----------------------------------------" << RESET << endl;
}

void User::buatPin() {
    while (true) { // perulangan
        cout << "Buat PIN ATM 6 digit : ";
        getline(cin, pin);
        if (pin.empty())
            cout << RED << BOLD << "[!] PIN tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
        else if (pin.length() != 6)
            cout << RED << BOLD << "[!] PIN harus 6 digit! Silakan isi ulang.\n" << RESET << endl;
        else if (!all_of(pin.begin(), pin.end(), ::isdigit))
            cout << RED << BOLD << "[!] PIN harus berupa angka! Silakan isi ulang.\n" << RESET << endl;
        else {
            cout << GREEN << BOLD << "[SUKSES] PIN berhasil dibuat!\n" << RESET << endl;
            break;
        }
    }
}

bool User::verifikasiPin() {
    string inputPin;
    cout << "Masukkan PIN : ";
    cin >> inputPin;
    if (inputPin == pin) {
        cout << GREEN << BOLD << "[SUKSES] PIN benar." << RESET << endl;
        return true;
    }
    return false;
}

string User::getNama() { return nama; }
string User::getNim()  { return nim; }
User::~User() {} // destructor 