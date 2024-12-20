#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[500][500];
int dp[500][500]; //해당 칸에서 갈 수 있는 경우의 수
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n;

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[x][y] <= graph[nx][ny]) continue;
        ret += dfs(nx, ny);
    }
    return dp[x][y] = ret;
}

int main() {
    FastIO
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    dp[n - 1][m - 1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    cout << dfs(0, 0);
    return 0;
}