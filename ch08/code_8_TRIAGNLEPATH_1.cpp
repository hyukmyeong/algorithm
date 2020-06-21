#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

#if 0
#if 0
const int N = 5;
int board[N][N] = {
  { 6, 0, 0, 0, 0 },
  { 1, 2, 0, 0, 0 },
  { 3, 7, 4, 0, 0 },
  { 9, 4, 1, 7, 0 },
  { 2, 7, 5, 9, 4 },
};
#else
const int N = 5;
int board[N][N] = {
  {   1,   0,   0,   0,   0 },
  {   2,   4,   0,   0,   0 },
  {   8,  16,   8,   0,   0 },
  {  32,  64,  32,  64,   0 },
  { 128, 256, 128, 256, 128 },
};
#endif
#endif

vector<vector<vector<int>>> g_data;
vector<vector<int>> g_board;

void get_data()
{
  int cases = 0;
  cin >> cases;

  for (int i = 0; i < cases; ++i) {
    int lines = 0;
    cin >> lines;
    cin.ignore();

    vector<vector<int>> v1;
    for (int j = 0; j < lines; ++j) {
      string line, num;
      getline(cin, line);
      istringstream ss(line);

      vector<int> v2(lines, 0);
      auto&& iter = v2.begin();
      while (getline(ss, num, ' ')) {
        *iter = atoi(num.c_str());
        ++iter;
      }
      v1.push_back(v2);
    }
    g_data.push_back(v1);
  }
}

int triangle(unsigned int x, unsigned int y)
{
  cout << "size: " << g_board.size() << endl;
  if (x == g_board.size() - 1 || y == g_board.size() - 1)
    return g_board[y][x];

  int res = max(triangle(x, y + 1), triangle(x + 1, y + 1)) + g_board[y][x];

  return res;
}

int main()
{
  get_data();

  for (auto& board : g_data) {
    g_board.clear();
    g_board = board;
    cout << triangle(0, 0) << endl;
  }
}
