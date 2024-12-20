#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int costs[1'000'000];

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> costs[i];
        }

        int hi = -1;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            hi = max(hi, costs[i]);
            ans += hi - costs[i];
        }
        cout << ans << '\n';
    }
    return 0;
}