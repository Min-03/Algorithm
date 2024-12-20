#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int color[100][100];
int dist[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n;

void dfs(int x, int y, int group) {
    color[x][y] = group;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (graph[nx][ny] == 1 && color[nx][ny] == 0) {
                dfs(nx, ny, group);
            }
        }
    }
}

void spreadLand() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (color[nx][ny] == 0) {
                    color[nx][ny] = color[x][y];
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
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

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && color[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (color[i][j] != 0) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }
    spreadLand();

    int length = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n - 1 && color[i][j] != color[i + 1][j]) {
                length = min(length, dist[i][j] + dist[i + 1][j]);
            }
            if (j < n - 1 && color[i][j] != color[i][j + 1]) {
                length = min(length, dist[i][j] + dist[i][j + 1]);
            }
        }
    }
    cout << length;
    return 0;
}