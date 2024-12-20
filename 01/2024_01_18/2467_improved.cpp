#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int lVal, rVal, res = 2e9 + 1, lp = 0, rp = n - 1;
    while (lp < rp) {
        int sum = nums[lp] + nums[rp];
        if (abs(sum) < res) {
            lVal = nums[lp];
            rVal = nums[rp];
            res = abs(sum);
        }
        if (sum == 0) {
            break;
        } else if (sum > 0) {
            rp--;
        } else {
            lp++;
        }
    }
    cout << lVal << ' ' << rVal;
    return 0;
}