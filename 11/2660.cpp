#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> graph[51];
bool isFriend[51][51];
int dists[51];

void bfs(int s) {
  memset(dists, -1, sizeof(dists));
  dists[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    for (int ngb : graph[curr]) {
      if (dists[ngb] != -1) continue;
      dists[ngb] = dists[curr] + 1;
      q.push(ngb);
    }
  }
}

int main() {
  FASTIO
  int n, lo = 1e9;
  cin >> n;
  while (true) {
    int u, v;
    cin >> u >> v;
    if (u == -1) break;
    if (isFriend[u][v]) continue;
    graph[u].push_back(v);
    graph[v].push_back(u);
    isFriend[u][v] = true;
    isFriend[v][u] = true;
  }

  vector<int> candidates;
  for (int i = 1; i <= n; i++) {
    bfs(i);
    int hi = 0;
    for (int j = 1; j <= n; j++) {
      hi = max(hi, dists[j]);
    }
    if (lo < hi) continue;
    if (hi < lo) candidates.clear();
    lo = hi;
    candidates.push_back(i);
  }
  cout << lo << ' ' << candidates.size() << '\n';
  for (int n : candidates) cout << n << ' ';
}