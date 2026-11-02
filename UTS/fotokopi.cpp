// UTS Praktikum Paket B: Fotokopi Kampus.
// Lengkapi TODO 1 sampai TODO 6 sesuai lembar soal. Bagian yang sudah ada jangan diubah kecuali diminta.
// Bangun dengan baseline kelas; program harus bebas warning. Uji dengan: ./fotokopi < contoh_masukan.txt
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int HARGA_KECIL = 300;     // 1 sampai 50 halaman
    const int HARGA_SEDANG = 250;    // 51 sampai 200 halaman
    const int HARGA_BESAR = 200;     // lebih dari 200 halaman
    const int BATAS_KECIL = 50;
    const int BATAS_SEDANG = 200;
    const int MAKS_HALAMAN = 1000;

    int jumlah = 0;
    cout << "=== Fotokopi Kampus ===\n";
    cout << "Jumlah pesanan: ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {          // contoh pembacaan aman; pakai pola ini untuk halaman
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah pesanan: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total_halaman = 0;
    int total_pendapatan = 0;
    int banyak_kecil = 0;
    int banyak_sedang = 0;
    int banyak_besar = 0;

    // TODO 5a: deklarasikan penampung biaya terbesar (mulai -1) dan nama pemesannya.
    int biaya_terbesar = -1;
    string nama_terbesar = "";

    for (int i = 1; i <= jumlah; i++) {
        string nama;
        int halaman = 0;
        char warna = ' ';

        cout << "\n--- Pesanan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca nama dengan getline sampai sah (tidak kosong atau hanya spasi, dan tanpa angka),
        //         lalu rapikan menjadi Huruf Besar Di Awal Kata.
        //         Pesan penolakan: "Nama tidak boleh kosong." dan "Nama tidak boleh mengandung angka."
        bool nama_sah = false;
        do {
            cout << "Nama pemesan : ";
            getline(cin, nama);

            bool ada_karakter = false;
            for (size_t j = 0; j < nama.length(); j++) {
                if (nama[j] != ' ' && nama[j] != '\t') {
                    ada_karakter = true;
                    break;
                }
            }

            if (!ada_karakter) {
                cout << "Nama tidak boleh kosong.\n";
                continue;
            }

            bool ada_angka = false;
            for (size_t j = 0; j < nama.length(); j++) {
                if (nama[j] >= '0' && nama[j] <= '9') {
                    ada_angka = true;
                    break;
                }
            }

            if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
                continue;
            }

            nama_sah = true;
        } while (!nama_sah);

        bool awal_kata = true;
        for (size_t j = 0; j < nama.length(); j++) {
            if (nama[j] == ' ' || nama[j] == '\t') {
                awal_kata = true;
            } else if (awal_kata) {
                if (nama[j] >= 'a' && nama[j] <= 'z') {
                    nama[j] = nama[j] - 32;
                }
                awal_kata = false;
            } else {
                if (nama[j] >= 'A' && nama[j] <= 'Z') {
                    nama[j] = nama[j] + 32;
                }
            }
        }

        // TODO 2: baca halaman dengan aman (bilangan bulat 1 sampai MAKS_HALAMAN), pola seperti jumlah di atas.
        //         Pesan penolakan: "Harus bilangan bulat 1 sampai 1000. Halaman: "
        cout << "Halaman (1-" << MAKS_HALAMAN << "): ";
        cin >> halaman;
        while (cin.fail() || halaman < 1 || halaman > MAKS_HALAMAN) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harus bilangan bulat 1 sampai 1000. Halaman: ";
            cin >> halaman;
        }

        // TODO 3: baca warna (char), jadikan huruf besar, ulangi selama bukan 'Y' atau 'T'.
        //         Pesan penolakan: "Hanya Y atau T. Berwarna (Y/T): "
        cout << "Berwarna (Y/T): ";
        cin >> warna;
        if (warna >= 'a' && warna <= 'z') {
            warna = warna - 32;
        }
        while (cin.fail() || (warna != 'Y' && warna != 'T')) {
            cin.ignore(1000, '\n');
            cout << "Hanya Y atau T. Berwarna (Y/T): ";
            cin >> warna;
            if (warna >= 'a' && warna <= 'z') {
                warna = warna - 32;
            }
        }
        cin.ignore(1000, '\n');

        // TODO 4: tentukan harga per halaman dari jumlah halaman (kecil, sedang, besar) dan tambah
        //         penghitung kategorinya; biaya = halaman * harga, dikali 2 bila berwarna.
        int harga_per_lembar = 0;
        if (halaman <= BATAS_KECIL) {
            harga_per_lembar = HARGA_KECIL;
            banyak_kecil++;
        } else if (halaman <= BATAS_SEDANG) {
            harga_per_lembar = HARGA_SEDANG;
            banyak_sedang++;
        } else {
            harga_per_lembar = HARGA_BESAR;
            banyak_besar++;
        }

        int biaya = halaman * harga_per_lembar;
        if (warna == 'Y') {
            biaya *= 2;
        }

        cout << "  " << left << setw(16) << nama << right << setw(6) << halaman;
        if (warna == 'Y') {
            cout << setw(7) << "Warna";
        } else {
            cout << setw(7) << "Hitam";
        }
        cout << setw(9) << biaya << "\n";

        total_halaman += halaman;
        total_pendapatan += biaya;

        // TODO 5b: perbarui biaya terbesar dan nama pemesannya bila biaya ini lebih besar.
        if (biaya > biaya_terbesar) {
            biaya_terbesar = biaya;
            nama_terbesar = nama;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah pesanan    : " << jumlah << "\n";
    cout << "Total halaman     : " << total_halaman << "\n";
    cout << "Total pendapatan  : " << total_pendapatan << "\n";
    cout << "Rata-rata halaman : " << static_cast<double>(total_halaman) / jumlah << "\n";

    // TODO 5c: cetak "Terbesar          : " diikuti nama dan biaya terbesar dalam kurung.
    cout << "Terbesar          : " << nama_terbesar << " (" << biaya_terbesar << ")\n";

    cout << "\nSebaran ukuran pesanan:\n";
    // TODO 6: tiga baris batang (Kecil, Sedang, Besar) memakai perulangan bersarang:
    //         perulangan luar memilih label dan jumlahnya, perulangan dalam mencetak tanda # sebanyak itu.
    //         Format tiap baris: label rata kiri selebar 7, lalu "| ", batang, spasi, jumlah. Contoh: "Kecil  | ## 2"
    const string labels[3] = {"Kecil", "Sedang", "Besar"};
    const int counts[3] = {banyak_kecil, banyak_sedang, banyak_besar};

    for (int k = 0; k < 3; k++) {
        cout << left << setw(7) << labels[k] << "| ";
        for (int b = 0; b < counts[k]; b++) {
            cout << "#";
        }
        cout << " " << counts[k] << "\n";
    }

    return 0;
}