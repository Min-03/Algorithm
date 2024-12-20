#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[50][50];
int changed[50][50]; //얼마나 증가? 감소?
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int r, c, t;

bool check(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void spreadDust() {
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] > 0) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && graph[nx][ny] != -1) {
                changed[nx][ny] += graph[x][y] / 5;
                changed[x][y] -= graph[x][y] / 5;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            graph[i][j] += changed[i][j];
        }
    }
}

void moveWind(int x, int y, int dir, bool reversed) {
    changed[x][y] -= graph[x][y];
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (check(nx, ny)) {
        if (graph[nx][ny] == -1) {
            return;
        }
        changed[nx][ny] += graph[x][y];
        moveWind(nx, ny, dir, reversed);
    } else {
        if (reversed) dir = (dir - 1 + 4) % 4;
        else dir = (dir + 1) % 4;
        nx = x + dx[dir];
        ny = y + dy[dir];
        changed[nx][ny] += graph[x][y];
        moveWind(nx, ny, dir, reversed);
    }
}

int main() {
    FastIO
    int topX, topY, botX, botY;
    topX = topY = botX = botY = -1;
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                if (topX == -1) {
                    topX = i;
                    topY = j;
                } else {
                    botX = i;
                    botY = j;
                }
            }
        }
    }
    while (t > 0) {
        memset(changed, 0, sizeof(changed));
        spreadDust();
        memset(changed, 0, sizeof(changed));
        moveWind(topX, topY + 1, 0, true);
        moveWind(botX, botY + 1, 0, false);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                graph[i][j] += changed[i][j];
            }
        }
        t--;
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] != -1) ans += graph[i][j];
        }
    }
    cout << ans;
    return 0;
}