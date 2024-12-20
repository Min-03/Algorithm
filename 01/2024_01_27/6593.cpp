#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct point {
    int x, y, z;
};

char graph[30][30][30];
int dist[30][30][30];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int l, r, c;

void bfs(int sx, int sy, int sz) {
    memset(dist, -1, sizeof(dist));
    queue<point> q;
    q.push({sx, sy, sz});
    dist[sx][sy][sz] = 0;
    while (!q.empty()) {
        auto [x, y, z] = q.front(); q.pop();
        if (graph[x][y][z] == 'E') {
            cout << "Escaped in " << dist[x][y][z] << " minute(s).\n";
            return;
        }
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l || dist[nx][ny][nz] != -1 || graph[nx][ny][nz] == '#') continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!\n";
}

int main() {
    FastIO
    while (true) {
        int sx, sy, sz;
        cin >> l >> r >> c;
        if (l == r && r == c && c == 0) break;
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> graph[i][j][k];
                    if (graph[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
            }
        }
        bfs(sx, sy, sz);
    }
    return 0;
}