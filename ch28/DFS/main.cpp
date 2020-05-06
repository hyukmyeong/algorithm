#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];

// indegree[i] = i로 시작하는 단어의 수
// outdegree[i] = i로 끝나는 단어의 수
vector<int> indegree, outdegree;

void makeGraph(const vector<string>& words)
{
    for(int i = 0; i< 26; ++i)
        for(int j = 0; j < 26; ++j)
            graph[i][j].clear();

    adj = vector<vector<int>>(26, vector<int>(26,0));

    indegree = vector<int>(26,0);
    outdegree = vector<int>(26,0);

    for(int i = 0; i < words.size(); ++i) {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size()-1] - 'a';

        graph[a][b].push_back(words[i]);

        adj[a][b]++;
        outdegree[a]++; 
        indegree[b]++;
    }
}

void getEulerCircuit(int here, vector<int>& circuit) {
  for(int there = 0; there < adj.size(); ++there)
    while(adj[here][there] > 0) {
      adj[here][there]--;
      getEulerCircuit(there, circuit);
    }

  circuit.push_back(here);
}

#if 0
vector<vector<int>> adj;

void getEulerCircuit(int here, vector<int>& circuit) {
  for(int there = 0; there < adj.size(); ++there)
    while(adj[here][there] > 0) {
      adj[here][there]--;
      adj[there][here]--;
      getEulerCircuit(there, circuit);
    }

  circuit.push_back(here);
}
#endif

vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;

    for(int i = 0; i < 26; ++i)
        if(outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            cout << "Euler Trail is found" << endl;
            return circuit;
        }

    for(int i = 0; i< 26; ++i)
        if(outdegree[i]) {
            getEulerCircuit(i, circuit);
            cout << "Euler Circuit is found" << endl;
            return circuit;
        }

    return circuit;
}

bool checkEuler() {
    int plus1 = 0;
    int minus1 = 0;

    for(int i = 0; i < 26; ++i) {
        int delta = outdegree[i] - indegree[i];

        if(delta < -1 || 1 < delta)
            return false;

        if(delta == 1)
            plus1++;

        if(delta == -1)
            minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words) {
    makeGraph(words);

    if(!checkEuler())
        return "IMPOSSIBLE";

    vector<int> circuit = getEulerTrailOrCircuit();

    if(circuit.size() != words.size() + 1)
        return "IMPOSSIBLE";

    reverse(circuit.begin(), circuit.end());

    string ret;

    for(int i = 1; i < circuit.size(); i++) {
        int a = circuit[i-1];
        int b = circuit[i];

        if(ret.size())
            ret += " ";

        ret += graph[a][b].back();

        graph[a][b].pop_back();
    }
    return ret;
}


int main() {
  vector<string> vec1{"dog", "god", "dragon", "need"};
  vector<string> vec2{"aa", "ab", "bb"};
  vector<string> vec3{"ab", "cd"};

  for (string item : vec1) {
    cout << item << endl;
  }
  cout << solve(vec1).c_str() << endl;

  for (string item : vec2) {
    cout << item << endl;
  }
  cout << solve(vec2).c_str() << endl;


  for (string item : vec3) {
    cout << item << endl;
  }
  cout << solve(vec3).c_str() << endl;
}
