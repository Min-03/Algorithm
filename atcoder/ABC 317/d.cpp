#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int costs[101];
int candidates[101];
long long dp[101][100'001];
int m, nums = 0, zSum = 0;

long long go(int index, int left) {
    if (left <= 0) {
        return 0;
    }
    if (index <= 0) {
        return 1e18;
    }
    if (dp[index][left] != 0) {
        return dp[index][left];
    }
    dp[index][left] = min(go(index - 1, left), costs[index] + go(index - 1, left - candidates[index]));
    return dp[index][left];
}

int main() {
    FastIO
    int n, taka = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        zSum += z;
        if (x > y) {
            taka += z;
        } else {
            costs[++nums] = (x + y) / 2 + 1 - x;
            candidates[nums] = z;
        }
    }
    m = (zSum + 1) / 2;
    m -= taka;
    cout << go(nums, m);
    return 0;
}