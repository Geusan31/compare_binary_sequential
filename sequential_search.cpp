#include "sequential_search.h" // include header file
#include <vector>              // agar bisa menggunakan array dinmais
using namespace std;

int sequential_search(const vector<int> &data, int target) // menerima parameter berupa array dinamis dan target yang dicari
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] == target) // jika data pada index i sama dengan target
        {
            return i; // kembalikan index i
        }
    }
    return -1; // jika tidak ditemukan, kembalikan -1
}