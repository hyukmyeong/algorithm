#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

/* dynamic programming is not applied */
int fib(int N)
{
  if (N == 1 || N == 2)
    return 1;

  return fib(N-1) + fib(N-2);
}

/* bottom-up approach */
int fib_tabulation(int N)
{
  int cache[N + 1];
  cache[0] = 0;
  cache[1] = 1;

  for (int i = 2; i <= N; i++)
    cache[i] = cache[i-1] + cache[i-2];

  return cache[N];
}

/* top-down approch */
int cache[100];
int fib_memoization(int N)
{
  if (N == 1 || N == 2)
    return 1;

  if (cache[N] != -1)
    return cache[N];

  cache[N] = fib_memoization(N-1) + fib_memoization(N-2);
  return cache[N];
}

int main()
{
  memset(cache, -1, sizeof(cache));

  cout << fib(7) << endl;
  cout << fib_tabulation(7) << endl;
  cout << fib_memoization(7) << endl;
}
