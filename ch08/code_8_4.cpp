#include <iostream>
#include <cstring>

using namespace std;

#define N 7
int board[N][N] = {
  { 2, 5, 1, 6, 1, 4, 1 },
  { 6, 1, 1, 2, 2, 9, 3 },
  { 7, 2, 3, 2, 1, 3, 1 },
  { 1, 1, 3, 1, 7, 1, 2 },
  { 4, 1, 2, 3, 4, 1, 2 },
  { 3, 3, 1, 2, 3, 4, 1 },
  { 1, 5, 2, 9, 4, 7, 0 },
};

bool jmp(int x, int y)
{
  if (x >= N || y >= N)
    return false;

  if (x == N - 1 && y == N -1)
    return true;

  int jmp_size = board[y][x];

  return jmp(x, y + jmp_size) || jmp(x + jmp_size, y);
}

int main()
{
  cout << "result: " << (jmp(0, 0) ? "success" : "failure") << endl;

  return 0;
}
