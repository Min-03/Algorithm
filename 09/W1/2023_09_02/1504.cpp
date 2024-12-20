#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pair<int, int>> graph[801];
int dists[801];

int dijkstra(int start, int end) {
    memset(dists, 0x3f, sizeof(dists));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dists[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] < w) continue;
        for (auto [next, nextW] : graph[curr]) {
            if (w + nextW < dists[next]) {
                dists[next] = w + nextW;
                pq.push({dists[next], next});
            }
        }
    }
    return dists[end];
}

int main() {
    FastIO
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int p, q;
    cin >> p >> q;

    long long ans = (long long) dijkstra(1, p) + dijkstra(p, q) + dijkstra(q, n);
    ans = min(ans, (long long) dijkstra(1, q) + dijkstra(q, p) + dijkstra(p, n));
    cout << (ans >= inf ? -1 : ans);
    return 0;
}