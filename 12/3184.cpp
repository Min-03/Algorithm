#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

char graph[250][251];
bool visited[250][250];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, totalWolf = 0, totalSheep = 0;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    visited[sx][sy] = true;
    q.push({sx, sy});
    int wolf = 0, sheep = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (graph[x][y] == 'o') sheep++;
        else if (graph[x][y] == 'v') wolf++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == '#' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (wolf >= sheep) totalWolf += wolf;
    else totalSheep += sheep;
}

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> graph[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != '#' && !visited[i][j]) bfs(i, j);
        }
    }
    cout << totalSheep << ' ' << totalWolf;
    return 0;
}