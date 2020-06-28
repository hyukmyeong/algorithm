#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

static int g_cnt = 0;

int lis(const vector<int>& A)
{
  g_cnt++;
  if (A.empty())
    return 0;

  int ret = 0;

  for (int i = 0; i < A.size(); ++i) {

    vector<int> B;
    for (int j = i + 1; j < A.size(); ++j) {
      if (A[i] < A[j])
        B.push_back(A[j]);
    }

    ret = max(ret, 1 + lis(B));
  }
  return ret;
}

int main()
{
#if 0
  int C, N;
  cin >> C;

  while (C-- > 0) {
    cin >> N;

    vector<int> A;
    int num;
    while (N-- > 0) {
      cin >> num;
      A.push_back(num);
    }
    cout << "result: " << lis(A) << endl;
  }
#else
  vector<int> A = { 1, 2, 3, 4, 5 };
  //vector<int> A = { 6, 5, 4, 3, 2, 1 };
  cout << "result: " << lis(A) << endl;

  cout << "final cnt: " << g_cnt << endl;
#endif
}
