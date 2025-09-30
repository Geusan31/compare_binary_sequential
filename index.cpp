#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

#include "sequential_search.cpp"
#include "binary_search.cpp"

int main()
{
    srand(time(0));

    const int PERULANGAN = 500000;

    std::vector<int> sizes = {32, 1024};

    std::cout << "Tabel Komparasi Waktu Eksekusi TOTAL (" << PERULANGAN << " kali perulangan)" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "| " << std::left << std::setw(20) << "Ukuran Data (n)"
              << "| " << std::left << std::setw(20) << "Sequential Search"
              << "| " << std::left << std::setw(20) << "Binary Search" << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    for (int n : sizes)
    {
        std::vector<int> numbers;
        for (int i = 0; i < n; ++i)
        {
            numbers.push_back(rand() % (n * 10));
        }
        int x = numbers[rand() % n];
        std::sort(numbers.begin(), numbers.end());

        clock_t start_seq = clock();

        for (int i = 0; i < PERULANGAN; ++i)
        {
            sequential_search(numbers, x);
        }

        clock_t end_seq = clock();

        double total_waktu_seq = double(end_seq - start_seq) / CLOCKS_PER_SEC;

        clock_t start_bin = clock();
        for (int i = 0; i < PERULANGAN; ++i)
        {
            binary_search(numbers, x);
        }
        clock_t end_bin = clock();
        double total_waktu_bin = double(end_bin - start_bin) / CLOCKS_PER_SEC;

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "| " << std::left << std::setw(20) << n
                  << "| " << std::left << std::setw(20) << total_waktu_seq
                  << "| " << std::left << std::setw(20) << total_waktu_bin << " |" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------" << std::endl;

    return 0;
}