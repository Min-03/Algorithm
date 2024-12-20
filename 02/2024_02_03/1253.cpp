#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<int, bool> canMake;
map<int, int> cnts;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums) {
        cin >> i;
        cnts[i]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if ((nums[i] == 0 || nums[j] == 0) && cnts[sum] <= 1) continue;
            if (nums[i] == 0 && nums[j] == 0 && cnts[0] <= 2) continue;
            canMake[sum] = true;
        }
    }
    int ans = 0;
    for (int i : nums) {
        if (canMake[i]) ans++;
    }
    cout << ans;
    return 0;
}