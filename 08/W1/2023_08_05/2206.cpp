#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000];
int dist[1000][1000][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int bfs() {
    queue<tuple<int, int, bool>> q;
    q.emplace(0, 0, false);
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x, y;
        bool breaked;
        tie(x, y, breaked) = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist[x][y][breaked];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                //벽이 없음
                if (graph[nx][ny] == 0) {
                    if (dist[nx][ny][breaked] == -1) {
                        q.emplace(nx, ny, breaked);
                        dist[nx][ny][breaked] = dist[x][y][breaked] + 1;
                    }
                } else { //벽이 있음
                    if (!breaked && dist[nx][ny][true] == -1) {
                        q.emplace(nx, ny, true);
                        dist[nx][ny][1] = dist[x][y][breaked] + 1;
                    }
                }
            }
        }
    }
    return -1;
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
    memset(dist, -1, sizeof(dist));
    cout << bfs();
    return 0;
}
