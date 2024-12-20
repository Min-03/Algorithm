#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n), sums(n + 1);
    for (int &i : nums) cin >> i;
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= n; i++) sums[i] = sums[i - 1] + nums[i - 1];
    if (sums[1] != 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] > sums[i] + 1) {
            cout << sums[i] + 1;
            return 0;
        }
    }
    cout << sums[n] + 1;
    return 0;
}