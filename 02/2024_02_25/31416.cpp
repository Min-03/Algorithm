#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int ta, tb, va, vb;
        cin >> ta >> tb >> va >> vb;
        int lo = 1e6;
        for (int i = 0; i <= va; i++) {
            lo = min(lo, max(ta * i + vb * tb, ta * (va - i)));
        }
        cout << lo << '\n';
    }
    return 0;
}