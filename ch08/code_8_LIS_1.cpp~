#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int n = 501;
int cache[501];
int S[500];

int lis(int start)
{
    int& ret = cache[start + 1];

    if (ret != -1)
        return ret;

    ret = 1;

    for (int next = start + 1; next < n; ++next) {
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    }

    return ret;
}


int main()
{
    int C, N;
    vector<vector<int>> A;

    cin >> C;
    while (C-- > 0) {
        int num;
        vector<int> B;

        cin >> N;

        while (N-- > 0) {
            cin >> num;
            B.push_back(num);
        }
        A.push_back(B);
    }

    for (auto&& item : A) {
        memset(cache, -1, sizeof(cache));
        memset(S, -1, sizeof(S));
        copy(item.begin(), item.end(), S);

        cout << lis(-1) - 1 << endl;
    }

    return 0;
}
