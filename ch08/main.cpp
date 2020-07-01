// Example program
#include <iostream>
#include <string>

using namespace std;

int fibo(int N)
{
  if (N == 1 || N == 2)
    return 1;

  int before_1 = 1;
  int before_2 = 1;
  int res;

  for (int i = 3; i <= N; ++i) {
    res = before_1 + before_2;

    before_2 = before_1;
    before_1 = res;
  }

    return res;
}

int main()
{
  cout << fibo(6) << endl;
}
