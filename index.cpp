#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <chrono>

#include "sequential_search.cpp"
#include "binary_search.cpp"

using namespace std;

int main() {
    srand(time(0));
    vector<int> sizes = {32, 1024, 65536};
    
    const int REPETITIONS = 50000;

    cout << "Tabel Komparasi Waktu Eksekusi Rata-Rata (dalam nanodetik)" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| " << left << setw(20) << "Ukuran Data (n)"
              << "| " << left << setw(20) << "Sequential Search"
              << "| " << left << setw(20) << "Binary Search" << " |" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (int n : sizes) {
        vector<int> numbers;
        for (int i = 0; i < n; ++i) {
            numbers.push_back(rand() % (n * 10));
        }

        int x = numbers[rand() % n];
        sort(numbers.begin(), numbers.end());
        
        auto start_seq = chrono::high_resolution_clock::now();
        for(int i = 0; i < REPETITIONS; ++i) {
            volatile int result = sequential_search(numbers, x);
        }
        auto end_seq = chrono::high_resolution_clock::now();
        long long duration_seq_total = chrono::duration_cast<chrono::nanoseconds>(end_seq - start_seq).count();
        double avg_time_seq = (double)duration_seq_total / REPETITIONS;


        auto start_bin = chrono::high_resolution_clock::now();
        for(int i = 0; i < REPETITIONS; ++i) {
            volatile int result = binary_search(numbers, x);
        }
        auto end_bin = chrono::high_resolution_clock::now();
        long long duration_bin_total = chrono::duration_cast<chrono::nanoseconds>(end_bin - start_bin).count();
        double avg_time_bin = (double)duration_bin_total / REPETITIONS;


        cout << fixed << setprecision(2);
        cout << "| " << left << setw(20) << n
                  << "| " << left << setw(20) << avg_time_seq
                  << "| " << left << setw(20) << avg_time_bin << " |" << endl;
    }
    
    cout << "----------------------------------------------------------------------" << endl;

    return 0;
}