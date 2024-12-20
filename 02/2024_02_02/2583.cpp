#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool visited[100][100], banned[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k;

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || banned[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> m >> n >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                banned[i][j] = true;
            }
        }
    }
    vector<int> sizes;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] || banned[i][j]) continue;
            sizes.push_back(bfs(i, j));
        }
    }
    cout << sizes.size() << '\n';
    sort(sizes.begin(), sizes.end());
    for (int i : sizes) cout << i << ' ';
    return 0;
}