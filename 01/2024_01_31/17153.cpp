#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[16][16], original[16][16], dist[16][16];
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
queue<pair<int, int>> del;
int n, m, d;

void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({n, s});
    dist[n][s] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (dist[x][y] > d) {
            return;
        } else if (graph[x][y] == 1) {
            del.push({x, y});
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

pair<int, bool> move() {
    int ret = 0;
    while (!del.empty()) {
        auto [x, y] = del.front(); del.pop();
        if (graph[x][y] == 1) {
            ret++;
            graph[x][y] = 0;
        }
    }

    bool isMove = false;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) {
                graph[i][j] = 0;
                if (i == n - 1) continue;
                graph[i + 1][j] = 1;
                isMove = true;
            }
        }
    }
    return {ret, isMove};
}

int sol(int i, int j, int k) {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            graph[a][b] = original[a][b];
        }
    }
    int ret = 0;
    while (true) {
        bfs(i);
        bfs(j);
        bfs(k);
        auto [res, isMove] = move();
        ret += res;
        if (!isMove) return ret;
    }
}

int main() {
    FastIO
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> original[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                ans = max(ans, sol(i, j, k));
            }
        }
    }
    cout << ans;
    return 0;
}