#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int &i : nums) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum <= m) ans = max(ans, sum);
            }
        }
    }
    cout << ans;
    return 0;
}