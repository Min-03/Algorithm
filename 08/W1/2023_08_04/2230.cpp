#include <bits/stdc++.h>
using namespace std;

int nums[100'000];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int lp = 0;
    int rp = 0;
    int ans = -1;
    sort(nums, nums + n);
    while (lp <= rp && rp < n) {
        int diff = abs(nums[rp] - nums[lp]);
        if (diff == m) {
            cout << m;
            return 0;
        } else if (diff > m) {
            if (ans == -1) ans = diff;
            else ans = min(ans, diff);
            lp += 1;
        } else {
            rp += 1;
        }
    }
    cout << ans;
    return 0;
}