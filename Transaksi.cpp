#include "Transaksi.h"

void Setor::proses() {
    cout << YELLOW << "[SYSTEM] Memproses Penyetoran via ATM..." << RESET << endl;
}

void Tarik::proses() {
    cout << YELLOW << "[SYSTEM] Memproses Penarikan via ATM..." << RESET << endl;
}

void Transfer::proses() {
    cout << YELLOW << "[SYSTEM] Memproses Transfer via ATM..." << RESET << endl;
}