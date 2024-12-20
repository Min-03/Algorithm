#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int, int> pii;

vector<pair<int, int>> graph[1001];
int dists[1001];

int dijkstra(int start, int dest) {
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
    return dists[dest];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    int start, dest;
    cin >> start >> dest;
    cout << dijkstra(start, dest);
    return 0;
}