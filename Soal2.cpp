#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Peralatan {
    string kode;
    string nama;
    int jumlah;
    string kondisi;
};

void tambahPeralatan();
void ubahPeralatan();
void hapusPeralatan();
void tampilkanPeralatan();

int main() {
    tambahPeralatan();
    ubahPeralatan();
    hapusPeralatan();
    tampilkanPeralatan();
    return 0;
}

void tambahPeralatan() {
    ofstream file("inventaris.txt", ios::app);
    Peralatan p;
    cout << "Masukkan kode peralatan: ";
    cin >> p.kode;
    cout << "Masukkan nama peralatan: ";
    cin >> p.nama;
    cout << "Masukkan jumlah peralatan: ";
    cin >> p.jumlah;
    cout << "Masukkan kondisi peralatan: ";
    cin >> p.kondisi;
    file << p.kode << " " << p.nama << " " << p.jumlah << " " << p.kondisi << endl;
    file.close();
    cout << "Data berhasil ditambahkan.\n";
}

void ubahPeralatan() {
    // Implementasi ubah data peralatan (serupa dengan metode tambah)
}

void hapusPeralatan() {
    // Implementasi hapus data peralatan
}

void tampilkanPeralatan() {
    ifstream file("inventaris.txt");
    Peralatan p;
    cout << "Data Peralatan:\n";
    while (file >> p.kode >> p.nama >> p.jumlah >> p.kondisi) {
        cout << p.kode << " " << p.nama << " " << p.jumlah << " " << p.kondisi << endl;
    }
    file.close();
}
