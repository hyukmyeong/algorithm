#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

const int MOD = 1000000007;

string e, sorted_e;
int n, m;
int cache[1<<14][20][2];

int price(int index, int taken, int mod, int less)
{
  if (index == n)
    return (less && mod == 0) ? 1 : 0;

  int& ret = cache[taken][mod][less];
  if (ret != -1)
    return ret;

  ret = 0;

  for (int next = 0; next < n; ++next) {

    if ((taken & (1 << next)) == 0) {

      if (!less && e[index] < sorted_e[next])
        continue;

      if (next > 0 && sorted_e[next-1] == sorted_e[next] && (taken & (1 << (next-1))) == 0)
          continue;

      int nextTaken = taken | (1 << next);
      int nextMod = (mod * 10 + sorted_e[next] - '0') % m;
      int nextLess = less || e[index] > sorted_e[next];

      ret += price(index+1, nextTaken, nextMod, nextLess);
      ret %= MOD;
    }
  }
  return ret;
}

int main()
{
  int C;
  cin >> C;

  vector<int> result;

  while (C--) {
    n = 0;
    memset(cache, -1, sizeof(cache));
    cin >> e >> m;

    n = e.size();
    sorted_e = e;
    sort(sorted_e.begin(), sorted_e.end());

    result.push_back(price(0, 0, 0, 0));
  }

  for (const auto& item : result)
    cout << item << endl;

  return 0;
}
