#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1'000'001];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v, c, k;
        cin >> v >> c >> k;
        vector<int> nums;
        for (int j = 1; j <= k; j *= 2) {
            nums.push_back(j);
        }
        int sub = nums.back() * 2 - 1 - k;
        nums.back() -= sub;
        for (int num : nums) {
            int cost = num * v;
            int value = num * c;
            for (int j = m; j >= cost; j--) {
                dp[j] = max(dp[j], value + dp[j - cost]);
            }
        }
    }
    cout << dp[m];
    return 0;
}