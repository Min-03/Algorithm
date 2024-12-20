#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int costs[20], values[20];
int dp[101];

int main() {
    FASTIO
    int n, k = 100;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> costs[i];
    for (int i = 0; i < n; i++) cin >> values[i];
    for (int i = 0; i < n; i++) {
        for (int j = k; j - costs[i] > 0; j--) {
            dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
        }
    }
    cout << dp[k];
}
