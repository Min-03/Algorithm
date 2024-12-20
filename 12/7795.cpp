#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    FASTIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b.begin(), b.end());
        for (long long n : a) {
            ans += lower_bound(b.begin(), b.end(), n) - b.begin();
        }
        cout << ans << '\n';
    }
}