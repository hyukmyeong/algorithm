#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 2000

int C, N, M;
vector<pair<int,int> > adj[MAX_N];

// by bfs
bool hasPath(int lo, int hi)
{
    queue<int> q;
    vector<int> visit(MAX_N, 0);
    q.push(0);
    visit[0]=1;

    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        if(here == N-1)
            break;

        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int weight = adj[here][i].second;

            if((weight < lo) || (weight > hi) || (visit[there]))
                continue;

            visit[there]=1;
            q.push(there);
        }
    }

    // this is true if it can arrive vertex[N-1] from vertex[0]
    if(visit[N-1])
        return true;

    return false;
}


vector<int> weights;

int minUpperBound(int low)
{
    int lo = low - 1;
    int hi = weights.size();

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(hasPath(weights[i], mid))
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

int main()
{
    cin >> C;
    vector<int> result;

    while(C--)
    {
        cin >> N >> M;

        for(int i=0; i<N; ++i)
            adj[i].clear();

        for(int i=0,u,v,w; i<M; ++i)
        {
            cin >> u >> v >> w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            weights.push_back(w);
        }
        sort(weights.begin(), weights.end());

        int ret = 987654321;

        for(int i=0; i < weights.size(); ++i)
            ret = min(ret, minUpperBound(i) - weights[i]);

        result.push_back(ret);
    }

    for(const auto& e : result)
        cout << e << endl;
}
