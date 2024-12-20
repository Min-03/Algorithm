#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[201];
int prevs[201];
int dists[201];

void dijkstra(int s) {
    memset(dists, inf, sizeof(dists));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dists[s] = 0;
    pq.push({dists[s], s});
    while(!pq.empty()) {
        auto [dist, curr] = pq.top(); pq.pop();
        // cout << curr << endl;
        if (dist != dists[curr]) continue;
        for (auto [w, next] : graph[curr]) {
            if (dists[next] <= dist + w) continue;
            dists[next] = dist + w;
            prevs[next] = curr;
            pq.push({dists[next], next});
        }
    }
}

int main() {
    FASTIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
                continue;
            }
            int curr = j;
            while (prevs[curr] != i) curr = prevs[curr];
            cout << curr << " ";
        }
        cout << '\n';
    }
    return 0;
}