#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[100][100];
int cnts[100][100][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int w, h;

int bfs(int sx, int sy, int ex, int ey) {
    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, -1, -1});
    cnts[sx][sy][0] = cnts[sx][sy][1] = 0;
    vector<int> ret;
    while (!q.empty()) {
        auto [x, y, pdx, pdy] = q.front(); q.pop();
        if (x == ex && y == ey) {
            ret.push_back(cnts[x][y][pdx == 0] - 1);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (0 <= nx && nx < h && 0 <= ny && ny < w && cnts[nx][ny][dx[i] == 0] == -1 && graph[nx][ny] != '*') {
                cnts[nx][ny][dx[i] == 0] = cnts[x][y][pdx == 0] + 1;
                q.push({nx, ny, dx[i], dy[i]});
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    return *min_element(ret.begin(), ret.end());
}

int main() {
    FastIO
    cin >> w >> h;
    int sx = -1, sy, ex, ey;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'C') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                } else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    memset(cnts, -1, sizeof(cnts));
    cout << bfs(sx, sy, ex, ey);
    return 0;
}