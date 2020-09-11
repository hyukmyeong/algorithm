#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 15;

// 문자개수
int K;
string word[MAX+1];
int overlap[MAX + 1][MAX + 1];
int cache[MAX][(1 << MAX) + 1];

int restore(int last, int used)
{
  if (used == (1<<K) - 1)
    return 0;

  int &res = cache[last][used];
  if(res != -1)
    return res;

  res = 0;
  for(int next=0; next<K; next++) {
    if ((used & (1 << next)) == 0) {
      int cand = overlap[last][next] + restore(next, used + (1 << next));
      res= max(res, cand);
    }
  }
  return res;
}

//처음 호출 시 last는 recover()가 최댓값을 반환한 시작 단어
//used는 1<<last로 둔다
string reconstruct(int last, int used)
{
  if (used == (1 << K) - 1)
    return "";

  for (int next = 0; next < K; next++) {
    if (used & (1 << next))
      continue;

    int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
    if (restore(last, used) == ifUsed)
      return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));

  }
  return "****ooops****";
}

int get_overlap(const string &s1, const string &s2)
{
  // s1의 접미사와 s2의 접두사
  int len = min(s1.size(), s2.size());

  while (len--) {
    if (s1.substr(s1.size() - len) == s2.substr(0, len))
      return len;
  }

  return 0;
}

int init_overlap()
{
  for (int i=0; i<K; ++i)
    for (int j=0; j<K; ++j)
      overlap[i][j] = get_overlap(word[i], word[j]);
}

void remove_substr()
{
  for (int i=0; i<K; ++i) {
    for (int j=0; j<K; ++j) { 
      if (i!=j && word[i].find(word[j]) != string::npos) {
        word[j] = word[K-1];
        K--;
      }
    }
  }
  word[K] = "";
}

int main(void)
{
  int C;
  cin >> C;

  while(C--) {
    memset(cache, -1, sizeof(cache));
    cin >> K;

    for (int j=0; j<K; ++j)
      cin >> word[j];

    // 전처리작업
    remove_substr();
    init_overlap();

    cout << reconstruct(K, 0) << endl;
  }
  return 0;
}
