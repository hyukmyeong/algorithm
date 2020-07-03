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
string g_input;

bool match(unsigned int pattern_idx, unsigned int input_idx)
{
    while (true) {
        if (pattern_idx == g_pattern.size() || input_idx == g_input.size())
            break;

        if (g_pattern[pattern_idx] == g_input[input_idx] || g_pattern[pattern_idx] == '?') {
            ++pattern_idx;
            ++input_idx;
        }
        else
            break;
    }

    if (pattern_idx == g_pattern.size() && input_idx == g_input.size())
        return true;

    // 여기까지 왔으면 pattern[pos] == * 이거나 그게 아니라면 실패를 의미함
    if (g_pattern[pattern_idx] == '*') {
        for (unsigned int i = 0; input_idx + i <= g_input.size(); i++) {
            if (match(pattern_idx + 1, input_idx + i))
                return true;
        }
    }

    return false;
}

// unsigned int cache[101
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

int main()
{
#if 1
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
    g_input = item;
    if (match(0, 0))
      cout << g_input << endl;
  }
  return 0;
}
