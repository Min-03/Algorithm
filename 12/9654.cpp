#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int dp[1001];

int canWin(int n) {
    if (n < 0) return 1;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    return dp[n] = max({!canWin(n - 1), !canWin(n - 3), !canWin(n - 4)});
}
int main() {
    FASTIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = -1;
    cout << (canWin(n) ? "SK" : "CY");
    return 0;
}