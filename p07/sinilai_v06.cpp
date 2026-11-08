// Pertemuan 7: SiNilai v0.6 - Laporan Kelas yang Tangguh terhadap Masukan Berantakan
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    int jumlah_mahasiswa = 0;

    // TODO 1: Membaca jumlah mahasiswa dengan aman (pola input_aman)
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;
    while (cin.fail() || jumlah_mahasiswa < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah mahasiswa: ";
        cin >> jumlah_mahasiswa;
    }
    cin.ignore(1000, '\n'); // Membuang sisa Enter setelah angka

    int total_lulus = 0;
    int total_belum_lulus = 0;
    double akumulasi_nilai_akhir = 0.0;
    
    double nilai_tertinggi = -1.0;
    string nama_tertinggi = "";
    int sebaran_huruf[5] = {0, 0, 0, 0, 0}; // A, B, C, D, E

    for (int k = 1; k <= jumlah_mahasiswa; k++) {
        string nama;
        string npm;
        double kehadiran = 0, mingguan = 0, uts = 0, uas = 0;

        cout << "\n--- Mahasiswa ke-" << k << " dari " << jumlah_mahasiswa << " ---\n";

        // TODO 2: Membaca dan memvalidasi nama (tidak boleh kosong/hanya spasi, tidak boleh ada angka)
        bool nama_sah = false;
        do {
            cout << "Nama\t\t: ";
            getline(cin, nama);

            int panjang = nama.length();
            bool ada_huruf = false;
            bool ada_angka = false;

            for (int i = 0; i < panjang; i++) {
                if (nama[i] != ' ' && nama[i] != '\t') {
                    ada_huruf = true;
                }
                if (isdigit(nama[i])) {
                    ada_angka = true;
                }
            }

            if (!ada_huruf) {
                cout << "Nama tidak boleh kosong.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            } else {
                nama_sah = true;
            }
        } while (!nama_sah);

        // TODO 3: Merapikan nama menjadi Huruf Besar Di Awal Kata
        int panjang_nama = nama.length();
        bool awal_kata = true;
        for (int i = 0; i < panjang_nama; i++) {
            if (nama[i] == ' ' || nama[i] == '\t') {
                awal_kata = true;
            } else if (awal_kata) {
                nama[i] = toupper(nama[i]);
                awal_kata = false;
            } else {
                nama[i] = tolower(nama[i]);
            }
        }

        // Membaca NPM
        cout << "NPM\t\t: ";
        getline(cin, npm);

        // TODO 4: Membaca kehadiran dengan aman (0 - 100)
        cout << "Kehadiran\t: ";
        cin >> kehadiran;
        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Kehadiran : ";
            cin >> kehadiran;
        }
        cin.ignore(1000, '\n');

        // TODO 5: Membaca Mingguan, UTS, dan UAS dengan pola aman yang sama
        cout << "Mingguan\t: ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0 || mingguan > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. Mingguan : ";
            cin >> mingguan;
        }
        cin.ignore(1000, '\n');

        cout << "UTS\t\t: ";
        cin >> uts;
        while (cin.fail() || uts < 0 || uts > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. UTS : ";
            cin >> uts;
        }
        cin.ignore(1000, '\n');

        cout << "UAS\t\t: ";
        cin >> uas;
        while (cin.fail() || uas < 0 || uas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus angka 0 sampai 100. UAS : ";
            cin >> uas;
        }
        cin.ignore(1000, '\n');

        // Perhitungan nilai akhir (bobot sesuai versi v0.5)
        double nilai_akhir = (kehadiran * 0.10) + (mingguan * 0.20) + (uts * 0.30) + (uas * 0.40);
        akumulasi_nilai_akhir += nilai_akhir;

        // Menentukan Huruf Mutu
        char huruf_mutu = 'E';
        int indeks_sebaran = 4;
        if (nilai_akhir >= 80) { huruf_mutu = 'A'; indeks_sebaran = 0; }
        else if (nilai_akhir >= 70) { huruf_mutu = 'B'; indeks_sebaran = 1; }
        else if (nilai_akhir >= 60) { huruf_mutu = 'C'; indeks_sebaran = 2; }
        else if (nilai_akhir >= 50) { huruf_mutu = 'D'; indeks_sebaran = 3; }
        
        sebaran_huruf[indeks_sebaran]++;

        // Status Kelulusan
        bool status_lulus = (huruf_mutu != 'D' && huruf_mutu != 'E');
        if (status_lulus) {
            total_lulus++;
        } else {
            total_belum_lulus++;
        }

        // Cek Nilai Tertinggi
        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }

        // Cetak hasil per mahasiswa
        cout << fixed << setprecision(2);
        cout << nama << " " << nilai_akhir << " " << huruf_mutu << " " << (status_lulus ? "Lulus" : "Belum lulus") << "\n";
    }

    // Laporan Kelas Akhir
    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << total_lulus << "\n";
    cout << "Belum lulus      : " << total_belum_lulus << "\n";
    
    if (jumlah_mahasiswa > 0) {
        cout << "Rata-rata kelas  : " << (akumulasi_nilai_akhir / jumlah_mahasiswa) << "\n";
        cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";
    }

    cout << "Sebaran huruf mutu:\n";
    char daftar_huruf[5] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 5; i++) {
        cout << daftar_huruf[i] << " : " << sebaran_huruf[i] << "\n";
    }

    return 0;
}