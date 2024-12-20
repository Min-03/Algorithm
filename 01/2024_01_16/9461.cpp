#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
int main() {
    FastIO
    for (int i = 11; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}