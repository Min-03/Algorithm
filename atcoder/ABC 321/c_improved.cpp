#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    vector<long long> targets;
    for (int set = 2; set < (1 << 10); set++) {
        long long target = 0;
        for (int i = 9; i >= 0; i--) {
            if (set >> i & 1) {
                target = target * 10 + i;
            }
        }
        targets.push_back(target);
    }
    sort(targets.begin(), targets.end());
    int k;
    cin >> k;
    cout << targets[k - 1];
    return 0;
}