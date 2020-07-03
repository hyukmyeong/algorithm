#include <iostream>

using namespace std;

int bino(int n, int r)
{
  if (n == r || r == 0)
    return 1;

  return bino(n - 1, r - 1) + bino(n - 1, r);
}

int main()
{
  memset(cache, -1, sizeof(cache));

  cout << "Code 8.1" << endl;
  cout << "bino: " << bino(5, 3) << endl;

}
