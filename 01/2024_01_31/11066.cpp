#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[501][501];
int costs[501];
int sums[502];

int go(int s, int e) {
    if (s == e) {
        return 0;
    }
    if (dp[s][e] != -1) {
        return dp[s][e];
    }
    int ret = 1e9;
    for (int c = s; c < e; c++) {
        ret = min(ret, go(s, c) + go(c + 1, e));
    }
    return dp[s][e] = ret + sums[e + 1] - sums[s];
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int k;
        cin >> k;
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (int i = 0; i < k; i++) {
            cin >> costs[i];
            sum += costs[i];
            sums[i + 1] = sum;
        }
        cout << go(0, k - 1) << '\n';
    }
    return 0;
}