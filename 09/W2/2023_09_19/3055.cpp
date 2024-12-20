#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[50][50];
int dists[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int r, c;

int bfs(int sx, int sy) {
    q.push({sx, sy});
    dists[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (graph[x][y] == 'D') return dists[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && dists[nx][ny] == -1 && graph[nx][ny] != 'X' && graph[nx][ny] != '*') {
                if (graph[nx][ny] == 'D' && graph[x][y] == '*') {
                    continue;
                }
                dists[nx][ny] = dists[x][y] + 1;
                q.push({nx, ny});
                if (graph[x][y] == '*') graph[nx][ny] = '*';
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    int sx = -1, sy = -1;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (graph[i][j] == '*') {
                q.push({i, j});
            }
        }
    }
    memset(dists, -1, sizeof(dists));
    int ans = bfs(sx, sy);
    cout << (ans == -1 ? "KAKTUS" : to_string(ans));
    return 0;
}