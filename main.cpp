#include<iostream>
#include<string>
using namespace std;

struct Kegiatan {
    string id;
    string nama;
    string kategori;
    int biaya;
    int sisaHari;
    string status;
};

// 1. Cek status kegiatan (SOON jika <= 7 hari, UPCOMING jika > 7 hari)
void cekStatus(Kegiatan daftar[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].sisaHari <= 7) {
            daftar[i].status = "SOON";
        } else {
            daftar[i].status = "UPCOMING";
        }
    }
}
// 2. Cari biaya kegiatan paling mahal
int cariTermahal(Kegiatan daftar[], int jumlah) {
    if (jumlah == 0) return 0;
    int mahal = daftar[0].biaya;
    for (int i = 1; i < jumlah; i++) {
        if (daftar[i].biaya > mahal) {
            mahal = daftar[i].biaya;
        }
    }
    return mahal;
}
// 3. Cari biaya kegiatan paling murah
int cariTermurah(Kegiatan daftar[], int jumlah) {
    if (jumlah == 0) return 0;
    int murah = daftar[0].biaya;
    for (int i = 1; i < jumlah; i++) {
        if (daftar[i].biaya < murah) {
            murah = daftar[i].biaya;
        }
    }
    return murah;
}
// 4. Hitung rata-rata biaya seluruh kegiatan
int hitungRataRata(Kegiatan daftar[], int jumlah) {
    if (jumlah == 0) return 0;
    int total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += daftar[i].biaya;
    }
    return static_cast<double>(total) / jumlah;
}
// 5. Fungsi Rekursif: Menghitung total biaya dari N kegiatan yang diikuti
int hitungTotalBiaya(Kegiatan diikuti[], int n) {
    if (n <= 0) {
        return 0;
    }
    return diikuti[n - 1].biaya + hitungTotalBiaya(diikuti, n - 1);
}
// =========================================================================
// LANJUT ANGGOTA 2 (DATA & CORE LOGIC)
// Tugas: Bikin fungsi input tambah kegiatan, tampilkan tabel list kegiatan,
//        dan fungsi daftar/ikuti kegiatan di bawah baris ini.
// =========================================================================
// =========================================================================

// 6. Fungsi untuk input dan menambah kegiatan, meliputi jenis, nama, biaya, sisa hari
void tambahKegiatan(Kegiatan daftar[], int &jumlah) {
    cout << "Masukkan jumlah kegiatan yang akan ditambahkan: ";
    cin >> jumlah;
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan jenis kegiatan (seminar/kompetisi) (gunakan huruf kecil) ke-" << i+1 << " : ";
        cin >> daftar[i].kategori;
        cin.ignore();
        cout << "Masukkan nama kegiatan ke-" << i+1 << " : ";
        getline(cin, daftar[i].nama);
        cout << "Masukkan biaya kegiatan ke-" << i+1 << " : ";
        cin >> daftar[i].biaya;
        if (daftar[i].biaya < 0) {
            cout << "Biaya tidak boleh negatif. Harap ulangi lagi" << endl;
            cout << "Masukkan biaya kegiatan ke-" << i+1 << " : ";
            cin >> daftar[i].biaya;
        }
        cout << "Masukkan sisa hari kegiatan ke-" << i+1 << " : ";
        cin >> daftar[i].sisaHari;
        if (daftar[i].sisaHari < 0) {
            cout << "Sisa hari tidak boleh negatif. Harap ulangi lagi" << endl;
            cout << "Masukkan sisa hari kegiatan ke-" << i+1 << " : ";
            cin >> daftar[i].sisaHari;
        }
        cout << endl;
    }
}

// 7. Fungsi untuk menghitung jumlah kegiatan seminar
int jumlahKegiatanSeminar(Kegiatan daftar[], Kegiatan seminar[], int jumlah, int jumlahSeminar) {
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].kategori == "seminar") {
            jumlahSeminar++;
            seminar[i] = daftar[i];
        }
    }
    return jumlahSeminar;
}

// 8. Fungsi untuk menghitung jumlah kegiatan kompetisi
int jumlahKegiatanKompetisi(Kegiatan daftar[], Kegiatan kompetisi[], int jumlah, int jumlahKompetisi) {
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].kategori == "kompetisi") {
            jumlahKompetisi++;
            kompetisi[i] = daftar[i];
        }
    }
    return jumlahKompetisi;
}

// 9. Fungsi untuk membuat ID kegiatan
void IDGenerator(Kegiatan daftar[], Kegiatan seminar[], Kegiatan kompetisi[], int jumlah) {
    string IDjenisKegiatan;
    string IDindex;
    int urutanSeminar = 0;
    int urutanKompetisi = 0;
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].kategori == "seminar") {
            IDjenisKegiatan = "01";
            if (urutanSeminar < 9) {
                IDindex = "00" + to_string(urutanSeminar + 1);
            } else if (urutanSeminar < 99) {
                IDindex = "0" + to_string(urutanSeminar + 1);
            } else if (urutanSeminar < 999) {
                IDindex = to_string(urutanSeminar + 1);
            }
            seminar[urutanSeminar].id = IDjenisKegiatan + IDindex;
            daftar[i].id = seminar[urutanSeminar].id;
            urutanSeminar++;
        } else if (daftar[i].kategori == "kompetisi") {
            IDjenisKegiatan = "02";
            if (urutanKompetisi < 9) {
                IDindex = "00" + to_string(urutanKompetisi + 1);
            } else if (urutanKompetisi < 99) {
                IDindex = "0" + to_string(urutanKompetisi + 1);
            } else if (urutanKompetisi < 999) {
                IDindex = to_string(urutanKompetisi + 1);
            }
            kompetisi[urutanKompetisi].id = IDjenisKegiatan + IDindex;
            daftar[i].id = kompetisi[urutanKompetisi].id;
            urutanKompetisi++;
        }
    }
}

// 10. Fungsi untuk menampilkan data kegiatan
void tampilData(Kegiatan daftar[], int jumlah) {
    cout << "========== LIST KEGIATAN TERSEDIA ==========" << endl;
     cout << "ID \tNama \tKategori \tBiaya \tSisa Hari \tStatus  " << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << daftar[i].id << "\t" << daftar[i].nama << "\t" << daftar[i].kategori << "\t" << daftar[i].biaya << "\t" << daftar[i].sisaHari << "\t" << daftar[i].status << endl;
    }
}
// LANJUT ANGGOTA 4 (SORTING & SEARCHING)
// Tugas: Bikin fungsi urutkan kegiatan (biaya/sisaHari) & cari kegiatan
//        (budget/nama/kategori) di bawah baris ini.
// =========================================================================
// =========================================================================
// LANJUT ANGGOTA 1 (COORDINATOR / MAIN MENU)
// Tugas: Bikin tampilan Menu Utama (1-4) & panggil semua fungsi di atas.
// =========================================================================
int main() {
    // Inisialisasi array di int main dengan ukuran 100 sebagai penampung awal
    Kegiatan daftar[100];
    int jumlah = 0;
    
    Kegiatan seminar[100];
    int jumlahSeminar = 0;
    
    Kegiatan kompetisi[100];
    int jumlahKompetisi = 0;
    
    Kegiatan daftarTersedia[100];
    int jumlahTersedia = 0;

    Kegiatan daftarDiikuti[100];
    int jumlahDiikuti = 0;

    tambahKegiatan(daftar, jumlah); // Panggil fungsi input data kegiatan
    IDGenerator(daftar, seminar, kompetisi, jumlah); // Panggil fungsi untuk generate ID kegiatan;
    cekStatus(daftar, jumlah); // Panggil fungsi untuk menenrukan status kegiatan
    tampilData(daftar, jumlah); // Panggil fungsi tampilkan list data
    
    
// =========================================================================
// LANJUTIN KODENYA DI BAWAH INI OLEH ANGGOTA 1 (COORDINATOR)
// Tugas: Bikin tampilan Main Menu (pilihan 1-4), perulangan menu, dan 
//        panggil semua fungsi milik Anggota 2, Anggota 3, & Anggota 4 di sini.
// =========================================================================
    return 0;
}
