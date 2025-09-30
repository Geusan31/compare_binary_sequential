#include <vector>
using namespace std;

int binary_search(const vector<int> &data, int target)
{
    int low = 0;
    int high = data.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == target)
        {
            return mid;
        }
        else if (data[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
