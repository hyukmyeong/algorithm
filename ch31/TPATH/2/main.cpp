#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 2000

int C, N, M;
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

// by kruskal 
bool can_arrive_dest(int lo, int hi)
{
  int ret = 0;

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
    int cost = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (sets.find(u) == sets.find(v))
      continue;

    sets.merge(u, v);
    ret += cost;
  }

  if(visit[N-1])
    return true;

  return false;
}

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
