#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[501];
int dist[501];

int bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int ret = -1;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (dist[curr] > 2) break;
        ret++;
        for (int ngb : graph[curr]) {
            if (dist[ngb] == -1) {
                dist[ngb] = dist[curr] + 1;
                q.push(ngb);
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist));
    cout << bfs();
    return 0;
}