#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[500'000];

int main() {
    FastIO
    int n, d;
    cin >> n >> d;
    vector<int> nums(n);
    for (int &i : nums) cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(nums[i] - nums[j]) <= d) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int hi = 0;
    for (int i = 0; i < n; i++) hi = max(hi, dp[i]);
    cout << hi + 1;
    return 0;
}