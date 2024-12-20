#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int graph[1000][1000];
bool visited[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == 1 || visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return false;
}

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
    for (int j = 0; j < m; j++) {
        if (graph[0][j] == 0 && !visited[0][j] && bfs(0, j)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}