#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[500][500];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> dp[i][j];
            if (i == 0) continue;

            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
            } else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    int answer;
    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[n - 1][i]);
    }
    cout << answer;
    return 0;
}