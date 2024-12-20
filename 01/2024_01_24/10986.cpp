#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long cnt[1'000];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<long long> nums(n), sums(n + 1);
    for (long long &i : nums) cin >> i;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = nums[i] + sums[i];
        cnt[sums[i + 1] % m]++;
    }
    long long ans = 0;
    for (int i = 0; i <= m; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans + cnt[0];
    return 0;
}