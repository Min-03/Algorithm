#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100];
int visited[100][100]; //방문 횟수
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool isCheese() {
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (graph[x][y] == 1) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inRange(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void bfs() {
    memset(visited, 0, sizeof(visited));
    vector<pair<int, int>> melt;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 2;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inRange(nx, ny)) {
                if (visited[nx][ny] == 0) {
                    if (graph[nx][ny] == 0) {
                        visited[nx][ny] = 2;
                        q.push({nx, ny});
                    } else {
                        visited[nx][ny] = 1;
                    }
                } else if (visited[nx][ny] == 1) {
                    visited[nx][ny] = 2;
                    melt.push_back({nx, ny});
                }
            }
        }
    }

    for (auto [x, y] : melt) {
        graph[x][y] = 0;
    }
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int ans = 0;
    while (true) {
        if (!isCheese()) {
            break;
        }
        bfs();
        ans++;
    }
    cout << ans;
    return 0;
}