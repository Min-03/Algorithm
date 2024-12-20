#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long dp[15][15];

int main() {
    FastIO
    for (int i = 1; i < 15; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) dp[i][j] = accumulate(dp[i - 1], dp[i - 1] + j + 1, 0LL);
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n] << '\n';
    }
    return 0;
}