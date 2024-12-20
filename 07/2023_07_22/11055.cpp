#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[1001];
    int dp[1001];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
}