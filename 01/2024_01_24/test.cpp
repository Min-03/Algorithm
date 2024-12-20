#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), sums(n + 1);
    for (int &i : nums) cin >> i;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = nums[i] + sums[i];
    }

    int lp = 0, rp = 0, cnt = 0;
    while (lp <= rp && rp <= n) {
        int sum = sums[rp] - sums[lp];
        if (sum == m) {
            cnt++;
            lp++;
            rp++;
        } else if (sum < m) {
            rp++;
        } else {
            lp++;
        }
    }
    cout << cnt;
    return 0;
}