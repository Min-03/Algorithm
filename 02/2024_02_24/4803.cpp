#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[501];
bool visited[501];

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int nodeCnt = 0, edgeCnt = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        nodeCnt++;
        for (int ngb : graph[curr]) {
            edgeCnt++;
            if (!visited[ngb]) {
                q.push(ngb);
                visited[ngb] = true;
            }
        }
    }
    edgeCnt /= 2;
    return nodeCnt == edgeCnt + 1;
}

int main() {
    FastIO
    int tc = 1;
    while (true) {
        int n, m, cnt = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) graph[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && bfs(i)) cnt++;
        }
        cout << "Case " << tc << ": ";
        if (cnt == 0) cout << "No trees.\n";
        else if (cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
        tc++;
    }
    return 0;
}