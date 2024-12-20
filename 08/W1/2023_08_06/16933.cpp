#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000];
int dist[1000][1000][11][2];
int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};
int n, m, k;

int bfs() {
    dist[0][0][0][0] = 1;
    queue<tuple<int, int, int, bool>> q;
    q.emplace(0, 0, 0, false);
    while (!q.empty()) {
        int x, y, numBreak;
        bool isNight;
        tie(x, y, numBreak, isNight) = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist[x][y][numBreak][isNight];
        }
        for (int i = 0; i < 5; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (graph[nx][ny] == 0 && dist[nx][ny][numBreak][!isNight] == -1) {
                    dist[nx][ny][numBreak][!isNight] = dist[x][y][numBreak][isNight] + 1;
                    q.emplace(nx, ny, numBreak, !isNight);
                } else if (!isNight && numBreak + 1 <= k && graph[nx][ny] == 1 && dist[nx][ny][numBreak + 1][!isNight] == -1){
                    dist[nx][ny][numBreak + 1][!isNight] = dist[x][y][numBreak][isNight] + 1;
                    q.emplace(nx, ny, numBreak + 1, !isNight);
                } else if (x == nx && y == ny && dist[nx][ny][numBreak][!isNight] == -1) {
                    dist[nx][ny][numBreak][!isNight] = dist[x][y][numBreak][isNight] + 1;
                    q.emplace(nx, ny, numBreak, !isNight);
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