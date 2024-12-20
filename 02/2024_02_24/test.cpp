#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[10'001][4];

int main() {
    FastIO
    for (int i = 1; i <= 10'000; i++) dp[i][1] = 1;
    dp[2][2] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= 10'000; i++) {
        dp[i][2] = dp[i - 2][2] + dp[i - 2][1];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
    return 0;
}