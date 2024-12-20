#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;


vector<pii> graph[1001];
int dists[1001];

int dijkstra(int start, int end) {
    memset(dists, inf, sizeof(dists));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dists[start] = 0;
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
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dijkstra(i, x) + dijkstra(x, i));
    }
    cout << ans;
    return 0;
}