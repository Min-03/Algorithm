#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[1001][3][3] = {0, }; // 처음 선택 색 / 마지막 선택 색
    int memo[1001][3];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> memo[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp[1][i][i] = memo[1][i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = dp[i - 1][j][j] + memo[i][k];
                    if (j == k) dp[i][j][k] = 1e9;
                }
            } else {
                dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][2]) + memo[i][0];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + memo[i][1];
                dp[i][j][2] = min(dp[i - 1][j][0], dp[i - 1][j][1]) + memo[i][2];
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            ans = min(ans, dp[n][i][j]);
        }
    }

    cout << ans;
}
