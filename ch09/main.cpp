#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;


#if 0
int solve(string text, string pattern)
{
  // memoization이 어려움
}

int cache[N][N];
int solve(int text_idx, int pattern_idx)
{
  int& ret = cache[text_idx][pattern_idx];
  if (ret != -1)
    return ret;
}
#endif

#if 0
map<vector<int>, int> cache;

int solve(vector<int>& key)
{
  int& ret = cache[key];
  if (ret != -1)
    return ret;

  ...
}

int mapping(cont vector<int>& key)
{
  ...
}

int solve(vector<int>& key>)
{
  int& ret = cache[mapping(key)];
  if (ret != -1)
    return ret;

  ...
}
#endif

#if 0
int factorials[12];

int getIndex(const vector<int>& X)
{
  int ret = 0;

  for (int i=0; i < X.size(); ++i) {

    int less = 0;

    for (int j=i+1; j < X.size(); ++j) {
      if (X[j] < X[i])
        ++less;
    }

    ret += factorials[X.size()-i-1] * less;
  }

  return ret;
}

int solve(vector<int>& key>)
{
  // int& ret = cache[getIndex(key)];
  // if (ret != -1)
  //   return ret;

  // ...
}
#endif

//https://www.acmicpc.net/problem/1722

int factorials[12] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};

int getIndex(const vector<int> &X)
{
  int ret = 0;
  for (int i=0; i<X.size(); ++i) {
    int less = 0;
    for (int j=i+1; j<X.size(); ++j)
      if (X[j] < X[i])
        less++;

    ret += factorials[X.size()-i-1] * less;
  }
  return ret;
}

int cache[100];
int solve(vector<int>& key)
{
  int& ret = cache[getIndex(key)];
  if (ret != -1)
    return ret;

  //...
}

int main(void)
{
  memset(cache, -1, sizeof(cache));

  vector<int> X1 = {1,2,3,4,5,6,7,8,9,10};
  vector<int> X2 = {2,1,3,4,5,6,7,8,9,10};
  cout << getIndex(X1) << endl;
  cout << getIndex(X2) << endl;

  cout << solve(X1) << endl;

}
