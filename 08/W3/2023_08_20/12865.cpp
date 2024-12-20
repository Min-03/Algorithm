#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int w[101];
int v[101];
int dp[101][100'001];

int go(int line, int weightLeft) {
    if (line == 0) {
        return 0;
    }

    if (dp[line][weightLeft] != 0) {
        return dp[line][weightLeft];
    }

    int currW = w[line], currV = v[line];
    if (weightLeft - currW >= 0) {
        return dp[line][weightLeft] = max(go(line - 1, weightLeft - currW) + currV, go(line - 1, weightLeft));
    } else {
        return dp[line][weightLeft] = go(line - 1, weightLeft);
    }
}

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << go(n, k);
    return 0;
}