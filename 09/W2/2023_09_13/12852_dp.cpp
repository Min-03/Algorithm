#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dp[1'000'001];
int before[1'000'001];

int main() {
    FastIO
    int n;
    cin >> n;
    memset(dp, inf, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
        if (dp[i - 1] + 1 < dp[i]) {
            dp[i] = dp[i - 1] + 1;
            before[i] = i - 1;
        }
    }
    cout << dp[n] << '\n';
    int curr = n;
    while (curr != 1) {
        cout << curr << ' ';
        curr = before[curr];
    }
    cout << 1;
    return 0;
}