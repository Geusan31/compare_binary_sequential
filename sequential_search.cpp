#include "sequential_search.h"
#include <vector>
using namespace std;

int sequential_search(const vector<int> &data, int target)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] == target)
        {
            return i;
        }
    }
    return -1;
}