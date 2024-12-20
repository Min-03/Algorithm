#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[1025];
vector<int> numInDep[10];

void go(int l, int r, int dep) {
    if (l == r) {
        numInDep[dep].push_back(nums[l]);
        return;
    }
    int mid = (l + r) / 2;
    numInDep[dep].push_back(nums[mid]);
    go(l, mid - 1, dep + 1);
    go(mid + 1, r, dep + 1);
}

int main() {
    FastIO
    int k;
    cin >> k;
    for (int i = 0; i < (1 << k) - 1; i++) cin >> nums[i];
    go(0, (1 << k) - 2, 0);
    for (int i = 0; i < k; i++) {
        for (int num : numInDep[i]) cout << num << ' ';
        cout << '\n';
    }
    return 0;
}