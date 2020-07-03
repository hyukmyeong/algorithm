#include <iostream>
#include <vector>
#include <algorithm>

int data[N];
bool brute_force(int index)
{
    if (some_condition)
        return true;

    for (int i = 0; i < 3; ++i) {
        brute_force(next)
    }
}

int data[N];
bool divide_and_conquer(int low, int high)
{
    if (some_condition)
        return true;

    int 1_3 = high / 3;
    int 2_3 = high / 3 * 2;

    bool res1 = divide_and_conquer(data, low, 1_3);
    bool res2 = divide_and_conquer(data, 1_3, 2_3);
    bool res3 = divide_and_conquer(data, 2_3, high);

    return res1 || res2 || res3;
}
