#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> nums;
int n;

bool check(int idx) {
    int lp = 0, rp = n - 1;
    while (lp < rp) {
        int sum = nums[lp] + nums[rp];
        if (sum == nums[idx] && idx != lp && idx != rp) {
            return true;
        }
        if (sum == nums[idx] && nums[lp + 1] == nums[lp] && idx == lp) lp++;
        else if (sum < nums[idx]) lp++;
        else rp--;
    }
    return false;
}

int main() {
    FastIO
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}