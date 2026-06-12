#ifndef USER_H
#define USER_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "warna.h"
using namespace std;

// class user
class User {
private: // encapsulation
    string nama;
    string nim;
    string pin; 

public: 
    User();
    void inputData();
    void tampilData();
    void buatPin();
    bool verifikasiPin();
    string getNama();
    string getNim();
    ~User();
};

#endif