#include <vector> // untuk menggunakan array dinamis
using namespace std;
// 
int binary_search(const vector<int> &data, int target) // menerima parameter berupa array dinamis dan target yang dicari
{
    int low = 0;                // Membuat variabel low yang menandai batas paling kiri dari area pencarian
    int high = data.size() - 1; // Membuat variabel high yang menandai batas paling kanan dari area pencarian

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Di dalam setiap loop, selalu mencari indeks tengah dari area pencarian saat ini (low sampai high).
        if (data[mid] == target)          // Jika elemen yang ada di posisi tengah (data[mid]) sama dengan target yang kita cari.
        {
            return mid; // kembalikan indeks mid yang udah ketemu
        }
        else if (data[mid] < target) // jika elemen tengah lebih kecil dari target, artinya target pasti berada di sebelah kanan dari mid (karena datanya terurut).
        {
            low = mid + 1; // Maka, kita geser batas paling kiri (low) ke kanan, tepat setelah mid.
        }
        else
        {
            high = mid - 1; // Jika tidak ada kondisi di atas yang terpenuhi, berarti elemen tengah lebih besar dari target. Artinya, target pasti ada di sebelah kiri dari mid.
        }
    }
    return -1;
}
