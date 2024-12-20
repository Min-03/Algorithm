#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000];
int dist[1000][1000][11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k;

int bfs() {
    dist[0][0][0] = 1;
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        int x, y, numBreak;
        tie(x, y, numBreak) = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist[x][y][numBreak];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (graph[nx][ny] == 0 && dist[nx][ny][numBreak] == -1) {
                    dist[nx][ny][numBreak] = dist[x][y][numBreak] + 1;
                    q.emplace(nx, ny, numBreak);
                } else if (numBreak + 1 <= k && graph[nx][ny] == 1 && dist[nx][ny][numBreak + 1] == -1){
                    dist[nx][ny][numBreak + 1] = dist[x][y][numBreak] + 1;
                    q.emplace(nx, ny, numBreak + 1);
                }
            }
        }
    }
    return -1;
}


int main() {
    FastIO
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }
    memset(dist, -1, sizeof(dist));
    cout << bfs();
    return 0;
}