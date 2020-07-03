#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

static int g_cnt = 0;

int lis(const vector<int>& A)
{
    g_cnt++;
    if (A.empty())
        return 0;

    int ret = 0;

    for (int i = 0; i < A.size(); ++i) {

        vector<int> B;
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[i] < A[j])
                B.push_back(A[j]);
        }

        ret = max(ret, 1 + lis(B));
    }
    return ret;
}

int main()
{
    int C, N;
    cin >> C;

    vector<vector<int>> A;
    while (C-- > 0) {
        cin >> N;

        vector<int> B;
        int num;
        while (N-- > 0) {
            cin >> num;
            B.push_back(num);
        }
        A.push_back(B);
    }

    for (auto&& item : A)
        cout << lis(item) << endl;
}
