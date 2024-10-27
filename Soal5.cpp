#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Buku {
    string ISBN;
    string judul;
    string pengarang;
    int tahunTerbit;
};

stack<string> riwayatPeminjaman;
queue<string> antrianPeminjaman;

void pinjamBuku(string judul) {
    antrianPeminjaman.push(judul);
    cout << "Buku " << judul << " ditambahkan ke antrian peminjaman.\n";
}

void kembalikanBuku(string judul) {
    riwayatPeminjaman.push(judul);
    cout << "Buku " << judul << " telah dikembalikan dan disimpan di riwayat.\n";
}

int main() {
    pinjamBuku("Struktur Data");
    kembalikanBuku("Struktur Data");
    return 0;
}
