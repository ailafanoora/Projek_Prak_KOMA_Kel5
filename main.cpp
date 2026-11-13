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

// 11. Fungsi untuk search ID kegiatan yang diikuti ada dan sesuai dengan ID list kegiatan tersedia
bool cekIDdiikuti(Kegiatan daftar[], Kegiatan daftarDiikuti[], int jumlahDiikuti, int jumlah, string IDdiikuti, int indexDiikuti) {
    bool IDsesuai = false;
        for(int j = 0; j < jumlah; j++) {
            if (IDdiikuti == daftar[j].id) {
                daftarDiikuti[indexDiikuti] = daftar[j];
                return IDsesuai = true;
            }
    } 
    return IDsesuai = false;
}

// 12. Fungsi untuk menambah kegiatan yang diikuti (input ID kegiatan untuk mempermudah penulisan serta menghindari typo atau ketidaksesuaian penulisan)
void tambahDiikuti(Kegiatan daftar[], Kegiatan daftarDiikuti[], int &jumlahDiikuti, int jumlah, string IDdiikuti) {
    cout << "Masukkan jumlah kegiatan yang akan diikuti: ";
    cin >> jumlahDiikuti;
    for (int i = 0; i < jumlahDiikuti; i++) {
        cout << "Masukkan ID kegiatan ke-" << i+1 << " : ";
        cin >> IDdiikuti;
        bool IDsesuai = cekIDdiikuti(daftar, daftarDiikuti, jumlahDiikuti, jumlah, IDdiikuti, i);
        if (IDsesuai = false) {
            cout << "Tidak ditemukan kegiatan dengan ID: " << IDdiikuti << endl;
            cout << "Harap ulangi lagi." << endl;
            cout << "Masukkan ID kegiatan ke-" << i+1 << " : ";
            cin >> IDdiikuti;
        }
    }
}

// 13. Fungsi untuk menampilkan data kegiatan yang diikuti
void tampilDiikuti(Kegiatan daftarDiikuti[], int jumlahDiikuti) {
    cout << "========== LIST KEGIATAN YANG DIIKUTI ==========" << endl;
     cout << "ID \tNama \tKategori \tBiaya \tSisa Hari \tStatus  " << endl;
    for (int i = 0; i < jumlahDiikuti; i++) {
        cout << daftarDiikuti[i].id << "\t" << daftarDiikuti[i].nama << "\t" << daftarDiikuti[i].kategori << "\t" << daftarDiikuti[i].biaya << "\t" << daftarDiikuti[i].sisaHari << "\t" << daftarDiikuti[i].status << endl;
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
void mainmenu(){
        cout << "==================================================\n";
        cout << "        CAMPUS EVENT & STUDENT ACTIVITY FINDER    \n";
        cout << "==================================================\n";
        cout << "1. Tambahkan Kegiatan\n";
        cout << "2. List Kegiatan Tersedia\n";
        cout << "3. List Kegiatan Yang Diikuti\n";
        cout << "4. Cari Kegiatan\n";
        cout << "0. Exit\n";
        cout << "==================================================\n";
        cout << "Pilih Menu: ";
}

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main() {// Inisialisasi array di int main dengan ukuran 100 sebagai penampung awal
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
    string IDdiikuti;
    
    int pilihan = 0;
    int opsiListKegiatan = 0;
    int opsiSort = 0;
    
    do {
        clearTerminal();
        mainmenu();

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();

        switch (pilihan){
            case 0: 
            cout << "Program berhenti." << endl;
            break;
            case 1:
            clearTerminal();
            tambahKegiatan(daftar, jumlah);    
            IDGenerator(daftar, seminar, kompetisi, jumlah);
            cekStatus(daftar, jumlah);
            break;
            
            case 2:
            tampilData(daftar, jumlah);
            cout << "Jumlah kegiatan: " << jumlah << endl;
            cout << "Rata-rata biaya: " << hitungRataRata(daftar, jumlah) << endl;
            cout << "Biaya termahal: " << cariTermahal(daftar, jumlah) << endl;
            cout << "Biaya termurah: " << cariTermurah(daftar, jumlah) << endl;
            cout << endl;
            do {
                cout << "Pilih Opsi List Kegiatan: " << endl;
                cout << "1. Sort Kegiatan\n";
                cout << "2. Tambahkan Kegiatan yang Diikuti\n";
                cout << "3. Kembali ke Menu Utama\n";
                cin >> opsiListKegiatan;
                switch(opsiListKegiatan) {
                    case 3: cout << "Kembali ke menu utama" << endl;
                    break;
                    case 1: 
                    cout << "Pilih Opsi Sort: " << endl;
                    cout << "1. Biaya (Ascending)\n";
                    cout << "2. Biaya (Desecending)\n";
                    cout << "3. Sisa Hari (Ascending)\n";
                    cout << "4. Sisa Hari (Descending)\n";
                    cout << "5. Kembali ke Menu List Kegiatan\n";
                    cout << "6. Kembali ke Menu Utama\n";
                    cin >> opsiSort;
                    do {
                        switch(opsiSort) {
                            case 6: cout << "Kembali ke menu utama" << endl;
                            break;
                            case 5: cout << "Kembali ke Menu List Kegiatan" << endl;
                            break;
                            // case 1: Panggil fungsi sortBiayaAscend(); 
                            // case 2: Panggil fungsi sortBiayaDescend(); 
                            // case 3: Panggil fungsi sortSisaHariAscend(); 
                            // case 4: Panggil fungsi sortSisaHariDescend(); 
                            default: cout << "Pilihan tidak valid. Harap ulangi lagi" << endl;
                        }
                    } while (opsiSort != 5);
                    break;
                    
                    case 2: tambahDiikuti(daftar, daftarDiikuti, jumlahDiikuti, jumlah, IDdiikuti);
                    break; 
                    
                    default: cout << "Pilihan tidak valid. Harap ulangi lagi" << endl;
                }
            } while (opsiListKegiatan != 3 && opsiSort != 6);
            break;
            
            case 3:
            tampilDiikuti(daftarDiikuti, jumlahDiikuti);
            cout << "Jumlah kegiatan yang diiikuti: " << jumlahDiikuti << endl;
            cout << "Total biaya kegiatan yang diikuti: " << hitungTotalBiaya(daftarDiikuti, jumlahDiikuti) << endl;
            break;
            
            //case 4:
            //cariKegiatan();             break;
            default: cout << "Pilihan tidak valid. Harap ulangi lagi" << endl;
        }
    } while (pilihan != 0);
    
    
// =========================================================================
// LANJUTIN KODENYA DI BAWAH INI OLEH ANGGOTA 1 (COORDINATOR)
// Tugas: Bikin tampilan Main Menu (pilihan 1-4), perulangan menu, dan 
//        panggil semua fungsi milik Anggota 2, Anggota 3, & Anggota 4 di sini.
// =========================================================================
    return 0;
}
