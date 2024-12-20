#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[501];
vector<int> parent[501];
int dist[501];
bool banned[501][501];
bool visited[501];

int dijkstra(int s, int e) {
    memset(dist, inf, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dist[curr] < w) continue;
        for (auto [nw, next] : graph[curr]) {
            if (banned[curr][next] || dist[next] < nw + dist[curr]) continue;
            if (dist[next] > nw + dist[curr]) {
                parent[next].clear();
                pq.push({nw, next});
            }
            dist[next] = dist[curr] + nw;
            parent[next].push_back(curr);
        }
    }
    return (dist[e] == inf ? -1 : dist[e]);
}

void setBanned(int s, int curr) {
    visited[curr] = true;
    if (curr == s) return;
    for (int p : parent[curr]) {
        banned[p][curr] = true;
        if (!visited[p]) setBanned(s, p);
    }
}

int main() {
    FastIO
    while (true) {
        int n, m, s, e;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> e;
        memset(banned, false, sizeof(banned));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            parent[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int st, en, w;
            cin >> st >> en >> w;
            graph[st].push_back({w, en});
        }
        dijkstra(s, e);
        setBanned(s, e);
        cout << dijkstra(s, e) << '\n';
    }
    return 0;
}