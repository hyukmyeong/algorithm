#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int fib_bottom_up(int N)
{
  int a = 1, b = 1;
  int ret = 1;

  if (N == 1 || N == 2)
    return 1;

  for (int i = 3; i <= N; ++i) {
    ret = a + b;
    a = b;
    b = ret;
  }
  return ret;
}

int fib_top_down(int N)
{
  if (N == 1 || N == 2)
    return 1;

  return fib_top_down(N-1) + fib_top_down(N-2);
}

int main()
{
  cout << fib_bottom_up(7) << endl;
  cout << fib_top_down(7) << endl;
}
