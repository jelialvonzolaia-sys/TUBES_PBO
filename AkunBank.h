#ifndef AKUNBANK_H
#define AKUNBANK_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "warna.h"
#include "utils.h"
#include "User.h"
using namespace std;

class AkunBank { // class AkunBank
private: //encapsulation
    double saldo;
    vector<string> riwayatTransfer; // vector

public:
    AkunBank();
    void cekSaldo();
    void setorSaldo(double jumlah);
    void tarikSaldo(double jumlah);
    void transferSaldo(double jumlah, string rekeningTujuan, string namaBank,
                       string namaPengirim, string namaPenerima);
    void simpanRiwayatTransfer(string namaPengirim, string namaPenerima,
                               string rekeningTujuan, string namaBank,
                               double jumlah, double biayaAdmin);
    void tampilRiwayatTransfer();
    void simpanLaporanAkun(User &user);
    void simpanLaporanTeller(string jenisTransaksi, double jumlah);
    double getSaldo();
    ~AkunBank();
};

#endif