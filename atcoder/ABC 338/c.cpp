#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, cntA = 0, hi = 0;
    cin >> n;
    vector<int> q(n), a(n), b(n), left(n);
    for (int &i : q) cin >> i;
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    bool ok = true;
    while (true) {
        for (int i = 0; i < n; i++) {
            left[i] = q[i] - cntA * a[i];
            if (left[i] < 0) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
        int cntB = 1e6;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) continue;
            cntB = min(cntB, left[i] / b[i]);
        }
        hi = max(hi, cntA + cntB);
        cntA++;
    }
    cout << hi;
    return 0;
}