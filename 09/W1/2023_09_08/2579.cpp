#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int scores[301], dp[301][3];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }
    dp[1][1] = scores[1];
    dp[2][1] = scores[2];
    dp[2][2] = scores[1] + scores[2];
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + scores[i];
        dp[i][2] = dp[i - 1][1] + scores[i];
    }
    cout << max(dp[n][1], dp[n][2]);
    return 0;
}