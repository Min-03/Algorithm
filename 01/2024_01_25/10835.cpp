#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[2000][2000];
int a[2000], b[2000];
int n;

int go(int x, int y) {
    if (x >= n || y >= n) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int ret = max(go(x + 1, y + 1), go(x + 1, y));
    if (a[x] > b[y]) ret = max(ret, go(x, y + 1) + b[y]);
    return dp[x][y] = ret;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
    return 0;
}