#include "menu.h"

void tampilMenu(){ // menu program
    cout << BLUE << BOLD << "=========================================" << RESET << endl;
    cout << BLUE << BOLD << "        MENU ATM BANK ANAK RANTAU        " << RESET << endl;
    cout << BLUE << BOLD << "=========================================" << RESET << endl;
    cout << "[" << YELLOW << BOLD << "1" << RESET << "] Cek Saldo" << endl;
    cout << "[" << YELLOW << BOLD << "2" << RESET << "] Setor Tunai" << endl;
    cout << "[" << YELLOW << BOLD << "3" << RESET << "] Tarik Tunai" << endl;
    cout << "[" << YELLOW << BOLD << "4" << RESET << "] Transfer Dana" << endl;
    cout << "[" << YELLOW << BOLD << "5" << RESET << "] Data Nasabah" << endl;
    cout << "[" << YELLOW << BOLD << "6" << RESET << "] Cetak Laporan Akun" << endl;
    cout << "[" << YELLOW << BOLD << "7" << RESET << "] Cetak Riwayat Transfer" << endl;
    cout << "[" << RED << BOLD << "8" << RESET << "] Keluar" << endl;
    cout << BLUE << "=========================================" << RESET << endl;
    cout << "Pilih menu " << BOLD << ": " << RESET;
}

void kembaliMenu(){
    cout << "\nTekan [" << RED << BOLD << "ESC" << RESET << "] untuk kembali ke menu utama...";
    
    char tombol;
    while (true) { // perulangan
        tombol = _getch(); 
        if (tombol == 27) { 
            break;
        }
    }
    system("cls");
}