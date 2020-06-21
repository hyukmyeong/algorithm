#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

class problem {
public:
  string pattern;
  vector<string> words;
};
int cnt;
vector<problem> problems;

problem g_problem;
string g_pattern;
string g_word;

int cache[101][101];

void get_input()
{
  cin >> cnt;

  for (int i = 0; i < cnt; i++) {
    problem p;
    int cnt_inputs;
    cin >> p.pattern;
    cin >> cnt_inputs;

    for (int j = 0; j < cnt_inputs; j++) {
      string input;
      cin >> input;
      p.words.push_back(input);
    }
    problems.push_back(p);
  }
}

#if 1
bool match(unsigned int pattern_idx, unsigned int word_idx)
{
  int& res = cache[pattern_idx][word_idx];

  if (res != -1)
    return res;

  while (true) {
    if (pattern_idx == g_pattern.size() || word_idx == g_word.size())
      break;

    if (g_pattern[pattern_idx] == g_word[word_idx] || g_pattern[pattern_idx] == '?') {
      ++pattern_idx;
      ++word_idx;
    }
    else
      break;
  }

  if (pattern_idx == g_pattern.size() && word_idx == g_word.size()) {
    res = true;
    return true;
  }

  if (g_pattern[pattern_idx] != '*') {
    res = false;
    return false;
  }

  // 여기까지 왔으면 pattern[pos] == '*' 인 상황임
  for (unsigned int i = 0; word_idx + i <= g_word.size(); i++)
    if (match(pattern_idx + 1, word_idx + i)) {
      res = true;
      return true;
    }

  res = false;
  return false;
}
#endif

int main()
{
#if 0
#if 1
  g_problem.pattern = "***";
  g_problem.words.push_back("abcde");
#else
  g_problem.pattern = "*p*";
  g_problem.words.push_back("help");
  g_problem.words.push_back("papa");
  g_problem.words.push_back("hello");
#endif
#else
#if 0
  g_problem.pattern = "*bb*";
  g_problem.words.push_back("babbbc");
#else
  g_problem.pattern = "he?p";
  g_problem.words.push_back("help");
  g_problem.words.push_back("heap");
  g_problem.words.push_back("helpp");
#endif
#endif

  g_pattern = g_problem.pattern;

  for (auto& item : g_problem.words) {
    memset(cache, -1, sizeof(cache));
    g_word = item;
    if (match(0, 0))
      cout << g_word << endl;
  }
  return 0;
}
