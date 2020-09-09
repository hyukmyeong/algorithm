#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

string e, sorted_e;
int n, m;

int res = 0;

void generate(string price, bool taken[15])
{
  if (price.size() == n) {
    if (price < e)
      res++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!taken[i] && (i == 0 || sorted_e[i-1] != sorted_e[i] || taken[i - 1])) {
      taken[i] = true;
      generate(price + sorted_e[i], taken);
      taken[i] = false;
    }
  }
}

int main(void)
{
  int C;
  cin >> C;

  while (C--) {
    cin >> e >> m;

    n = e.size();
    sorted_e = e;
    sort(sorted_e.begin(), sorted_e.end());

    res = 0;
    string price {};
    bool taken[15] {0};
    generate(price, taken);

    cout << res << endl;
  }


  return 0;
}
