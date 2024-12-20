#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000];
int dist[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int bfs() {
    deque<pair<int, int>> q;
    q.emplace_back(0, 0);
    dist[0][0] = 0;
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop_front();
        if (x == n - 1 && y == m - 1) {
            return dist[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == -1) {
                if (graph[nx][ny] == 0) {
                    q.emplace_front(nx, ny);
                    dist[nx][ny] = dist[x][y];
                } else {
                    q.emplace_back(nx, ny);
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    cin >> m >> n;
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