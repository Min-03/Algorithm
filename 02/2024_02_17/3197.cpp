#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[1500][1500];
int dists[1500][1500];
bool visited[1500][1500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int r, c, sx, sy, ex, ey;

void bfs() {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || graph[nx][ny] != 'X' || dists[nx][ny]) continue;
            q.push({nx, ny});
            dists[nx][ny] = dists[x][y] + 1;
        }
    }
}

bool check(int n) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> qq;
    qq.push({sx, sy});
    visited[sx][sy] = true;
    while (!qq.empty()) {
        auto [x, y] = qq.front(); qq.pop();
        if (x == ex && y == ey) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || dists[nx][ny] > n) continue;
            qq.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return false;
}

int main() {
    FastIO
    cin >> r >> c;
    vector<pair<int, int>> ducks;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 'X') q.push({i, j});
            if (graph[i][j] == 'L') ducks.push_back({i, j});
        }
    }
    tie(sx, sy) = ducks[0];
    tie(ex, ey) = ducks[1];
    bfs();
    int lo = -1, hi = max(r, c) + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}