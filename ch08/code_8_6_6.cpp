#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <algorithm>

using namespace std;

class problem {
public:
  string pattern;
  vector<string> words;
};
vector<problem> g_problems;
string g_pattern;
string g_word;

void get_input()
{
  int cnt;
  cin >> cnt;

  for (int i = 0; i < cnt; i++) {
    problem p;
    int cnt_words;
    cin >> p.pattern;
    cin >> cnt_words;

    for (int j = 0; j < cnt_words; j++) {
      string input;
      cin >> input;
      p.words.push_back(input);
    }
    sort(p.words.begin(), p.words.end());
    g_problems.push_back(p);
  }
}

int cache[101][101];

bool match(unsigned int pattern_idx, unsigned int word_idx)
{
  int& res = cache[pattern_idx][word_idx];

  if (res != -1)
    return res;

  while ((pattern_idx < g_pattern.size() && word_idx < g_word.size()) &&
        (g_pattern[pattern_idx] == g_word[word_idx] || g_pattern[pattern_idx] == '?'))
    match(++pattern_idx, ++word_idx);

  if (pattern_idx == g_pattern.size() && word_idx == g_word.size()) {
    res = true;
    return res;
  }

  if (g_pattern[pattern_idx] == '*') {
    if (match(pattern_idx + 1, word_idx) || match(pattern_idx, word_idx + 1)) {
      res = true;
      return res;
    }
  }

  res = false;
  return res;
}

int main()
{
  get_input();

  for (auto problem : g_problems) {
    g_pattern = problem.pattern;

    for (auto& word : problem.words) {
      memset(cache, -1, sizeof(cache));
      g_word = word;

      if (match(0, 0))
        cout << g_word << endl;
    }
  }
  return 0;
}
