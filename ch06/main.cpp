int n, double dist[MAX][MAX];

// path : 지금까지 만든 경로
// visited : 각 도시의 방문 여부
// currentLength: 지금까지 만든 경로의 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
  // 기저사례: 모든 도시를 다 방문했을 떄는 시작 도시로 돌아가고 종료한다
  if(path.size == n)
    return currentLength + dist[path[0]][path.back()];

  double ret = INF;	// 매우 큰 값으로 초기화 (확인안된 경로는 거리가 무한대라는 의미)
  // 다음 방문할 도시를 전부 시도해 본다.
  for(int next = 0; next < n; ++next) {
    if(visited[next])
      continue;

    int here = path.back();
    path.push_back(next);
    visited[next] = true;

    // 나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
    double cand = shortestPath(path, visited, currentLength + dist[here][next]);
    ret = min(ret, cand);
    visited[next] = flase;
    path.pop_back();
  }
  return ret;
}

int n, dist[MAX][MAX];
double cache[MAX][1<<MAX];

double shortestPath2(int here, int visited)
{
  if (visited == (1<<n)-1)
    return dist[here][0];

  double& ret = cache[here][visited];
  if (ret >= 0)
    return ret;

  ret = INF;

  for (int next=0; next<n; ++next) {
    if (visited & (1<<next))
      continue;

    double cand = dist[here][next] + shortestPath2(next, visited + 1(<<next));
    ret = min(ret, cand);
  }
  return ret;
}

int main()
{
}
