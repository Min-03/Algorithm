#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int color[100][100];
bool visited[100][100];
int dist[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n;

void dfs(int x, int y, int cnt) {
    color[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && color[nx][ny] == 0 && graph[nx][ny] == 1) {
            dfs(nx, ny, cnt);
        }
    }
}

int bfs(int type) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (color[x][y] != 0 && color[x][y] != type) {
            return dist[x][y] - 1;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && color[i][j] == 0) {
                dfs(i, j, cnt++);
            }
        }
    }

    int length = 1000;
    for (int index = 1; index <= cnt - 1; index++) {
        //i번째 육지에서 다른 육지로 가는 최단 경로 탐색
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (color[i][j] == index) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
        int res = bfs(index);
        length = min(length, res);
        memset(visited, 0, sizeof(visited));
        memset(dist, -1, sizeof(dist));
        q = queue<pair<int, int>>();
    }
    cout << length;
    return 0;
}
