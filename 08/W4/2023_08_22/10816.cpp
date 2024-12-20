#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[500'000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << upper_bound(nums, nums + n, num) - lower_bound(nums, nums + n, num) << ' ';
    }
    return 0;
}