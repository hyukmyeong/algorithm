#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
const int MAX_N = 2000;

int C, N, M;
vector<pair<int,int> > adj[MAX_N];

// by BFS (or DFS)
bool hasPath(int lo, int hi)
{
    queue<int> q;
    vector<int> visit(MAX_N, 0);
    q.push(0);
    visit[0] = 1;

    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        if(here == N-1)
            break;

        for(int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int weight = adj[here][i].second;

            if((weight < lo) || (weight > hi) || (visit[there]))
                continue;

            visit[there]=1;
            q.push(there);
        }
    }

    if(visit[N-1])
        return true;

    return false;
}

int optimized(vector<int>& weights)
{
    int ret = INF;
    int foundPathUsing = 0;

    for(int lo = 0; lo < weights.size(); ++lo)
    {
        bool foundPath = false;

        for(int hi = foundPathUsing; hi < weights.size(); ++hi)
        {
            if(hasPath(weights[lo], weights[hi]))
            {
                ret = min(ret, weights[hi] - weights[lo]);

                foundPath = true;
                foundPathUsing = hi;
                break;
            }
        }

        if(!foundPath)
            break;
    }
    return ret;
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

        result.push_back(optimized(weights));
    }

    for(const auto& e : result)
        cout << e << endl;
}
