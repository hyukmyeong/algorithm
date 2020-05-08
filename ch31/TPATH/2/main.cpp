#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 2000

int C, N, M;
vector<pair<int,int> > adj[MAX_N];

// by bfs
bool can_arrive_dest(int lo, int hi)
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
