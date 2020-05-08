#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

int C, N, M;
const int MAX_V = 500;
//vector<pair<int,int>> point;

typedef struct {
    int x;
    int y;
} Point;
vector<Point> points;

double kruskal(OptimizedDisjointSet& set)
{
  double ret = 0.0;

  vector<pair<double,pair<int,int > > > edges;

  for(int u = 0; u < N; ++u)
  {
    for(int v = u+1; v < N; ++v)
    {
      // weight = distance = sqrt (subX^2 + subY^2)
      int distance_x = abs(points[u].x - points[v].x);
      int distance_y = abs(points[u].y - points[v].y);
      double distance = sqrt(distance_x * distance_x + distance_y * distance_y);

      edges.push_back(make_pair(distance, make_pair(u,v)));
    }
  }

  sort(edges.begin(), edges.end());

  for(int i = 0; i < edges.size(); ++i)
  {
    double cost = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (set.find(u) == set.find(v))
      continue;

    set.merge(u, v);
    ret += cost;
  }
  return ret;
}

int main()
{
  cin >> C;
  for(int i=0; i<C; i++)
  {
    cin >> N >> M;

    points = vector<Point>(N);
    OptimizedDisjointSet set(N);

    for (int j=0; j<N; j++)
      cin >> points[j].x;

    for (int j=0; j<N; j++)
      cin >> points[j].y;

    for (int j=0; j<M; j++)
    {
      int u, v;
      cin >> u >> v;

      set.merge(u, v);
    }
    cout << fixed << kruskal(set) << endl;
  }
  return 0;
}
