#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1'500'002];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + t  <= n + 1) dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    cout << max(dp[n], dp[n + 1]);
    return 0;
}