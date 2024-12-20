#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> fire;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void spread() {
    int qSize = fire.size();
    while (qSize--) {
        auto [x, y] = fire.front(); fire.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == 'F' || graph[nx][ny] == '#') continue;
            fire.push({nx, ny});
            graph[nx][ny] = 'F';
        }
    }
}

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        spread();
        int qSize = q.size();
        while (qSize--) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) return dist[x][y] + 1;
                if (dist[nx][ny] != -1 || graph[nx][ny] == 'F' || graph[nx][ny] == '#') continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'J') {
                sx = i;
                sy = j;
            } else if (graph[i][j] == 'F') fire.push({i, j});
        }
    }
    memset(dist, -1, sizeof(dist));
    int res = bfs(sx, sy);
    cout << (res == -1 ? "IMPOSSIBLE" : to_string(res));
    return 0;
}