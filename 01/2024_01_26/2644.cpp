#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dist[101];
vector<int> graph[101];

int bfs(int s, int e) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (dist[ngb] == -1) {
                dist[ngb] = dist[curr] + 1;
                q.push(ngb);
            }
        }
    }
    return dist[e];
}

int main() {
    FastIO
    int n, m, a, b;
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    cout << bfs(a, b);
    return 0;
}