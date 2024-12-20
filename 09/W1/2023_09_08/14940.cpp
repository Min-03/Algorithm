#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000], dists[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dists[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && dists[nx][ny] == -1 && graph[nx][ny] != 0) {
                dists[nx][ny] = dists[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    FastIO
    cin >> n >> m;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }
    memset(dists, -1, sizeof(dists));
    bfs(sx, sy);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) cout << dists[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}