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
        if (tb * vb >= ta * va) {
            cout << tb * vb << '\n';
            continue;
        }

        int ar = (tb * vb) % ta ;
        int aWorked = (ar == 0 ? (tb * vb) / ta : (tb * vb) / ta + 1);
        aWorked = min(aWorked, va);
        int aLeft = va - aWorked;
        if (aLeft == 0) cout << ta << ' ' << tb << '\n';
        int ans = max(tb * vb, aWorked * ta);
        if (ar) {
            aLeft--;
            ans += ar;
        }
        ans += (aLeft + 1) / 2 * ta;
        cout << ans << '\n';
    }
    return 0;
}