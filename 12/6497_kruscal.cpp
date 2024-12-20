#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int ranks[200'001], parents[200'001];
vector<tuple<int, int, int>> edges;

int find_set(int n) {
  if (n == parents[n]) return n;
  return parents[n] = find_set(parents[n]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b) return;
  if (ranks[a] > ranks[b]) swap(a, b);
  parents[a] = b;
  ranks[b] += ranks[a] == ranks[b];
}

int main() {
  FASTIO
  while (true) {
    int n, m, cost = 0, tot = 0;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    edges.clear();
    for (int i = 0; i <= n; i++) {
      ranks[i] = 0;
      parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      edges.push_back({w, a, b});
      tot += w;
    }
    sort(edges.begin(), edges.end());
    for (auto [w, a, b] : edges) {
      if (find_set(a) != find_set(b)) {
        union_set(a, b);
        cost += w;
      }
    }
    cout << tot - cost << '\n';
  }
  return 0;
}