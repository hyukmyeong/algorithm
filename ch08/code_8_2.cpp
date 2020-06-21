#include <iostream>
#include <cstring>

using namespace std;

int cache[30][30];

int bino(int n, int r)
{
  if (n == r || r == 0)
    return 1;

  int& ret = cache[n][r];

  if (ret != -1)
    return ret;

  ret = bino(n - 1, r - 1) + bino(n - 1, r);

  return ret;
}

int main()
{
  memset(cache, -1, sizeof(cache));

  cout << "Code 8.1" << endl;
  cout << "bino: " << bino(5, 3) << endl;

}
