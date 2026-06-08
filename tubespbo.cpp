#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

class User {
private:
    string nama;
    string nim;
    string pin;

public:
    User(){ 
        nama = ""; 
        nim = "";
    };

    void inputData(){
        while (true) {
            cout << "Masukkan Nama : ";
            getline(cin, nama);
            
            if (nama.empty()) {
                cout << RED << BOLD << "[!] Nama tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
            } else {
                break;
            }
        }
        
        while (true) {
            cout << "Masukkan NIM  : ";
            getline(cin, nim);
            
            if (nim.empty()) {
                cout << RED << BOLD << "[!] NIM tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
            } else {
                break;
            }
        }
    };

    void tampilData(){
        cout << CYAN << BOLD << "\n=========================================" << RESET << endl;
        cout << CYAN << BOLD << "                DATA DIRI                " << RESET << endl;
        cout << CYAN << BOLD << "=========================================" << RESET << endl;
        cout << "Nama\t: " << BOLD << nama << RESET << endl;
        cout << "NIM\t: " << BOLD << nim << RESET << endl;
        cout << CYAN << "-----------------------------------------" << RESET << endl;
    };

    void buatPin(){
        while (true) {
            cout << "Buat PIN ATM 6 digit : ";
            getline(cin, pin);

            if (pin.empty()) {
                cout << RED << BOLD << "[!] PIN tidak boleh kosong! Silakan isi ulang.\n" << RESET << endl;
            } else if (pin.length() !=6) {
                cout << RED << BOLD << "[!] PIN harus 6 digit! Silakan isi ulang.\n" << RESET << endl;
            } else if (!all_of(pin.begin(), pin.end(), ::isdigit)) {
                cout << RED << BOLD << "[!] PIN harus berupa angka! Silakan isi ulang.\n" << RESET << endl;
            } else {
                cout << GREEN << BOLD << "[SUKSES] PIN berhasil dibuat!\n" << RESET << endl;
                break;
            }
        }
    }

    bool verifikasiPin() {
        string inputPin;

        cout << "Masukkan PIN : ";
        cin >> inputPin;

        if (inputPin == pin) {
            cout << GREEN << BOLD << "[SUKSES] PIN benar." << RESET << endl;
            return true;
        } else {
            return false;
        }
    }

    string getNama(){ 
        return nama; 
    };

    string getNim(){ 
        return nim; 
    };

    ~User(){};
};

class AkunBank {
private:
    double saldo;

public:
    AkunBank(){
        saldo = 0;
    };
    
    void cekSaldo(){
        cout << GREEN << BOLD << "\n=========================================" << RESET << endl;
        cout << GREEN << BOLD << "                CEK SALDO                " << RESET << endl;
        cout << GREEN << BOLD << "=========================================" << RESET << endl;
        cout << "Saldo Anda Saat Ini : " << GREEN << BOLD << "Rp. " << saldo << RESET << endl;
        cout << GREEN << "-----------------------------------------" << RESET << endl;
    };
        
    void setorSaldo(double jumlah) {
        if (jumlah <= 0) {
            cout << RED << BOLD << "\n[ERROR] Jumlah setor tidak valid!" << RESET << endl;
        }
        else if (jumlah < 50000) {
            cout << RED << BOLD << "\n[ERROR] Minimal setor adalah Rp. 50.000!" << RESET << endl;
        }
        else if ((int)jumlah % 50000 != 0) {
            cout << RED << BOLD << "\n[ERROR] Setoran harus kelipatan Rp. 50.000!" << RESET << endl;
        }
        else {
            saldo += jumlah;
            cout << fixed << setprecision(0);
            cout << GREEN << BOLD << "\n[SUKSES] Penyetoran Berhasil!" << RESET << endl;
            cout << "Jumlah Setor   : " << GREEN << BOLD << "Rp. " << jumlah << RESET << endl;
            cout << "Saldo Sekarang : " << GREEN << BOLD << "Rp. " << saldo << RESET << endl;
            cout << GREEN << "-----------------------------------------" << RESET << endl;
            simpanLaporanTeller("Setor Saldo", jumlah);
        } 
    }
    
    void tarikSaldo(double jumlah) {
        if (jumlah <= 0) {
            cout << RED << BOLD << "\n[ERROR] Jumlah penarikan tidak valid!" << RESET << endl;
        }
        else if (jumlah < 50000) {
            cout << RED << BOLD << "\n[ERROR] Minimal penarikan adalah Rp. 50.000!" << RESET << endl;
        }
        else if ((int)jumlah % 50000 != 0) {
            cout << RED << BOLD << "\n[ERROR] Penarikan harus kelipatan Rp. 50.000!" << RESET << endl;
        }
        else if (jumlah > saldo) {
            cout << RED << BOLD << "\n[ERROR] Saldo tidak mencukupi untuk penarikan ini!" << RESET << endl;
        } 
        else {
            saldo -= jumlah;
            cout << fixed << setprecision(0);
            cout << GREEN << BOLD << "\n[SUKSES] Penarikan berhasil sebesar Rp. " << jumlah << RESET << endl;
            cout << "Saldo Anda sekarang : " << GREEN << BOLD << "Rp. " << saldo << RESET << endl;
            simpanLaporanTeller("Tarik Saldo", jumlah);
        }
    }

    void simpanLaporanAkun(User &user){
        ofstream file("laporan_keuangan_bank_anak_rantau.txt", ios::app);

        cout << YELLOW << BOLD << "\n=========================================" << RESET << endl;
        cout << YELLOW << BOLD << "           PROSES CETAK LAPORAN          " << RESET << endl;
        cout << YELLOW << BOLD << "=========================================" << RESET << endl;

        if (file.is_open()) {
            file << "Nama           : " << user.getNama() << endl;
            file << "NIM            : " << user.getNim() << endl;
            file << "Saldo akhir    : Rp. " << saldo << endl;
            file << "------------------------" << endl;
            file.close();

            cout << GREEN << BOLD << "[SUKSES] Laporan Berhasil Disimpan ke File!" << RESET << endl;
        } else {
            cout << RED << BOLD << "[ERROR] Gagal Membuka File Laporan Akun!" << RESET << endl;
        }
        cout << YELLOW << "-----------------------------------------" << RESET << endl;
    }

    void simpanLaporanTeller(string jenisTransaksi, double jumlah){
        ofstream file("laporan_keuangan_khusus_teller.txt", ios::app);
        if (file.is_open()) {
            file << "Jenis Transaksi    : " << jenisTransaksi << endl;
            file << "Jumlah             : Rp. " << jumlah << endl;
            file << "Saldo saat ini     : Rp. " << saldo << endl;
            file << "------------------------" << endl;
            file.close();
        }
    }

    void transferSaldo(double jumlah, string rekeningTujuan, string namaBank, string namaPengirim, string namaPenerima) {
        double biayaAdmin = 0;

        if (namaBank != "Bank Anak Rantau") {
            biayaAdmin = 2500;
        }

        double totalPotongan = jumlah + biayaAdmin;

        if (jumlah < 50000) {
            cout << RED << BOLD << "\n[ERROR] Minimal transfer adalah Rp. 50.000!" << RESET << endl;
        } 
        else if ((int)jumlah % 50000 != 0) {
                cout << RED << BOLD << "\n[ERROR] Transfer harus kelipatan Rp. 50.000!" << RESET << endl;
        }
        else if (jumlah > 10000000) {
            cout << RED << BOLD << "\n[ERROR] Maksimal transfer adalah Rp. 10.000.000!" << RESET << endl;
        } 
        else if (totalPotongan > saldo) {
            cout << RED << BOLD << "\n[ERROR] Saldo tidak mencukupi untuk transfer + biaya admin!" << RESET << endl;
        } 
        else {
            saldo -= totalPotongan;

            cout << GREEN << BOLD << "\n[SUKSES] Transfer berhasil!" << RESET << endl;
            cout << CYAN << BOLD << "\n============ BUKTI TRANSFER ===========\n" << RESET;
            cout << "      Nama Pengirim   : " << BOLD << namaPengirim << RESET << endl;
            cout << "      Nama Penerima   : " << BOLD << namaPenerima << RESET << endl;
            cout << "      NIM Penerima    : " << BOLD << rekeningTujuan << RESET << endl;
            cout << "      Bank Tujuan     : " << BOLD << namaBank << RESET << endl;
            cout << endl;
            cout << fixed << setprecision(0);
            cout << "      Jumlah Transfer : Rp. " << jumlah << endl;
            cout << "      Biaya Admin     : Rp. " << biayaAdmin << endl;
            cout << "      Total Potongan  : Rp. " << totalPotongan << endl;
            cout << "      Saldo Sekarang  : Rp. " << saldo << endl;
            cout << CYAN << BOLD << "=======================================" << RESET << endl;
            cout << GREEN << "     Transfer Berhasil Diproses        " << RESET << endl;
            cout << "Terimakasih Telah Bertaransaksi Bersama" << endl;
            cout << "          Bank Anak Rantau             " << endl;
            cout << "  Terimakasih Atas Kepercayaan Anda" << endl;
            simpanLaporanTeller("Transfer ke " + namaBank + " - Rekening " + rekeningTujuan, totalPotongan);
            }
        }

    double getSaldo() { return saldo; }
    ~AkunBank(){};
};

class Transaksi {
public:
    virtual void proses() = 0;
    virtual ~Transaksi() {}
};

class Setor : public Transaksi {
public:
    void proses() override {
        cout << YELLOW << "[SYSTEM] Memproses Penyetoran via ATM..." << RESET << endl;
    }
};

class Tarik : public Transaksi {
public:
    void proses() override {
        cout << YELLOW << "[SYSTEM] Memproses Penarikan via ATM..." << RESET << endl;
    }
};

void tampilMenu(){
    cout << BLUE << BOLD << "=========================================" << RESET << endl;
    cout << BLUE << BOLD << "        MENU ATM BANK ANAK RANTAU        " << RESET << endl;
    cout << BLUE << BOLD << "=========================================" << RESET << endl;
    cout << "[" << YELLOW << BOLD << "1" << RESET << "] Cek Saldo" << endl;
    cout << "[" << YELLOW << BOLD << "2" << RESET << "] Setor Tunai" << endl;
    cout << "[" << YELLOW << BOLD << "3" << RESET << "] Tarik Tunai" << endl;
    cout << "[" << YELLOW << BOLD << "4" << RESET << "] Transfer Dana" << endl;
    cout << "[" << YELLOW << BOLD << "5" << RESET << "] Data Nasabah" << endl;
    cout << "[" << YELLOW << BOLD << "6" << RESET << "] Cetak Laporan Akun" << endl;
    cout << "[" << RED    << BOLD << "7" << RESET << "] Keluar" << endl;
    cout << BLUE << "=========================================" << RESET << endl;
    cout << "Pilih menu " << BOLD << ": " << RESET;
}

void kembaliMenu(){
    cout << "\nTekan [" << RED << BOLD << "ESC" << RESET << "] untuk kembali ke menu utama...";
    
    char tombol;
    while (true) {
        tombol = _getch(); 
        if (tombol == 27) { 
            break;
        }
    }
    system("cls");
}

class Transfer : public Transaksi {
public:
    void proses() override {
        cout << YELLOW << "[SYSTEM] Memproses Transfer via ATM..." << RESET << endl;
    }
};

int main(){
    User pengguna;
    AkunBank a;
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


    do {
        tampilMenu();
        cin >> choice;
        
        switch (choice) {
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
            Transaksi *transaksi = new Setor(); 
            transaksi->proses();

            a.setorSaldo(jumlah);

            delete transaksi;
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

            switch (pilihanTarik) {
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
            Transaksi *transaksi = new Tarik();
            transaksi->proses();

                a.tarikSaldo(jumlah);
            delete transaksi;
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

        switch (pilihBank) {
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
            Transaksi *transaksi = new Transfer();
            transaksi->proses();

            a.transferSaldo(jumlah, rekeningTujuan, namaBank, pengguna.getNama(), namaPenerima);

            delete transaksi;
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
                cout << GREEN << BOLD << "\n=========================================" << RESET << endl;
                cout << GREEN << BOLD << "     Terima kasih telah menggunakan \n           Bank Anak Rantau!   " << RESET << endl;
                cout << GREEN << BOLD << "=========================================\n" << RESET << endl;
                break;

            default:
                cout << RED << BOLD << "\n[!] Pilihan tidak valid! Silakan coba lagi." << RESET << endl;
            }

        } while (choice != 7);

    return 0;
}