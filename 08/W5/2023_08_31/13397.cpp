#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> nums;
int n, m;

bool check(int x) {
    int cnt = 1, lo = nums[0], hi = nums[0];
    for (int num : nums) {
        if (hi - x <= num && num <= lo + x) {
            lo = min(lo, num);
            hi = max(hi, num);
        } else {
            lo = hi = num;
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {
    FastIO
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int lo = -1, hi = 10000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}