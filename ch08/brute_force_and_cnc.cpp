#include <iostream>
#include <vector>
#include <algorithm>

int data[N];
bool brute_force(int idx)
{
    if (some_condition)
        return true;

    int next_idx = idx + 1;
    for (int i = 0; i < 3; ++i) {
        return brute_force(next_idx);
    }
    return false;
}

int data[N];
bool divide_and_conquer(int low, int high)
{
    if (some_condition)
        return true;

    int 1_3 = high / 3;
    int 2_3 = high / 3 * 2;

    bool res1 = divide_and_conquer(low, 1_3);
    bool res2 = divide_and_conquer(1_3, 2_3);
    bool res3 = divide_and_conquer(2_3, high);

    return res1 || res2 || res3;
}
