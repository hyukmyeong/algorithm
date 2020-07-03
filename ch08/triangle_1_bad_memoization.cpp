#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int const size = 5;
int const max_value  = 9;
int cache[size][size][max_value * size];

int board[size][size] = {
  { 6, 0, 0, 0, 0 },
  { 1, 2, 0, 0, 0 },
  { 3, 7, 4, 0, 0 },
  { 9, 4, 1, 7, 0 },
  { 2, 7, 5, 9, 4 },
};

int triangle(int x, int y, int sum)
{
    if (y == size-1)
        return sum + board[y][x];

    int& ret = cache[y][x][sum];
    if (ret != -1)
        return ret;
    
    sum += board[y][x];
    ret = max(triangle(x, y+1, sum), triangle(x+1, y+1, sum));
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << triangle(0, 0, 0) << endl;
}

#if 0
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

int main()
{
  get_data();

  for (auto& board : g_data) {
    g_board.clear();
    g_board = board;
    cout << triangle(0, 0) << endl;
  }
}
#endif
