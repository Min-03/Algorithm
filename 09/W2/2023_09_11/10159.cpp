#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[101];
bool visited[101];

//start에서 end를 갈 수 있으면 true
bool bfs(int start, int end) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == end) return true;
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                visited[ngb] = true;
                q.push(ngb);
            }
        }
    }
    return false;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int heavy, light;
        cin >> heavy >> light;
        graph[heavy].push_back(light);
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            memset(visited, 0, sizeof(visited));
            bool cmp1 = bfs(i, j);
            memset(visited, 0, sizeof(visited));
            bool cmp2 = bfs(j, i);
            if (!cmp1 && !cmp2) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}