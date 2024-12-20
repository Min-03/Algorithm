#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> nums;
vector<int> ans;

int main() {
    FastIO
    int n, divisor = -1;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = abs(nums[i] - nums[j]);
            if (divisor != -1) divisor = gcd(divisor, diff);
            else divisor = diff;
        }
    }
    for (int i = 1; i * i <= divisor; i++) {
        if (divisor % i == 0) {
            ans.push_back(i);
            if (i * i != divisor) ans.push_back(divisor / i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}