#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
const int MAX_N = 2000;

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


int minUpperBound(vector<int>& weights, int low)
{
    int lo = low - 1;
    int hi = weights.size();

    while(lo + 1 <  hi)
    {
        int mid = (lo + hi) / 2;

        if(hasPath(weights[low], weights[mid]))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    if(hi == weights.size())
        return INF;

    return weights[hi];
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

        int ret = INF;

        for(int i=0; i < weights.size(); ++i)
            ret = min(ret, minUpperBound(weights, i) - weights[i]);

        result.push_back(ret);
    }

    for(const auto& e : result)
        cout << e << endl;
}
