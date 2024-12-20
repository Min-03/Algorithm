#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[1000][1000];
int dists[1000][1000];
bool visited[1000][1000]; // fire 기준
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> fire;
int w, h;

void spreadFire() {
    int qSize = fire.size();
    while (qSize--) {
        auto [x, y] = fire.front(); fire.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && !visited[nx][ny] && graph[nx][ny] != '#') {
                visited[nx][ny] = true;
                graph[nx][ny] = '*';
                fire.push({nx, ny});
            }
        }
    }
}

int bfs(int sx, int sy) {
    dists[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        int qSize = q.size();
        spreadFire();
        while (qSize--) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 > nx || nx >= h || 0 > ny || ny >= w) {
                    return dists[x][y] + 1;
                }
                if (dists[nx][ny] == -1 && graph[nx][ny] != '*' && graph[nx][ny] != '#') {
                    dists[nx][ny] = dists[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int sx = -1, sy = -1;
        cin >> w >> h;
        fire = queue<pair<int, int>>();
        memset(visited, 0, sizeof(visited));
        memset(dists, -1, sizeof(dists));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == '@') {
                    sx = i;
                    sy = j;
                } else if (graph[i][j] == '*') fire.push({i, j});
            }
        }
        int ans = bfs(sx, sy);
        cout << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << '\n';
    }
    return 0;
}