#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

char graph[50][50];
int dists[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int bfs(int sx, int sy) {
    memset(dists, -1, sizeof(dists));
    dists[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int ret = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ret = max(ret, dists[x][y]);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dists[nx][ny] != -1 || graph[nx][ny] == 'W') continue;
            q.push({nx, ny});
            dists[nx][ny] = dists[x][y] + 1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> graph[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'L') ans = max(ans, bfs(i, j));
        }
    }
    cout << ans;
}