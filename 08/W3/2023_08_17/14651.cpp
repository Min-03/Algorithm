#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long dp[33'334];

int main() {
    FastIO
    int n;
    cin >> n;
    dp[1] = 0, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = 3 * dp[i - 1] % 1'000'000'009;
    }
    cout << dp[n];
    return 0;
}