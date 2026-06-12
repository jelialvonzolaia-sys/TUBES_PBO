#include <iostream>
#include <cstdlib>
#include "warna.h"
#include "User.h"
#include "AkunBank.h"
#include "Transaksi.h"
#include "menu.h"
using namespace std;

int main() { // main program
    User pengguna; // object user
    AkunBank a; // object akunbank
    double jumlah;
    int choice;
    string rekeningTujuan;

    system("cls");
    cout << BLUE << BOLD << "=========================================" << RESET << endl;
    cout << BLUE << BOLD << "           ATM BANK ANAK RANTAU          " << RESET << endl;
    cout << BLUE << BOLD << "=========================================" << RESET << endl;

    pengguna.inputData();
    pengguna.buatPin();
    system("cls");


    do { // perulangan
        tampilMenu();
        cin >> choice;
        
        switch (choice) { // switch case menu utama
        case 1:
            a.cekSaldo();
            kembaliMenu();
            break;

        case 2: {
            cout << GREEN << BOLD << "=========================================" << RESET << endl;
            cout << GREEN << BOLD << "             SETOR TUNAI ATM             " << RESET << endl;
            cout << GREEN << BOLD << "=========================================" << RESET << endl;
            cout << "Masukkan Jumlah Setor : Rp. ";
            cin >> jumlah;

            if (pengguna.verifikasiPin()) { 
            Transaksi *transaksi = new Setor(); // polymorphism & dynamic memory new
            transaksi->proses();

            a.setorSaldo(jumlah);

            delete transaksi; // dynamic memory delete
            } else {
                cout << RED << BOLD << "\n[ERROR] Verifikasi PIN gagal. Penyetoran dibatalkan." << RESET << endl;
            }
            kembaliMenu();
            break;
        }

        case 3: {
            cout << RED << BOLD << "=========================================" << RESET << endl;
            cout << RED << BOLD << "             TARIK TUNAI ATM             " << RESET << endl;
            cout << RED << BOLD << "=========================================" << RESET << endl;
            
            int pilihanTarik;

            cout << "Pilih Nominal Penarikan:" << endl;
            cout << "[1] Rp. 50.000" << endl;
            cout << "[2] Rp. 100.000" << endl;
            cout << "[3] Rp. 200.000" << endl;
            cout << "[4] Rp. 500.000" << endl;
            cout << "[5] Rp. 1.000.000" << endl;
            cout << "[6] Nominal Lain" << endl;
            cout << "Pilihan : ";
            cin >> pilihanTarik;

            switch (pilihanTarik) { // switch case pilihan tarik
                case 1:
                    jumlah = 50000;
                    break;
                case 2:
                    jumlah = 100000;
                    break;
                case 3:
                    jumlah = 200000;
                    break;
                case 4:
                    jumlah = 500000;
                    break;
                case 5:
                    jumlah = 1000000;
                    break;
                case 6:
                    cout << "Masukkan Jumlah Penarikan: Rp. ";
                    cin >> jumlah;
                    break;
                default:
                    cout << RED << BOLD << "\n[ERROR] Pilihan nominal tidak valid!" << RESET << endl;
                    kembaliMenu();
                    break;
            }

            if (pengguna.verifikasiPin()) {
                Transaksi *transaksi = new Tarik(); // polymorphism & dynamic memory new
                transaksi->proses();

                a.tarikSaldo(jumlah);
                delete transaksi; // dynamic memory delete
            } else {
                cout << RED << BOLD << "\n[ERROR] Verifikasi PIN gagal. Penarikan dibatalkan." << RESET << endl;
            }
    
            kembaliMenu();
            break;
        }

        case 4: {
        int pilihBank;
        string namaBank;
        string namaPenerima;

        cout << CYAN << BOLD << "=========================================" << RESET << endl;
        cout << CYAN << BOLD << "              TRANSFER SALDO             " << RESET << endl;
        cout << CYAN << BOLD << "=========================================" << RESET << endl;

        cout << "Pilih Bank Tujuan:" << endl;
        cout << "[1] Bank Anak Rantau" << endl;
        cout << "[2] BCA" << endl;
        cout << "[3] BRI" << endl;
        cout << "[4] Mandiri" << endl;
        cout << "[5] BNI" << endl;
        cout << "[6] Bank Lainnya" << endl;
        cout << "Pilihan Bank : ";
        cin >> pilihBank;

        switch (pilihBank) { // switch case pilihan bank
            case 1:
                namaBank = "Bank Anak Rantau";
                break;
            case 2:
                namaBank = "BCA";
                break;
            case 3:
                namaBank = "BRI";
                break;
            case 4:
                namaBank = "Mandiri";
                break;
            case 5:
                namaBank = "BNI";
                break;
            case 6:
                namaBank = "Bank Lainnya";
                break;
            default:
                cout << RED << BOLD << "\n[ERROR] Pilihan bank tidak valid!" << RESET << endl;
                kembaliMenu();
                break;
        }

        if (pilihBank < 1 || pilihBank > 6) {
            break;
        }

        cin.ignore();

        cout << "Masukkan Nama Penerima : ";
        getline(cin, namaPenerima);

        cout << "Masukkan NIM Penerima  : ";
        getline(cin, rekeningTujuan);

        cout << "Masukkan Jumlah Transfer : Rp. ";
        cin >> jumlah;

        if (pengguna.verifikasiPin()) {
            Transaksi *transaksi = new Transfer(); // polymorphism & dynamic memory new
            transaksi->proses();

            a.transferSaldo(jumlah, rekeningTujuan, namaBank, pengguna.getNama(), namaPenerima);

            delete transaksi; // dynamic memory delete
        } else {
            cout << RED << BOLD << "\n[ERROR] Verifikasi PIN gagal. Transfer dibatalkan." << RESET << endl;
        }

        kembaliMenu();
        break;
        }
            case 5: 
                pengguna.tampilData();
                kembaliMenu();
                break;
            
            case 6:
                if (pengguna.verifikasiPin()) {
                a.simpanLaporanAkun(pengguna);
                }
                kembaliMenu();
                break;
            
            case 7:
                if (pengguna.verifikasiPin()) {
                a.tampilRiwayatTransfer();
                }
                kembaliMenu();
                break;
                
            case 8:
                cout << GREEN << BOLD << "\n=========================================" << RESET << endl;
                cout << GREEN << BOLD << "     Terima kasih telah menggunakan \n           Bank Anak Rantau!   " << RESET << endl;
                cout << GREEN << BOLD << "=========================================\n" << RESET << endl;
                break;

            default:
                cout << RED << BOLD << "\n[!] Pilihan tidak valid! Silakan coba lagi." << RESET << endl;
            }
        } while (choice != 8);

    return 0;
}