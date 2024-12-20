#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int lo[3], hi[3], curr[3], prevLo[3], prevHi[3];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curr[0] >> curr[1] >> curr[2];
        lo[0] = curr[0] + min(prevLo[0], prevLo[1]);
        lo[1] = curr[1] + min({prevLo[0], prevLo[1], prevLo[2]});
        lo[2] = curr[2] + min(prevLo[2], prevLo[1]);

        hi[0] = curr[0] + max(prevHi[0], prevHi[1]);
        hi[1] = curr[1] + max({prevHi[0], prevHi[1], prevHi[2]});
        hi[2] = curr[2] + max(prevHi[2], prevHi[1]);

        for (int j = 0; j < 3; j++) {
            prevHi[j] = hi[j];
            prevLo[j] = lo[j];
        }
    }
    cout << max({hi[0], hi[1], hi[2]}) << ' ' << min({lo[0], lo[1], lo[2]});
    return 0;
}