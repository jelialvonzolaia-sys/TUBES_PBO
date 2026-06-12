# TUBES_PBO

Program **ATM Bank Anak Rantau** merupakan aplikasi ATM sederhana berbasis terminal menggunakan bahasa pemrograman **C++**. Project ini dibuat untuk memenuhi tugas besar mata kuliah **Praktikum Pemrograman Berorientasi Objek**.

## Daftar Anggota Kelompok

| No | Nama                           | NIM       |
| -: | ------------------------------ | --------- |
|  1 | Yessica Jaklin                 | 251402001 |
|  2 | Daradira Vonna                 | 251402026 |
|  3 | Rodotua Naomi Mutiara Simamora | 251402030 |
|  4 | Felix Desselo Tambunan         | 251402033 |
|  5 | Vedder Timothy Simbolon        | 251402072 |
|  6 | Jeli Alvonzo Laia              | 251402101 |

## Fitur Program

Program ini memiliki beberapa fitur utama, yaitu:

1. **Input Data User**
   User dapat memasukkan data diri berupa nama dan NIM sebelum masuk ke menu utama.

2. **Pembuatan PIN ATM**
   User dapat membuat PIN ATM 6 digit sebagai sistem keamanan transaksi.

3. **Verifikasi PIN**
   Program akan meminta PIN sebelum user melakukan transaksi tertentu.

4. **Cek Saldo**
   User dapat melihat jumlah saldo yang tersedia pada akun.

5. **Setor Saldo**
   User dapat melakukan penyetoran saldo dengan validasi minimal setor dan kelipatan nominal tertentu.

6. **Tarik Saldo**
   User dapat melakukan penarikan saldo dengan validasi agar saldo tidak kurang.

7. **Transfer Saldo**
   User dapat melakukan transfer saldo menggunakan NIM sebagai tujuan transfer.

8. **Cetak Struk Transfer**
   Program dapat menampilkan struk transfer setelah transaksi berhasil.

9. **Tampilkan Data User**
   Program dapat menampilkan kembali data user yang telah dimasukkan.

10. **Simpan Laporan Akun**
    Program dapat menyimpan laporan akun ke dalam file `.txt`.

11. **Laporan Teller**
    Setiap transaksi berhasil akan dicatat ke dalam file laporan khusus teller.

## Konsep PBO yang Digunakan

Project ini menerapkan beberapa konsep Pemrograman Berorientasi Objek, yaitu:

1. **Class dan Object**
2. **Constructor dan Destructor**
3. **Encapsulation**
4. **Abstraction**
5. **Inheritance**
6. **Overriding**
7. **Polymorphism**
8. **File Handling**
9. **Method dan Validasi Input**

## Struktur File Project

Project ini sudah dipisahkan menjadi beberapa file agar lebih rapi dan mudah dikembangkan.

| File            | Fungsi                                                                          |
| --------------- | ------------------------------------------------------------------------------- |
| `main.cpp`      | Berisi alur utama program                                                       |
| `AkunBank.h`    | Deklarasi class AkunBank                                                        |
| `AkunBank.cpp`  | Implementasi fitur akun bank seperti saldo, setor, tarik, transfer, dan laporan |
| `user.h`        | Deklarasi class User                                                            |
| `user.cpp`      | Implementasi input data user, PIN, dan verifikasi PIN                           |
| `Transaksi.h`   | Deklarasi class Transaksi dan turunannya                                        |
| `Transaksi.cpp` | Implementasi proses transaksi                                                   |
| `menu.h`        | Deklarasi fungsi menu                                                           |
| `menu.cpp`      | Implementasi tampilan menu program                                              |
| `utils.h`       | Deklarasi fungsi bantuan                                                        |
| `utils.cpp`     | Implementasi fungsi bantuan seperti format rupiah                               |
| `warna.h`       | Berisi kode warna untuk tampilan terminal                                       |

## Cara Menjalankan Program

Compile program dengan perintah berikut:

```bash
g++ main.cpp AkunBank.cpp menu.cpp Transaksi.cpp user.cpp utils.cpp -o BankAnakRantau
```

Jalankan program:

```bash
./BankAnakRantau
```

Untuk pengguna Windows, jalankan:

```bash
BankAnakRantau.exe
```

