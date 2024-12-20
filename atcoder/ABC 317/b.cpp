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
    sort(nums.begin(), nums.end());
    int before = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] != before + 1) {
            cout << nums[i] - 1;
            break;
        }
        before = nums[i];
    }
    return 0;
}