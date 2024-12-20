#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[300][300], diff[300][300];
bool visited[300][300];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    visited[sx][sy] = true;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    FastIO
    cin >> n >> m;
    queue<pair<int, int>> ice;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0) ice.push({i, j});
        }
    }
    int year = 0;
    while (!ice.empty()) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(diff, 0, sizeof(diff));
        queue<pair<int, int>> nxt;
        while (!ice.empty()) {
            auto [x, y] = ice.front();
            nxt.push(ice.front());
            ice.pop();
            if (!visited[x][y]) {
                bfs(x, y);
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << year;
            return 0;
        }

        while (!nxt.empty()) {
            auto [x, y] = nxt.front();
            ice.push(nxt.front());
            nxt.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny]) continue;
                diff[x][y]++;
            }
        }

        while (!ice.empty()) {
            auto [x, y] = ice.front();
            graph[x][y] = max(0, graph[x][y] - diff[x][y]);
            if (graph[x][y]) nxt.push(ice.front());
            ice.pop();
        }
        ice = nxt;
        year++;
    }
    cout << 0;
    return 0;
}