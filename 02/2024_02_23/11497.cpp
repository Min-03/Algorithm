#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &i : nums) cin >> i;
        sort(nums.begin(), nums.end());
        queue<int> left;
        stack<int> right;
        for (int i = 0; i < n; i++) {
            if (i & 1) right.push(nums[i]);
            else left.push(nums[i]);
        }
        int ans = 0, prev = -1;
        while (!left.empty()) {
            int diff = abs(left.front() - prev);
            if (prev != -1) ans = max(ans, diff);
            prev = left.front(); left.pop();
        }
        while (!right.empty()) {
            int diff = abs(right.top() - prev);
            ans = max(ans, diff);
            prev = right.top(); right.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}