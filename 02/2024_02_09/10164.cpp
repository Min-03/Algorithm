#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[31][31];

int main() {
    FastIO
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    int n, m, k;
    cin >> n >> m >> k;
    int sx = 0, sy = 0, ex = n - 1, ey = m - 1;
    if (k == 0) {
        cout << dp[ex - sx + ey - sy][ex - sx];
        return 0;
    }
    k--;
    int tx = k / m, ty = k % m;
    cout << dp[tx - sx + ty - sy][tx - sx] * dp[ex - tx + ey - ty][ex - tx];
    return 0;
}