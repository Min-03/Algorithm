#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<long long> nums;

bool check(long long x) {
    for (long long num : nums) {
        int cnt = upper_bound(nums.begin(), nums.end(), x - num) - lower_bound(nums.begin(), nums.end(), - x - num);
        if (cnt > 1) {
            return true;
        } else if (cnt == 1 && !(-x <= 2 * num && 2 * num <= x)) {
            return true;
        }
    }
    return false;
}

void printAns(long long x) {
    for (long long num : nums) {
        int cnt = upper_bound(nums.begin(), nums.end(), x - num) - lower_bound(nums.begin(), nums.end(), - x - num);
        if (cnt >= 1) {
            auto it = lower_bound(nums.begin(), nums.end(), - x - num);
            long long num2 = *it;
            if (num == num2) num2 = *(it + 1);
            cout << min(num, num2) << ' ' << max(num, num2);
            return;
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    long long lo = - 1;
    long long hi = abs(nums[nums.size() - 1] + nums[nums.size() - 2]) + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    printAns(hi);
    return 0;
}