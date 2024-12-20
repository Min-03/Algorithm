#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (long long &i : nums) cin >> i;
    sort(nums.begin(), nums.end());
    long long ans = 1e10, ansA, ansB, ansC;
    for (int i = 0; i < n; i++) {
        int lp = i + 1, rp = n - 1;
        while (lp < rp) {
            long long sum = nums[i] + nums[lp] + nums[rp];
            if (abs(sum) < ans) {
                ans = abs(sum);
                ansA = nums[i];
                ansB = nums[lp];
                ansC = nums[rp];
            }
            if (sum < 0) lp++;
            else rp--;
        }
    }
    cout << ansA << ' ' << ansB << ' ' << ansC;
    return 0;
}