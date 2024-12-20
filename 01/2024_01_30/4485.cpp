#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int graph[125][125];
int costs[125][125];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int bfs() {
    queue<pair<int, int>> q;
    costs[0][0] = graph[0][0];
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || costs[x][y] + graph[nx][ny] >= costs[nx][ny]) continue;
            costs[nx][ny] = costs[x][y] + graph[nx][ny];
            q.push({nx, ny});
        }
    }
    return costs[n - 1][n - 1];
}

int main() {
    FastIO
    int cnt = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        memset(costs, inf, sizeof(costs));
        cout << "Problem " << cnt++ << ": " << bfs() << '\n';
    }
    return 0;
}