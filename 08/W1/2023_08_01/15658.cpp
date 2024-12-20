#include <bits/stdc++.h>
using namespace std;

int cnts[4];
int nums[11];
int n, lo = 1e9, hi = -1e9;

void go(int index, int val) {
    if (index == n) {
        lo = min(lo, val);
        hi = max(hi, val);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (cnts[i] <= 0) continue;
        cnts[i] -= 1;
        if (i == 0) {
            go(index + 1, val + nums[index]);
        } else if (i == 1) {
            go(index + 1, val - nums[index]);
        } else if (i == 2) {
            go(index + 1, val * nums[index]);
        } else {
            go(index + 1, val / nums[index]);
        }
        cnts[i] += 1;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> cnts[i];
    }
    go(1, nums[0]);
    cout << hi << '\n' << lo;
    return 0;
}

