#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[31];

int main() {
    FastIO
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    if (n <= 2) {
        cout << dp[n];
    } else {
        if (n <= 3) {
            cout << dp[n] - 2;
        } else if (n <= 4) {
            cout << dp[n] - 2 * (dp[n - 3]) - 1;
        } else {
            cout << dp[n] - 2 * (dp[n - 3]) - (dp[n - 4]);
        }
    }
    return 0;
}