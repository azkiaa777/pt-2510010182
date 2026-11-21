# P09 Fungsi dan Pemrograman Modular

Folder kode Pertemuan 9 Pemrograman Terstruktur, pertemuan pertama setelah UTS. Flowchart mulai memakai
simbol kelima: proses terdefinisi (persegi bergaris ganda) untuk pemanggilan fungsi; isi fungsinya digambar
sebagai flowchart tersendiri yang diawali "Mulai namaFungsi" dan diakhiri "Kembali".

## Isi

| Berkas | Kegunaan |
|---|---|
| `fungsi_dasar.cpp` | Prototipe, definisi, parameter, return; fungsi `void`; memanggil fungsi tiga kali |
| `nilai_vs_referensi.cpp` | Pass by value (salinan) vs pass by reference (`&`); `tukar(a, b)` |
| `lingkup.cpp` | Variabel lokal lahir dan mati bersama fungsinya; variabel global diubah diam-diam dari dua fungsi |
| `baca_aman.cpp` | Pelunasan utang P7: empat salinan pembacaan aman menjadi satu fungsi `bacaKomponen(label)` dan `bacaNama()` |
| `sinilai_v07_awal.cpp` | Starter SiNilai v0.7: main dan prototipe sudah jadi, tiga fungsi terisi, enam fungsi TODO diisi dari v0.6 milikmu |
| `contoh_masukan.txt` | Sama dengan Pertemuan 7 (sengaja berantakan); keluaran v0.7 harus persis sama dengan v0.6 |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Fungsi-fungsi SiNilai v0.7

| Fungsi | Parameter | Mengembalikan | Status di starter |
|---|---|---|---|
| `bacaJumlah()` | tidak ada | `int` jumlah mahasiswa yang sah | sudah diisi (contoh) |
| `bacaNama()` | tidak ada | `string` nama yang sah dan rapi | TODO 2 |
| `bacaKomponen(string label)` | label (by value) | `double` 0 sampai 100 | TODO 1 |
| `bacaData(string& nama, string& npm, double& ...)` | enam referensi | `void`; mengisi variabel main | TODO 3 |
| `hitungNilaiAkhir(double, double, double, double)` | empat komponen | `double` nilai akhir | sudah diisi (contoh) |
| `hurufMutu(double nilai_akhir)` | nilai akhir | `string` huruf | TODO 4 |
| `cetakBaris(string, double, string, bool)` | data satu mahasiswa | `void` | sudah diisi (contoh) |
| `perbaruiPenghitung(char awal, int& a, ..., int& e)` | huruf pertama dan lima referensi | `void`; menambah penghitung main | TODO 5 |
| `cetakSebaran(int a, ..., int e)` | lima penghitung (by value) | `void` | TODO 6 |

Bobot komponen ditulis sebagai konstanta global (`const`), bukan variabel global: konstanta tidak pernah
berubah sehingga aman dibaca dari fungsi mana pun.

## Yang dikumpulkan mahasiswa

Folder `p09` di repository `pt-NPM` berisi `sinilai_v07.cpp`. Lihat Modul Pertemuan 9 bagian E.

## Deklarasi AI
- Label AI: AI 1
- AI yang digunakan: Gemini
- Prompt: Meminta bantuan menyusun struktur fungsi, penggunaan parameter referensi (`bacaData` dan `perbaruiPenghitung`), serta pengecekan kompilasi dan keluaran program SiNilai v0.7.
- Umpan balik AI: AI memberikan contoh kode fungsi dan langkah pengujian terminal. Saya menyesuaikan kode pada `sinilai_v07.cpp` dan mengujinya menggunakan `contoh_masukan.txt`.