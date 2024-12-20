#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[31], sym[31];

int main() {
    FastIO
    int n;
    cin >> n;
    sym[1] = dp[1] = 1;
    sym[2] = dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        sym[i] = sym[i - 2];
        if (i == 4) sym[i] += 2;
        if (i > 4) sym[i] += 2 * sym[i - 4];
    }
    cout << dp[n] << ' ' << sym[n] << '\n';
    return 0;
}