#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool graph[200][200];
int dist[200][200][31];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int tdx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int tdy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int w, h, k;

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, k});
    dist[0][0][k] = 0;
    while (!q.empty()) {
        auto [x, y, cnt] = q.front(); q.pop();
        if (x == h - 1 && y == w - 1) {
            return dist[x][y][cnt];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || graph[nx][ny] || dist[nx][ny][cnt] != -1) continue;
            q.push({nx, ny, cnt});
            dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
        }
        if (cnt <= 0) continue;
        for (int i = 0; i < 8; i++) {
            int nx = x + tdx[i];
            int ny = y + tdy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || graph[nx][ny] || dist[nx][ny][cnt - 1] != -1) continue;
            q.push({nx, ny, cnt - 1});
            dist[nx][ny][cnt - 1] = dist[x][y][cnt] + 1;
        }
    }
    return -1;
}

int main() {
    FastIO
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> graph[i][j];
    }
    memset(dist, -1, sizeof(dist));
    cout << bfs();
    return 0;
}