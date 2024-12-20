#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[20];

int main() {
    FastIO
    int s, k;
    cin >> s >> k;
    if (s == 0 || k == 0) {
        cout << 0;
        return 0;
    }
    int left = s % k;
    for (int i = 0; i < k; i++) {
        nums[i] = s / k;
        if (left > 0) nums[i]++;
        left--;
    }
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans *= nums[i];
    }
    cout << ans;
    return 0;
}