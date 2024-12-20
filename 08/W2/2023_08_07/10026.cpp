#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

void bfs(int x, int y, bool isBlind) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                if (graph[x][y] == 'B') {
                    if (graph[nx][ny] == 'B') {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
                    if (isBlind) {
                        if (graph[nx][ny] != 'B') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    } else {
                        if (graph[nx][ny] == graph[x][y]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int ansBlind = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, false);
                ans += 1;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, true);
                ansBlind += 1;
            }
        }
    }

    cout << ans << ' ' << ansBlind;
    return 0;
}