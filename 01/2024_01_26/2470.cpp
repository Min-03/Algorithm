#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums) cin >> i;
    sort(nums.begin(), nums.end());
    int lp = 0, rp = n - 1, res = 2e9, a, b;
    while (lp < rp) {
        int sum = nums[lp] + nums[rp];
        if (abs(sum) < res) {
            res = abs(sum);
            a = nums[lp];
            b = nums[rp];
        }
        if (sum > 0) rp--;
        else lp++;
    }
    cout << a << ' ' << b;
    return 0;
}