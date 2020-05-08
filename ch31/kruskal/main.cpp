#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class OptimizedDisjointSet {
public:
  OptimizedDisjointSet(int n) : parent(n), rank(n)
  {
    for(int i=0; i<n; ++i)
      parent[i] = i;
  }

  int find(int u)
  {
    if(u == parent[u])
      return u;

    return  parent[u] = find(parent[u]);
  }

  void merge(int u, int v)
  {
    u = find(u);
    v = find(v);

    if(u==v)
      return;

    if(rank[u] > rank[v])
      swap(u, v);

    parent[u] = v;

    if(rank[u] == rank[v])
      ++rank[v];
  }

private:
  vector<int> parent, rank;
};

vector<pair<int,int> > adj[100];
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

int kruskal(vector<pair<int,int> >& selected)
{
  int ret = 0;
  selected.clear();

  vector<pair<int,pair<int,int> > > edges;
  for(int u = 0; u < N; ++u)
  {
    for(int i = 0; i < adj[u].size(); ++i)
    {
      int v = adj[u][i].first;
      int weight = adj[u][i].second;

      edges.push_back(make_pair(weight, make_pair(u, v)));
    }
  }

  sort(edges.begin(), edges.end());

  OptimizedDisjointSet sets(N);

  for(int i = 0; i < edges.size(); ++i)
  {
    int weight = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (sets.find(u) == sets.find(v))
      continue;

    sets.merge(u, v);
    selected.push_back(make_pair(u, v));
    ret += weight;
  }
  return ret;
}

int main()
{
  N = 7;
  make_graph();

  vector<pair<int,int> > selected;
  cout << "result: " << kruskal(selected) << endl;

  int i = 1;
  for(auto& item : selected)
  {
    cout << i++
         << "th edge"
         << " src: " << static_cast<char>('a'+item.first)
         << " dst: " << static_cast<char>('a'+item.second) << endl;
  }

  return 0;
}
