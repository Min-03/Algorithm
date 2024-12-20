#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll num[6];

ll getTwo() {
    ll ret = 100;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue;
            ret = min(ret, num[i] + num[j]);
        }
    }
    return ret;
}

ll getThree() {
    ll ret = 150;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (i + j == 5 || j + k == 5 || i + k == 5) continue;
                ret = min(ret, num[i] + num[j] + num[k]);
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    ll n, lo = 50, hi = 0;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> num[i];
        lo = min(num[i], lo);
        hi = max(num[i], hi);
    }
    if (n == 1) {
        cout << accumulate(num, num + 6, 0) - hi;
        return 0;
    }
    cout << (n - 2) * (5 * n - 6) * lo + 4 * (2 * n - 3) * getTwo() + 4 * getThree();
    return 0;
}