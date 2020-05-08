#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
const int MAX_N = 2000;

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
int minUpperBound(vector<pair<int,pair<int,int>>>& edges, vector<int>& weights, int low)
{
    OptimizedDisjointSet sets(N);

    for(int i = 0; i < edges.size(); ++i)
    {
        if(edges[i].first < weights[low])
            continue;

        int u = edges[i].second.first;
        int v = edges[i].second.second;
        sets.merge(u, v);

        if(sets.find(0) == sets.find(N-1))
            return edges[i].first;
    }
    return INF;
}

int main()
{
    cin >> C;
    vector<int> result;

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

        vector<pair<int,pair<int,int>>> edges;
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

        int ret = INF;

        for(int i = 0; i < weights.size(); ++i)
            ret = min(ret, minUpperBound(edges, weights, i) - weights[i]);

        result.push_back(ret);
    }

    for(const auto& e : result)
        cout << e << endl;
}
