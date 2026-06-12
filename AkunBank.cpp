#include "AkunBank.h"

AkunBank::AkunBank() { saldo = 0; } // constructor


void AkunBank::cekSaldo(){ 
    cout << GREEN << BOLD << "\n=========================================" << RESET << endl;
    cout << GREEN << BOLD << "                CEK SALDO                " << RESET << endl;
    cout << GREEN << BOLD << "=========================================" << RESET << endl;
    cout << "Saldo Anda Saat Ini : " << GREEN << BOLD << "Rp. " << formatRupiah(&saldo) << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;
};
    
void AkunBank::setorSaldo(double jumlah) { 
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
        cout << "Jumlah Setor   : " << GREEN << BOLD << "Rp. " << formatRupiah(&jumlah) << RESET << endl;
        cout << "Saldo Sekarang : " << GREEN << BOLD << "Rp. " << formatRupiah(&saldo) << RESET << endl;
        cout << GREEN << "-----------------------------------------" << RESET << endl;
        simpanLaporanTeller("Setor Saldo", jumlah);
    } 
}

void AkunBank::tarikSaldo(double jumlah) {
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
        cout << GREEN << BOLD << "\n[SUKSES] Penarikan berhasil sebesar Rp. " << formatRupiah(&jumlah) << RESET << endl;
        cout << "Saldo Anda sekarang : " << GREEN << BOLD << "Rp. " << formatRupiah(&saldo) << RESET << endl;
        simpanLaporanTeller("Tarik Saldo", jumlah);
    }
}

void AkunBank::simpanLaporanAkun(User &user) { // file headling laporan akun

    bool fileKosong = false;
    
    ifstream cek("laporan_keuangan_bank_anak_rantau.txt");
    
    if (!cek.good()) {
        fileKosong = true;
    }
    else {
        cek.seekg(0, ios::end);
        fileKosong = (cek.tellg() == 0);
    }

    cek.close();

    ofstream file("laporan_keuangan_bank_anak_rantau.txt", ios::app);

    cout << YELLOW << BOLD << "\n=========================================" << RESET << endl;
    cout << YELLOW << BOLD << "           PROSES CETAK LAPORAN          " << RESET << endl;
    cout << YELLOW << BOLD << "=========================================" << RESET << endl;

    if (file.is_open()) {
    
        if (fileKosong) {
            file << "==========================================" << endl;
            file << "     LAPORAN KEUANGAN BANK ANAK RANTAU" << endl;
            file << "==========================================" << endl << endl;
        }
    
        file << "Nama           : " << user.getNama() << endl;
        file << "NIM            : " << user.getNim() << endl;
        file << "Saldo Akhir    : Rp. " << formatRupiah(&saldo) << endl;
        file << "-----------------------------------------" << endl;
        file.close();
        cout << GREEN << BOLD << "[SUKSES] Laporan Berhasil Disimpan ke File!" << RESET << endl;
    }
    else {
        cout << RED << BOLD << "[ERROR] Gagal Membuka File Laporan Akun!" << RESET << endl;
    }
    cout << YELLOW << "-----------------------------------------" << RESET << endl;
}

void AkunBank::simpanLaporanTeller(string jenisTransaksi, double jumlah) { // file headling laporan teller

    bool fileKosong = false;

    ifstream cek("laporan_keuangan_khusus_teller.txt");

    if (!cek.good()) {
        fileKosong = true;
    }
    else {
        cek.seekg(0, ios::end);
        fileKosong = (cek.tellg() == 0);
    }

    cek.close();

    ofstream file("laporan_keuangan_khusus_teller.txt", ios::app);

    if (file.is_open()) {

        if (fileKosong) {
            file << "==========================================" << endl;
            file << "      LAPORAN TRANSAKSI TELLER ATM" << endl;
            file << "==========================================" << endl << endl;
        }
        file << "Jenis Transaksi : " << jenisTransaksi << endl;
        file << "Jumlah          : Rp. " << formatRupiah(&jumlah) << endl;
        file << "Saldo Saat Ini  : Rp. " << formatRupiah(&saldo) << endl;
        file << "-----------------------------------------" << endl;

        file.close();
    }
}

void AkunBank::transferSaldo(double jumlah, string rekeningTujuan, string namaBank, string namaPengirim, string namaPenerima) {
    double biayaAdmin = 0;

    if (namaBank != "Bank Anak Rantau") {
        biayaAdmin = 2500;
    }

    double totalPotongan = jumlah + biayaAdmin;
    if (jumlah <= 0) {
        cout << RED << BOLD << "\n[ERROR] Jumlah transfer tidak valid!" << RESET << endl;
    }
    else if (jumlah < 10000) {
        cout << RED << BOLD << "\n[ERROR] Minimal transfer adalah Rp. 10.000!" << RESET << endl;
    } 
    else if (jumlah > 10000000) {
        cout << RED << BOLD << "\n[ERROR] Maksimal transfer adalah Rp. 10.000.000!" << RESET << endl;
    } 
    else if (totalPotongan > saldo) {
        cout << RED << BOLD << "\n[ERROR] Saldo tidak mencukupi untuk transfer + biaya admin!" << RESET << endl;
    } 
    else {
        saldo -= totalPotongan;
        double totalPotongan = jumlah + biayaAdmin;

        cout << GREEN << BOLD << "\n[SUKSES] Transfer berhasil!" << RESET << endl;
        cout << CYAN << BOLD << "\n============ BUKTI TRANSFER ===========\n" << RESET;
        cout << "    Nama Pengirim   : " << BOLD << namaPengirim << RESET << endl;
        cout << "    Nama Penerima   : " << BOLD << namaPenerima << RESET << endl;
        cout << "    NIM Penerima    : " << BOLD << rekeningTujuan << RESET << endl;
        cout << "    Bank Tujuan     : " << BOLD << namaBank << RESET << endl;
        cout << endl;
        cout << fixed << setprecision(0);
        cout << "    Jumlah Transfer : Rp. " << formatRupiah(&jumlah) << endl;
        cout << "    Biaya Admin     : Rp. " << formatRupiah(&biayaAdmin) << endl;
        cout << "    Total Potongan  : Rp. " << formatRupiah(&totalPotongan) << endl;
        cout << "    Saldo Sekarang  : Rp. " << formatRupiah(&saldo) << endl;
        cout << CYAN << BOLD << "=======================================" << RESET << endl;
        cout << GREEN << "     Transfer Berhasil Diproses        " << RESET << endl;
        cout << "Terimakasih Telah Bertaransaksi Bersama" << endl;
        cout << "          Bank Anak Rantau             " << endl;
        cout << "  Terimakasih Atas Kepercayaan Anda" << endl;
        simpanLaporanTeller("Transfer ke " + namaBank + " - Rekening " + rekeningTujuan, totalPotongan);
        simpanRiwayatTransfer( namaPengirim, namaPenerima, rekeningTujuan, namaBank, jumlah, biayaAdmin);
        }
    }
    
    void AkunBank::simpanRiwayatTransfer(string namaPengirim, string namaPenerima, string rekeningTujuan, string namaBank, double jumlah, double biayaAdmin) { // vector
        string data = "";
        double total = jumlah + biayaAdmin;

        data += "======================================\n";
        data += "Nama Pengirim  : " + namaPengirim + "\n";
        data += "Nama Penerima  : " + namaPenerima + "\n";
        data += "NIM Penerima   : " + rekeningTujuan + "\n";
        data += "Bank Tujuan    : " + namaBank + "\n";
        data += "Jumlah         : Rp. " + formatRupiah(&jumlah) + "\n";
        data += "Biaya Admin    : Rp. " + formatRupiah(&biayaAdmin) + "\n";
        data += "Total          : Rp. " + formatRupiah(&total) + "\n";
        data += "======================================\n";

        riwayatTransfer.push_back(data);
    }

    void AkunBank::tampilRiwayatTransfer() { // file headling cetak riwayat transfer
        cout << CYAN << BOLD << "\n============================================" << RESET << endl;
        cout << CYAN << BOLD << "           PROSES CETAK RIWAYAT TRANSFER        " << RESET << endl;
        cout << CYAN << BOLD << "=============================================" << RESET << endl;

        if (riwayatTransfer.empty()) {
            cout << RED << BOLD << "Belum ada riwayat transfer." << RESET << endl;
        }
        else {
            ofstream file("riwayat_transfer.txt");
        
            if (file.is_open()) {
            
                file << "==========================================" << endl;
                file << "         DATA RIWAYAT TRANSFER" << endl;
                file << "==========================================" << endl << endl;
            
                for (string data : riwayatTransfer) {
                    file << data << endl;
                }
            
                file.close();
            
                cout << GREEN << BOLD << "[SUKSES] Riwayat Transfer Berhasil Disimpan ke File!" << RESET << endl;
            }
            else {
                cout << RED << BOLD << "[ERROR] Gagal Menyimpan Riwayat!" << RESET << endl;
            }
        }
    
        cout << CYAN << "-----------------------------------------" << RESET << endl;
    }

double AkunBank::getSaldo() { return saldo; }
AkunBank::~AkunBank(){}; // destructor