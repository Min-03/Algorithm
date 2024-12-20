#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[50][50];
int type[50][50];
int cnts[2501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, l, r;

void bfs(int sx, int sy, int color) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    type[sx][sy] = color;
    int size = 0, people = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        size += graph[x][y];
        people++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || type[nx][ny]) continue;
            int diff = abs(graph[x][y] - graph[nx][ny]);
            if (l <= diff && diff <= r) {
                q.push({nx, ny});
                type[nx][ny] = color;
            }
        }
    }
    cnts[color] = size / people;
}

int main() {
    FastIO
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    int day = 0;
    while (true) {
        memset(type, 0, sizeof(type));
        memset(cnts, 0, sizeof(cnts));
        int color = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (type[i][j] == 0) bfs(i, j, ++color);
            }
        }
        if (color == n * n) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = cnts[type[i][j]];
            }
        }
        day++;
    }
    cout << day;
    return 0;
}