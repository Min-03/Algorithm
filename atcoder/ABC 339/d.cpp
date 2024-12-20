#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[60][60];
int dists[60][60][60][60];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int bfs(int sx1, int sy1, int sx2, int sy2) {
    queue<tuple<int, int, int, int>> q;
    q.push({sx1, sy1, sx2, sy2});
    dists[sx1][sy1][sx2][sy2] = 0;
    while (!q.empty()) {
        auto [x1, y1, x2, y2] = q.front(); q.pop();
        if (x1 == x2 && y1 == y2) {
            return dists[x1][y1][x2][y2];
        }
        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || graph[nx1][ny1] == '#') {
                nx1 = x1;
                ny1 = y1;
            }
            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || graph[nx2][ny2] == '#') {
                nx2 = x2;
                ny2 = y2;
            }
            if (dists[nx1][ny1][nx2][ny2] == -1) {
                q.push({nx1, ny1, nx2, ny2});
                dists[nx1][ny1][nx2][ny2] = dists[x1][y1][x2][y2] + 1;
            }
        }
    }
    return -1;
}


int main() {
    FastIO
    int sx[] = {-1, -1};
    int sy[] = {-1, -1};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'P') {
                if (sx[0] == -1) {
                    sx[0] = i;
                    sy[0] = j;
                } else {
                    sx[1] = i;
                    sy[1] = j;
                }
            }
        }
    }
    memset(dists, -1, sizeof(dists));
    cout << bfs(sx[0], sy[0], sx[1], sy[1]);
    return 0;
}