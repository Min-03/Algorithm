#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int q;
    cin >> q;
    vector<int> nums;
    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            nums.push_back(x);
        } else {
            cout << nums[nums.size() - x] << '\n';
        }
    }
    return 0;
}