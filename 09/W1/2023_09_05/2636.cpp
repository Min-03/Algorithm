#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y];
}

int calCheese() {
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny)) {
                if (graph[nx][ny] == 1) ret++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return ret;
}

void bfs() {
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    vector<pair<int, int>> melt;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny)) {
                visited[nx][ny] = true;
                if (graph[nx][ny] == 1) {
                    melt.push_back({nx, ny});
                } else {
                    q.push({nx, ny});
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

    int ans = 0, before = 0;
    while (true) {
        int cheeseCnt = calCheese();
        if (cheeseCnt == 0) break;
        bfs();
        ans++;
        before = cheeseCnt;
    }
    cout << ans << '\n' << before;
    return 0;
}