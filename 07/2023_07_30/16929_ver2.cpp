#include <bits/stdc++.h>
using namespace std;

int dist[50][50];
bool visited[50][50];
char graph[50][50];
int dx[] = {1, -1, 0 ,0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool isCycle(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == graph[x][y]) {
            if (!visited[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                if (isCycle(nx, ny)) return true;
            } else if ((dist[x][y] + 1) - dist[nx][ny] >= 4) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (isCycle(i, j)) {
                    cout << "Yes";
                    return 0;
                } else {
                    memset(dist, 0, sizeof(dist));
                }
            }
        }
    }
    cout << "No";
    return 0;
}