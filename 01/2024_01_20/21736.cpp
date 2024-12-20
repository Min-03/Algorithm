#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[600][600];
bool visited[600][600];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0;
int m, n;

void dfs(int x, int y) {
    visited[x][y] = true;
    if (graph[x][y] == 'P') ans++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 'X') continue;
        dfs(nx, ny);
    }
}

int main() {
    FastIO
    int sx, sy;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy);
    cout << (ans == 0 ? "TT" : to_string(ans));
    return 0;
}