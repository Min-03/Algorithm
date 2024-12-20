#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[500][500], graph[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;

int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[x][y] >= graph[nx][ny]) continue;
        ret = max(ret, dfs(nx, ny));
    }
    return dp[x][y] = ret + 1;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}