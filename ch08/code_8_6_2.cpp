#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

class problem {
public:
  string pattern;
  vector<string> inputs;
};
int cnt;
vector<problem> problems;

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
      p.inputs.push_back(input);
    }
    problems.push_back(p);
  }
}

bool match(const string& pattern, const string& input)
{
  unsigned int pos = 0;

  while (true) {
    if (pos == pattern.size() || pos == input.size())
      break;

    if (pattern[pos] == input[pos] || pattern[pos] == '?')
      pos++;
    else
      break;
  }

  if (pos == pattern.size() && pos == input.size())
    return true;

  if (pattern[pos] != '*')
    return false;

  // 여기까지 왔으면 pattern[pos] == * 인 상황임
  for (unsigned int i = 0; pos + i <= input.size(); i++)
    if (match(pattern.substr(pos + 1), input.substr(pos + i)))
      return true;

  return false;
}

int main()
{
  problem p;

#if 1
  p.pattern = "*p*";
  p.inputs.push_back("help");
  // p.inputs.push_back("papa");
  // p.inputs.push_back("hello");
#else
#if 0
  p.pattern = "*bb*";
  p.inputs.push_back("babbbc");
#else
  p.pattern = "he?p";
  p.inputs.push_back("help");
  p.inputs.push_back("heap");
  p.inputs.push_back("helpp");
#endif
#endif

  cout << "pattern: " << p.pattern << endl;

  for (auto& item : p.inputs) {
    if (match(p.pattern, item))
      cout << item << endl;
  }

  return 0;
}
