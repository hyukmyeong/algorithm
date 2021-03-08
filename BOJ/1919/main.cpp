#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string var1, var2;
  vector<pair<int, int>> cnt_alphabet(26, std::make_pair(0,0));

  cin >> var1 >> var2;

  for(auto e : var1) {
    int pos = static_cast<int>(e) - static_cast<int>('a');
    cnt_alphabet[pos].first++;
  }

  for(auto e : var2) {
    int pos = static_cast<int>(e) - static_cast<int>('a');
    cnt_alphabet[pos].second++;
  }

  unsigned int res = 0;
  for(auto&& e : cnt_alphabet) {
    int tmp =  e.first - e.second;
    res += tmp > 0 ? tmp : tmp * -1;
  }

  cout << res << endl;

  return 0;
}
