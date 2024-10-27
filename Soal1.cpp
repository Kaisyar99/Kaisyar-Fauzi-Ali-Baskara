#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string nama;
    float IPK;
};

void tambahMahasiswa(Mahasiswa* mhs[], int &jumlah);
void hapusMahasiswa(Mahasiswa* mhs[], int &jumlah, string nim);
void tampilkanMahasiswa(Mahasiswa* mhs[], int jumlah);
void urutkanMahasiswa(Mahasiswa* mhs[], int jumlah);

int main() {
    const int MAX = 10;
    Mahasiswa* mahasiswa[MAX];
    int jumlah = 0;

    tambahMahasiswa(mahasiswa, jumlah);
    tambahMahasiswa(mahasiswa, jumlah);
    tampilkanMahasiswa(mahasiswa, jumlah);
    urutkanMahasiswa(mahasiswa, jumlah);
    tampilkanMahasiswa(mahasiswa, jumlah);
    hapusMahasiswa(mahasiswa, jumlah, "12345");
    tampilkanMahasiswa(mahasiswa, jumlah);

    return 0;
}

void tambahMahasiswa(Mahasiswa* mhs[], int &jumlah) {
    if (jumlah < 10) {
        mhs[jumlah] = new Mahasiswa;
        cout << "Masukkan NIM: ";
        cin >> mhs[jumlah]->NIM;
        cout << "Masukkan Nama: ";
        cin >> mhs[jumlah]->nama;
        cout << "Masukkan IPK: ";
        cin >> mhs[jumlah]->IPK;
        jumlah++;
    } else {
        cout << "Data penuh!\n";
    }
}

void hapusMahasiswa(Mahasiswa* mhs[], int &jumlah, string nim) {
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i]->NIM == nim) {
            delete mhs[i];
            for (int j = i; j < jumlah - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            jumlah--;
            cout << "Data dengan NIM " << nim << " berhasil dihapus.\n";
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void tampilkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    cout << "Data Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << mhs[i]->NIM << " - " << mhs[i]->nama << " - " << mhs[i]->IPK << endl;
    }
}

void urutkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mhs[j]->IPK > mhs[j + 1]->IPK) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan IPK.\n";
}
