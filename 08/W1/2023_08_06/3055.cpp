#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[50][50];
bool visited[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> water;
int r, c;

void spreadWater() {
    int qSize = water.size();
    while (qSize--) {
        int x, y;
        tie(x, y) = water.front(); water.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && graph[nx][ny] == '.') {
                graph[nx][ny] = '*';
                water.push({nx, ny});
            }
        }
    }
}

int bfs(int startX, int startY, int endX, int endY) {
    visited[startX][startY] = true;
    queue<pair<int, int>> q;
    q.push({startX, startY});
    int ret = 0;
    while (!q.empty()) {
        int x, y;
        int qSize = q.size();
        spreadWater();
        while (qSize--) {
            tie(x, y) = q.front(); q.pop();
            if (x == endX && y == endY) {
                return ret;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny] && (graph[nx][ny] == '.' || graph[nx][ny] == 'D')) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ret += 1;
    }
    return -1;
}

int main() {
    FastIO
    int startX, startY, endX, endY;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (graph[i][j] == 'D') {
                endX = i;
                endY = j;
            } else if (graph[i][j] == '*') {
                water.push({i, j});
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    int res = bfs(startX, startY, endX, endY);
    if (res == -1) {
        cout << "KAKTUS";
    } else {
        cout << res;
    }
    return 0;
}