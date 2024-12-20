#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[100'001][2] = {0, };
    cin >> dp[1][0];
    for (int i = 2; i <= n; i++) {
        int curr;
        cin >> curr;
        dp[i][0] = max(dp[i - 1][0] + curr, curr);
        dp[i][1] = max(dp[i - 1][1] + curr, dp[i - 2][0] + curr);
    }

    int maxDefault = -1000;
    for (int i = 1; i <= n; i++) {
        maxDefault = max(maxDefault, dp[i][0]);
    }
    if (maxDefault < 0) {
        cout << maxDefault;
        return 0;
    }
    int maxDelete = -1000;
    for (int i = 1; i <= n; i++) {
        maxDelete = max(maxDelete, dp[i][1]);
    }
    cout << max(maxDelete, maxDefault);
}