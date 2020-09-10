#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 4;
int dist[N][N] = {
  {  0,  3, 10,  4},
  {  3,  0,  5,  7},
  { 10,  5,  0,  7},
  {  4,  1,  7,  0},
};

#if 1
int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength)
{
  if(path.size() == N)
    return currentLength + dist[path[0]][path.back()];

  int ret = 987654321;

  for(int next = 0; next < N; ++next) {
    if(visited[next])
      continue;

    int here = path.back();
    path.push_back(next);

    visited[next] = true;

    int cand = shortestPath(path, visited, currentLength + dist[here][next]);
    ret = min(ret, cand);

    visited[next] = false;

    path.pop_back();
  }
  return ret;
}

int main()
{
  vector<int> path {0};
  vector<bool> visited {true,false,false,false};

  cout << shortestPath(path, visited, 0) << endl;
  return 0;
}
#else
int cache[N][1<<N];
int shortestPath2(int here, int visited)
{
  if (visited == (1<<N)-1)
    return dist[here][0];

  int& ret = cache[here][visited];
  if (ret >= 0)
    return ret;

  ret = 987654321;

  for (int next=0; next<N; ++next) {
    if (visited & (1<<next))
      continue;

    int cand = dist[here][next] + shortestPath2(next, visited + (1<<next));
    ret = min(ret, cand);
  }
  return ret;
}

int main()
{
  memset(cache, -1, sizeof(cache));

  cout << shortestPath2(0, 1) << endl;
  return 0;
}
#endif
