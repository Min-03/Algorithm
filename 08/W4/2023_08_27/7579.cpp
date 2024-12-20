#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int costs[101], memories[101];
long long dp[10'001];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> memories[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    for (int i = 1; i <= n; i++) {
        int cost = costs[i];
        int memory = memories[i];
        for (int j = 10'000; j >= cost; j--) {
            dp[j] = max(dp[j], memory + dp[j - cost]);
        }
    }

    for (int i = 0; i <= 10'000; i++) {
        if (dp[i] >= m) {
            cout << i;
            break;
        }
    }

    return 0;
}