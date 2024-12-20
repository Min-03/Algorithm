#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[1000][1000];
int graph[1000][1000];
int visited[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int x, int y, int color) {
    queue<pair<int, int>> q, wall;
    q.emplace(x, y);
    visited[x][y] = color;
    int cnt = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        cnt += 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (graph[nx][ny] == 0 && visited[nx][ny] == 0) {
                    visited[nx][ny] = color;
                    q.emplace(nx, ny);
                }
                else if (graph[nx][ny] == 1 && visited[nx][ny] != color){
                    visited[nx][ny] = color;
                    wall.emplace(nx, ny);
                }
            }
        }
    }
    while (!wall.empty()) {
        tie(x, y) = wall.front(); wall.pop();
        cnts[x][y] += cnt;
    }
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }

    int color = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0 && !visited[i][j]) {
                bfs(i, j, color++);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) cout << (cnts[i][j] + 1) % 10;
            else cout << '0';
        }
        cout << '\n';
    }
    return 0;
}