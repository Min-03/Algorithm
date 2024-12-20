#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += nums[i];
    }
    ans -= k * (k - 1) / 2;
    cout << ans;
    return 0;
}