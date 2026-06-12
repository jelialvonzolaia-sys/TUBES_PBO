#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <iostream>
#include "warna.h"
using namespace std;

class Transaksi { // abstact class
public:
    virtual void proses() = 0;
    virtual ~Transaksi() {} // virtual function
};

class Setor : public Transaksi { // inheritance setor
public:
    void proses() override; // function overriding
};

class Tarik : public Transaksi { // inheritance setor
public:
    void proses() override; // function overriding
};

class Transfer : public Transaksi { // inheritance setor
public:
    void proses() override; // function overriding
};

#endif