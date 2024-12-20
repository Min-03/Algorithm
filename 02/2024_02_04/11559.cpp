#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[12][6];
bool visited[12][6];
int n = 12, m = 6;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool bfs(int sx, int sy) {
    queue<pair<int, int>> q, nxt;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        nxt.push(q.front());
        q.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] != graph[x][y]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    if (ret < 4) return false;
    while (!nxt.empty()) {
        auto [x, y] = nxt.front(); nxt.pop();
        graph[x][y] = '.';
    }
    return true;
}

bool isPuyo() {
    memset(visited, 0, sizeof(visited));
    bool isBreak = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] != '.') {
                if (bfs(i, j)) isBreak = true;
            }
        }
    }
    return isBreak;
}

void moveDown() {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != '.') continue;
            int nxt = i;
            while (nxt >= 0 && graph[nxt][j] == '.') nxt--;
            if (nxt >= 0) {
                graph[i][j] = graph[nxt][j];
                graph[nxt][j] = '.';
            }
            else graph[i][j] = '.';
        }
    }
}


int main() {
    FastIO
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> graph[i][j];
    }
    int cnt = 0;
    while (isPuyo()) {
        cnt++;
        moveDown();
    }
    cout << cnt;
    return 0;
}