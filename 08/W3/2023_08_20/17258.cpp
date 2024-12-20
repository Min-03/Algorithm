#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int a[251];
int b[251];
int dp[251][250 * 250 + 1];

int main() {
    FastIO
    int n;
    cin >> n;
    int bSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        bSum += b[i];
    }

    int ans = 1e8;
    for (int i = 0; i <= bSum; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[j - 1][i] + a[j];
            if (i >= b[j] && dp[j][i] > dp[j - 1][i - b[j]]) dp[j][i] = dp[j - 1][i - b[j]];
        }
        ans = min(ans, max(i, dp[n][i]));
    }
    cout << ans;
    return 0;
}