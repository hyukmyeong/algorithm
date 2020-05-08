#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define MAX_N 2001

int C, N, M;
vector<pair<int,int> > adj[MAX_N];

bool bfs(int hi, int lo)
{
    queue<int> q;
    vector<int> visit(MAX_N,0);
    q.push(0);
    visit[0]=1;

    while(!q.empty())
    {
        int here=q.front();
        q.pop();

        if(here==N-1)
            break;

        for(int i=0;i<adj[here].size();++i)
        {
            int there=adj[here][i].first;
            int velocity=adj[here][i].second;

            if(velocity<lo || velocity>hi || visit[there])
                continue;

            visit[there]=1;
            q.push(there);
        }
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

        for(int i=0;i<N;++i)
            adj[i].clear();

        vector<int> weight;

        for(int i=0,u,v,w; i<M; ++i)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            weight.push_back(w);
        }

        sort(weight.begin(),weight.end());

        int ret=987654321;

        for(int i=0; i<weight.size(); ++i)
        {
            int lo=weight[i],hi=1000,mid;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(bfs(mid,weight[i])) ret=min(ret,mid-weight[i]),hi=mid-1;
                else lo=mid+1;
            }
        }
        cout << ret << endl;
    }
}
