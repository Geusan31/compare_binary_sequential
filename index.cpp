#include <iostream>  // ini agar bisa input dan output menggunakan cin dan cout
#include <vector>    // ini agar bisa membuat array lebih fleksibel/dinamis
#include <algorithm> // ini agar bisa menggunakan fungsi sort

#include "sequential_search.cpp"
#include "binary_search.cpp"

using namespace std;

int main()
{

    const int PERULANGAN = 50000;          // Jumlah pengulangan
    vector<int> sizes = {32, 1024, 32764}; // membuat array dinamis untuk ukuran data yang akan diuji

    for (int n : sizes)
    {
        cout << "\n--- Hasil untuk Ukuran Data: " << n << " ---" << endl;

        vector<int> numbers; // array dinamis untuk menyimpan data
        for (int i = 0; i < n; ++i)
        {
            numbers.push_back(rand() % (n * 10)); //  Menambahkan elemen baru ke akhir
        }
        int x = numbers[rand() % n];          // Menghasilkan sebuah angka acak.
        sort(numbers.begin(), numbers.end()); // Mengurutkan data agar bisa digunakan pada binary search

        clock_t start_seq = clock(); // Mencatat "waktu" CPU saat ini dan menyimpannya ke variabel start_seq.
        for (int i = 0; i < PERULANGAN; ++i)
        {
            sequential_search(numbers, x);
        }
        clock_t end_seq = clock();                                             // Mencatat "waktu" CPU lagi setelah loop selesai. Ini adalah titik akhir "stopwatch".
        double total_waktu_seq = double(end_seq - start_seq) / CLOCKS_PER_SEC; // Menghitung total waktu yang berlalu. (waktu akhir - waktu awal) dibagi sama CLOCKS_PER_SEC (konstanta buat ngubah "tik" CPU menjadi detik).

        // sama kayak di atas, tapi untuk binary search
        clock_t start_bin = clock();
        for (int i = 0; i < PERULANGAN; ++i)
        {
            binary_search(numbers, x);
        }
        clock_t end_bin = clock();
        double total_waktu_bin = double(end_bin - start_bin) / CLOCKS_PER_SEC;

        cout << "Sequential Search butuh waktu: " << total_waktu_seq << " detik" << endl;
        cout << "Binary Search butuh waktu:   " << total_waktu_bin << " detik" << endl;
    }
    return 0;
}