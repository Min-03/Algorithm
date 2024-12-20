#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int dp[3] = {0, };
    while (n--) {
        int curr;
        cin >> curr;
        int before0 = dp[0];
        dp[0] = max({dp[0] ,dp[1], dp[2]});
        int before1 = dp[1];
        dp[1] = before0 + curr;
        dp[2] = before1 + curr;
    }
    cout << max({dp[0], dp[1], dp[2]});
    return 0;
}