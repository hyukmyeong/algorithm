#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 2000

int C, N, M;
const int INF = 987654321;
vector<pair<int,int> > adj[MAX_N];

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

// by prim MST 
#if 0
bool can_arrive_dest(int lo, int hi)
{
  int ret = 0;
  int selected = 0;

  vector<pair<int,pair<int,int> > > edges;
  for(int u = 0; u < N; ++u)
  {
    for(int i = 0; i < adj[u].size(); ++i)
    {
      int v = adj[u][i].first;
      int cost = adj[u][i].second;

      edges.push_back(make_pair(cost, make_pair(u, v)));
    }
  }

  sort(edges.begin(), edges.end());

  OptimizedDisjointSet sets(N);

  for(int i = 0; i < edges.size(); ++i)
  {
    int weight = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if((weight < lo) || (weight > hi))
      continue;

    if (sets.find(u) == sets.find(v))
      continue;

    sets.merge(u, v);
    selected++;
    ret += weight;
  }

  if(selected == N-1)
    return true;

  return false;
}
#else
bool can_arrive_dest(int lo, int hi)
{
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

    if(minWeight[u] < lo || minWeight[u] > hi)
      continue;

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

  if(added[N-1])
      return true;

  return false;
}
#endif

int main()
{
    cin >> C;
    while(C--)
    {
        cin >> N >> M;

        for(int i=0; i<N; ++i)
            adj[i].clear();

        vector<int> weights;

        for(int i=0,u,v,w; i<M; ++i)
        {
            cin >> u >> v >> w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            weights.push_back(w);
        }

        sort(weights.begin(), weights.end());

        int ret = 987654321;

        for(int i=0; i<weights.size(); ++i)
        {
            int lo = weights[i];
            int hi = 1000;
            int mid;

            while(lo <= hi)
            {
                mid = (lo + hi) / 2;

                if(can_arrive_dest(weights[i], mid))
                {
                    ret = min(ret, mid - weights[i]);
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
        }
        cout << ret << endl;
    }
}
