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
  if(last == 0 && used == 3)
    cout << "###1" << endl;

  if (used == (1<<K) - 1)
    return 0;

  if(last == 0 && used == 3)
    cout << "###2" << endl;

  int &res = cache[last][used];
  if(res != -1)
    return res;

  if(last == 0 && used == 3)
    cout << "###3" << endl;

  res = 0;
  for(int next=0; next<K; next++) {
    if ((used & (1 << next)) == 0) {
      int cand = overlap[last][next] + restore(next, used + (1 << next));
      res= max(res, cand);
    }
  }
  if(last == 0 && used == 3)
    cout << "###4: " << res << endl;
  return res;
}

//처음 호출 시 last는 recover()가 최댓값을 반환한 시작 단어
//used는 1<<last로 둔다
//
//abrac
//cadabra
//dabr

//depth: 0
//next: 0, used:1, ifUsed: 1, overlap[2][0]=0
//next: 1, used:2, ifUsed: 4, overlap[2][1]=0
//selected overlap[2][1]=0
//cadabra

//depth: 1
//next: 0, used:3, ifUsed: 4, overlap[1][0]=4
//selected overlap[1][0]=4
//c

//depth: 2
//cadabrac

string reconstruct(int index, int last, int used)
{
  cout << "depth: " << index << endl;
  if (used == (1 << K) - 1)
    return "";

  for (int next = 0; next < K; next++) {
    if (used & (1 << next))
      continue;

    int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
    cout << "next: " << next << ", used:" << used+(1<<next) << ", ifUsed: " << ifUsed << ", overlap[" << last << "][" << next << "]=" << overlap[last][next] << endl;

    if (restore(last, used) == ifUsed) {
      cout << "selected overlap[" << last << "][" << next << "]=" << overlap[last][next] << endl;
      cout << word[next].substr(overlap[last][next]) << endl; 
      return (word[next].substr(overlap[last][next]) + reconstruct(index+1, next, used + (1 << next)));
    }

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

    cout << reconstruct(0, K, 0) << endl;
  }
  return 0;
}
