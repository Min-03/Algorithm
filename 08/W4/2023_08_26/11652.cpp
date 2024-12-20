#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int hi = 1, cnt = 1;
    long long ans = nums[0], before = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] == before) cnt++;
        else {
            cnt = 1;
            before = nums[i];
        }
        if (cnt > hi) {
            hi = cnt;
            ans = nums[i];
        }
    }
    cout << ans;
    return 0;
}