#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>

template <typename T>
int binarySearch(std::vector<T> &arr, T &target)
{
    static_assert(std::is_arithmetic<T>::value, "Template only accepts numerical values");
    if (arr.empty())
        return -1;
    int8_t lo = 0;
    int8_t hi = arr.size() - 1;

    while (lo <= hi)
    {
        int8_t mid = lo + (hi - lo) / 2;

        T midVal = arr[mid];

        if (midVal == target)
            return mid;
        else if (midVal > target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int main()
{
    std::vector<int> searchArr{1, 3, 6, 7, 8};
    int target{8};

    int ans = binarySearch(searchArr, target);
    assert(ans == 4);
    std::cout << "location:\t" << ans << "\n";
    return 0;
}