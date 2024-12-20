#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[50'001];
int dists[50'001];

int dijkstra(int s, int e) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    memset(dists, inf, sizeof(dists));
    pq.push({0, s});
    dists[s] = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] != w) continue;
        for (auto [nw, nxt] : graph[curr]) {
            if (dists[curr] + nw < dists[nxt]) {
                dists[nxt] = dists[curr] + nw;
                pq.push({dists[nxt], nxt});
            }
        }
    }
    assert(dists[e] != inf);
    return dists[e];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    cout << dijkstra(1, n);
    return 0;
}