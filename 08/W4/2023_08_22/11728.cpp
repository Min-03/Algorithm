#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[2'000'000];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n + m);
    for (int i = 0; i < n + m; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}