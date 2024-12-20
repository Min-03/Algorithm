#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100][100];
int dist[100][100][100];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int m, n, h;

struct point {
    int x, y, z;
};

bool oob(int x, int y, int z) {
    return x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h;
}

int main() {
    FastIO
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> graph[i][j][k];
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    queue<point> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (graph[i][j][k] == 1) {
                    dist[i][j][k] = 0;
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty()) {
        point p = q.front(); q.pop();
        auto [x, y, z] = p;
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (!oob(nx, ny, nz) && graph[nx][ny][nz] == 0 && dist[nx][ny][nz] == -1) {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (graph[i][j][k] != -1) {
                    if (dist[i][j][k] == -1) {
                        cout << -1;
                        return 0;
                    }
                    ans = max(ans, dist[i][j][k]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}