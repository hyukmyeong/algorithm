#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
public:
  Graph(int N)
  {
    adj.resize(N+1);
    visited.resize(N+1, false);
  }

  void add_edge(int from, int to)
  {
    adj[from].push_back(to);
  }

  void sort_graph()
  {
    for(int i=0; i<adj.size(); ++i)
      sort(adj[i].begin(), adj[i].end(), less<int>());
  }

  void print_graph()
  {
    for(int i=1; i<adj.size(); ++i) {
      for(int j=0; j<adj[i].size(); ++j) {
          cout << "from:" << i << ", to:" << adj[i][j] << endl;
      }
    }
  }

  void dfs_impl(int start)
  {
    cout << start << " ";
    visited[start] = true;

    for(int i=0; i<adj[start].size(); ++i) {
      if(visited[adj[start][i]] == false)
        dfs_impl(adj[start][i]);
    }
  }

  void dfs(int start)
  {
    fill(visited.begin(), visited.end(), false);
    dfs_impl(start);
  }

  void bfs(int start)
  {
    fill(visited.begin(), visited.end(), false);
    std::queue<int> Q;
    Q.push(start);

    visited[0] = visited[start] = true;

    while(Q.empty() == false) {
      int cur = Q.front();
      Q.pop();

      cout << cur << " ";

      for(int i=0; i<adj[cur].size(); ++i) {
        if(visited[adj[cur][i]] == false) {
          visited[adj[cur][i]] = true;
          Q.push(adj[cur][i]);
        }
      }
    }
  }

private:
  vector<vector<int>> adj;
  vector<bool> visited;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V, E, start;
  cin >> V >> E >> start;

  Graph graph(V);

  int from, to;
  for(int i=0; i<E; ++i) {
    cin >> from >> to;
    graph.add_edge(from, to);
    graph.add_edge(to, from);
  }

  graph.sort_graph();
  graph.dfs(start);
  cout << endl;
  graph.bfs(start);
  cout << endl;

  return 0;
}
