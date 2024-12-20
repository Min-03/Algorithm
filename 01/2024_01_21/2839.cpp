#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dp[5001];

int main() {
    FastIO
    memset(dp, inf, sizeof(dp));
    int n;
    cin >> n;

    dp[0] = 0;
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= n; i++) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    }
    cout << (dp[n] >= inf ? -1 : dp[n]);
    return 0;
}