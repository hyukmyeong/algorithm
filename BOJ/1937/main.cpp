#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int cache[500][500];

vector<vector<int>> board;

int solve(int x, int y)
{
    if (x>=N || y>=N)
        return 0;

    if (x<0 || y<0)
        return 0;

    int& ret = cache[y][x];
    if (ret != -1)
        return ret;

    int res = 0;

    if (y+1 < N && board[y+1][x] > board[y][x])
        res = max(res, solve(x, y+1) + 1);

    if (y-1 >= 0 && board[y-1][x] > board[y][x])
        res = max(res, solve(x, y-1) + 1);

    if (x+1 < N && board[y][x+1] > board[y][x])
        res = max(res, solve(x+1, y) + 1);

    if (x-1 >= 0 && board[y][x-1] > board[y][x])
        res = max(res, solve(x-1, y) + 1);

    ret = res;
    return ret;
}


int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cout << "N= " << N << endl;;

    for (int i=0; i<N; ++i) {
        vector<int> board_inside;
        for (int j=0; j<N; ++j) {
            int aa;
            cin >> aa;
            board_inside.push_back(aa);
        }
        board.push_back(board_inside);
    }

    int res = 0;

    for (int x=0; x<N; ++x) {
        for (int y=0; y<N; ++y) {
            res = max(res, solve(x, y));
        }
    }

    cout << res + 1 << endl;

    return 0;
}
