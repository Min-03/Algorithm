#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[1'000'001];
int dist[1'000'001];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (dist[ngb] == -1) {
                q.push(ngb);
                dist[ngb] = dist[curr] + 1;
            }
        }
    }
}

int main() {
    FastIO
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    memset(dist, -1, sizeof(dist));
    bfs(x);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << '\n';
            ok = true;
        }
    }
    if (!ok) cout << -1;
    return 0;
}