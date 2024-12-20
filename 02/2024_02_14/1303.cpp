#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[100][100];
bool visited[100][100];
long long ansB = 0, ansW = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[x][y] != graph[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    if (graph[sx][sy] == 'W') ansW += cnt * cnt;
    else ansB += cnt * cnt;
}

int main() {
    FastIO
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> graph[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) bfs(i, j);
        }
    }
    cout << ansW << ' ' << ansB;
    return 0;
}