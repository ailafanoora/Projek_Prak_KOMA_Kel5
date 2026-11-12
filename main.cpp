#include<iostream>
#include<string>
using namespace std;

struct Kegiatan {
    string id;
    string nama;
    string kategori;
    int biaya;
    int sisaHari;
};
// 1. Cek status kegiatan (SOON jika <= 7 hari, UPCOMING jika > 7 hari)
string cekStatus(int sisaHari) {
    if (sisaHari <= 7) {
        return "SOON";
    }
    return "UPCOMING";
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
    return total / jumlah;
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
// LANJUT ANGGOTA 4 (SORTING & SEARCHING)
// Tugas: Bikin fungsi urutkan kegiatan (biaya/sisaHari) & cari kegiatan
//        (budget/nama/kategori) di bawah baris ini.
// =========================================================================
// =========================================================================
// LANJUT ANGGOTA 1 (COORDINATOR / MAIN MENU)
// Tugas: Bikin tampilan Menu Utama (1-4) & panggil semua fungsi di atas.
// =========================================================================
int main() {
    Kegiatan daftarTersedia[100];
    int jumlahTersedia = 0;

    Kegiatan daftarDiikuti[100];
    int jumlahDiikuti = 0;
// =========================================================================
// LANJUTIN KODENYA DI BAWAH INI OLEH ANGGOTA 1 (COORDINATOR)
// Tugas: Bikin tampilan Main Menu (pilihan 1-4), perulangan menu, dan 
//        panggil semua fungsi milik Anggota 2, Anggota 3, & Anggota 4 di sini.
// =========================================================================
return 0;
}
