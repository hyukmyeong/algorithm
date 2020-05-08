#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
vector<pair<int,int>> adj[100];
int N;

void make_graph()
{
  // vertex a
  adj[0].push_back(make_pair(1,5)); // a-b
  adj[0].push_back(make_pair(2,1)); // a-c

  // vertex b
  adj[1].push_back(make_pair(0,5)); // b-a
  adj[1].push_back(make_pair(3,1)); // b-d
  adj[1].push_back(make_pair(5,3)); // b-f
  adj[1].push_back(make_pair(6,3)); // b-g

  // vertex c
  adj[2].push_back(make_pair(0,1)); // c-a
  adj[2].push_back(make_pair(3,4)); // c-d

  // vertex d
  adj[3].push_back(make_pair(1,1)); // d-b
  adj[3].push_back(make_pair(2,4)); // d-c
  adj[3].push_back(make_pair(4,5)); // d-e
  adj[3].push_back(make_pair(5,3)); // d-f

  // vertex e
  adj[4].push_back(make_pair(3,5)); // e-d

  // vertex f
  adj[5].push_back(make_pair(1,3)); // f-b
  adj[5].push_back(make_pair(3,3)); // f-d
  adj[5].push_back(make_pair(6,2)); // f-g

  // vertex g
  adj[6].push_back(make_pair(1,3)); // g-b
  adj[6].push_back(make_pair(5,2)); // g-f
}

int prim(vector<pair<int,int>>& selected)
{
  int ret = 0;
  selected.clear();

  vector<bool> added(N, false);
  vector<int> minWeight(N, INF);
  vector<int> parent(N, -1);

  minWeight[0] = parent[0] = 0;

  for(int iter = 0; iter < N; ++iter)
  {
    // find next vertex
    int u = -1;
    for(int v = 0; v < N; ++v)
      if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
          u = v;

    // add (parent[u],u) into tree
    if(parent[u] != u)
      selected.push_back(make_pair(parent[u], u));

    ret += minWeight[u];
    added[u] = true;

    // check edges(u,v) near u
    for(int i = 0; i < adj[u].size(); ++i)
    {
      int v = adj[u][i].first;
      int weight = adj[u][i].second;

      if(!added[v] && (minWeight[v] > weight))
      {
          parent[v] = u;
          minWeight[v] = weight;
      }
    }
  }
  return ret;
}

int main()
{
  N = 7;
  make_graph();

  vector<pair<int,int>> selected;
  cout << "result: " << prim(selected) << endl;

  int i = 1;
  for(auto&& item : selected)
  {
    cout << i++
         << "th edge"
         << " src: " << static_cast<char>('a'+item.first)
         << " dst: " << static_cast<char>('a'+item.second) << endl;
  }

  return 0;
}
