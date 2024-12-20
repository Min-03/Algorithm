#include <bits/stdc++.h>
using namespace std;

int days[1000][1000];
int graph[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int m, n;

void bfs() {
    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        int cnt = days[currX][currY];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = currX + dx[i];
            int ny = currY + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (graph[nx][ny] == 0 && (days[nx][ny] == -1 || days[nx][ny] > cnt + 1)) {
                    days[nx][ny] = cnt + 1;
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
    cin >> m >> n;
    vector<pair<int, int>> zeros;
    memset(days, -1, sizeof(days));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                zeros.emplace_back(i, j);
            } else if (graph[i][j] == 1) {
                q.emplace(i, j);
                days[i][j] = 0;
            }
        }
    }
    bfs();
    int ans = 0;
    for (pair<int, int> zero : zeros) {
        int day = days[zero.first][zero.second];
        if (day == -1) {
            cout << -1;
            return 0;
        } else {
            ans = max(ans, day);
        }
    }
    cout << ans;
    return 0;
}