#include <iostream>
#include <cstring>

using namespace std;

#define N 7

#if 1
int board[N][N] = {
  { 2, 5, 1, 6, 1, 4, 1 },
  { 6, 1, 1, 2, 2, 9, 3 },
  { 7, 2, 3, 2, 1, 3, 1 },
  { 1, 1, 3, 1, 7, 1, 2 },
  { 4, 1, 2, 3, 4, 1, 2 },
  { 3, 3, 1, 2, 3, 4, 1 },
  { 1, 5, 2, 9, 4, 7, 0 },
};
#else
int board[N][N] = {
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 2 },
  { 1, 1, 1, 1, 1, 2, 0 },
};
#endif

int cache[N][N];

int jump(int x, int y)
{
  if (x >= N || y >= N)
    return 0;

  if (x == N-1 && y == N-1)
    return 1;

  if (cache[y][x] == -1) {
    int down = jump(x + board[y][x], y);
    int right = jump(x, y + board[y][x]);

    cache[y][x] = down || right;
  }

  return cache[y][x];
}

int main()
{
  memset(cache, -1, sizeof(cache));
  cout << "result: " << (jump(0, 0) ? "success" : "failure") << endl;

  return 0;
}
