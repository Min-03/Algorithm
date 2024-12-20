#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pair<int, int>> graph[1001];
int dist[1001];
int parent[1001];

void dijkstra(int x) {
    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dist[curr] < w) continue;
        for (auto [next, nw] : graph[curr]) {
            if (dist[curr] + nw < dist[next]) {
                dist[next] = dist[curr] + nw;
                parent[next] = curr;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    FastIO
    int n, m, start, dest;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> start >> dest;
    memset(dist, inf, sizeof(dist));

    dijkstra(start);
    cout << dist[dest] << '\n';
    int curr = dest;
    stack<int> s;
    while (curr != start) {
        s.push(curr);
        curr = parent[curr];
    }
    s.push(start);
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' '; s.pop();
    }
    return 0;
}