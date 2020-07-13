#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N = 0;
vector<vector<int>> board;
vector<vector<int>> cache;


int path(int x, int y)
{
    if (x >= N || y >= N)
        return 0;

    int& res = cache[y][x];
    if (res != -1)
        return res;

    res = board[y][x] + max(path(x, y+1), path(x+1, y+1));

    return res;
}

int main()
{
    int C, X;
    cin >> N;

    for (int i=0; i<N; ++i) {
        vector<int> temp(N, -1);
        cache.push_back(temp);
    }

    C = 1;
    while (C <= N) {
        vector<int> temp;
        for (int i=0; i < C; ++i) {
            cin >> X;
            temp.push_back(X);
        }
        board.push_back(temp);
        ++C;
    }

    cout << path(0, 0) << endl;
}
