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
int cnt;
vector<problem> problems;

problem g_problem;
string g_pattern;
string g_input;

bool match(unsigned int pattern_idx, unsigned int input_idx)
{
    if (pattern_idx < g_pattern.size() && input_idx < g_input.size()) {
        if (g_pattern[pattern_idx] == g_input[input_idx] || g_pattern[pattern_idx] == '?') {
            return match(pattern_idx + 1, input_idx + 1);
        }
    }

    if (pattern_idx == g_pattern.size() && input_idx == g_input.size()) {
        return true;
    }

    return false;
}

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
    get_input();

    for (auto& problem : problems) {
        g_pattern = problem.pattern;

        vector<string> result;
        for (auto& item : problem.words) {
            g_input = item;
            if (match(0, 0))
                result.push_back(item);
        }
        sort(result.begin(), result.end());
        for (auto& res : result)
            cout << res << endl;

    }

    return 0;
}
