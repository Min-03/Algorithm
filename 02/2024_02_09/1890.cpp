#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100];
long long dp[100][100];
int n;

long long dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == n - 1 && y == n - 1) return 1;
    int step = graph[x][y];
    if (step == 0) return 0;
    long long ret = 0;
    int nx = x + step, ny = y + step;
    if (nx < n) ret += dfs(nx, y);
    if (ny < n) ret += dfs(x, ny);
    return dp[x][y] = ret;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
    return 0;
}