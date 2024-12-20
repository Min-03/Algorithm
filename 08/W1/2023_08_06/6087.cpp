#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

char graph[100][100];
int cnts[100][100][2]; // 0 : 세로, 1 : 가로
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int w, h;

void bfs(pii start, pii end) {
    int startX, startY, endX, endY;
    tie(startX, startY) = start;
    tie(endX, endY) = end;
    cnts[startX][startY][0] = cnts[startX][startY][1] = 0;
    queue<pair<pii, pii>> q; // (x, y), (dx[i], dy[i])
    q.push({{startX, startY}, {-1, -1}});
    while (!q.empty()) {
        int x, y, pdx, pdy;
        pii curr, prevDir;
        tie(curr, prevDir) = q.front(); q.pop();
        tie(x, y) = curr;
        tie(pdx, pdy) = prevDir;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && graph[nx][ny] != '*') {
                if (dx[i] == pdx && dy[i] == pdy && (cnts[nx][ny][dx[i] == 0] == -1 || cnts[nx][ny][dx[i] == 0] > cnts[x][y][pdx == 0])) {
                    cnts[nx][ny][dx[i] == 0] = cnts[x][y][pdx == 0];
                    q.push({{nx,ny},{dx[i],dy[i]}});
                } else if (cnts[nx][ny][dx[i] == 0] == -1 || cnts[nx][ny][dx[i] == 0] > cnts[x][y][pdx == 0] + 1) {
                    cnts[nx][ny][dx[i] == 0] = cnts[x][y][pdx == 0] + 1;
                    q.push({{nx, ny},{dx[i],dy[i]}});
                }
            }
        }
    }
}

int main() {
    FastIO
    cin >> w >> h;
    vector<pii> mirrors;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'C') {
                mirrors.push_back({i, j});
            }
        }
    }
    memset(cnts, -1 , sizeof(cnts));
    bfs(mirrors[0], mirrors[1]);
    int x, y;
    tie(x, y) = mirrors[1];
    int ans;
    if (cnts[x][y][0] != -1 && cnts[x][y][1] != -1) {
        ans = min(cnts[x][y][0], cnts[x][y][1]);
    } else if (cnts[x][y][0] != -1) {
        ans = cnts[x][y][0];
    } else {
        ans = cnts[x][y][1];
    }
    cout << ans - 1;
    return 0;
}