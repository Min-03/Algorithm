#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[101];
int cnts[101];

int bfs(int s) {
    memset(cnts, -1, sizeof(cnts));
    cnts[s] = 0;
    queue<int> q;
    q.push(s);
    int ret = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ret += cnts[curr];
        for (int ngb : graph[curr]) {
            if (cnts[ngb] == -1) {
                cnts[ngb] = cnts[curr] + 1;
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
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int before = 1e6, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (bfs(i) < before) {
            before = bfs(i);
            ans = i;
        }
    }
    cout << ans;
    return 0;
}