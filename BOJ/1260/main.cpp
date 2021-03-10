#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Graph {
public:
  Graph(int V) : vertice(V)
  {
    adj.resize(V);
  }

    void add_edge(int from, int to)
    {
      adj[from].push_back(to);
    }

    void print_graph()
    { for(int i=0; i<adj.size(); ++i) {
        for(int j=0; j<adj[i].size(); ++j) {
          cout << "from:" << i << ", to:" << adj[i][j] << endl;
        }
      }
    }

    void bfs(int start) {
      vector<bool> visited(adj.size(), false);
      queue<int> Q;
      int cur = start;

      Q.push(start);

      while(!Q.empty()) {
        cur = Q.front();
        visited[cur] = true;
        Q.pop();

        cout << cur << " visited" << endl;

        for(int i=0; i<adj[cur].size(); ++i) {
          cout << "i= " << i << "and adj[cur][i]=" << adj[cur][i] << endl;
          if(visited[adj[cur][i]] == false)
            Q.push(adj[cur][i]);
        }
      }

    }

private:
  int vertice;
  vector<vector<int>> adj;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V, E, start;
  cin >> V >> E >> start;

  Graph G(V+1);

  int from, to;
  for(int i=0; i<E; ++i) {
    cin >> from >> to;
    G.add_edge(from, to);
  }

  G.print_graph();
  G.bfs(start);

  return 0;
}
