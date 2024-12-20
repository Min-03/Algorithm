#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const ll mod = 998'244'353;

int main() {
    FastIO
    ll w, h, k, t, ans = 1;
    cin >> w >> h >> k >> t;
    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> y >> x;
        x--;
        y--;
        assert(0 <= x && x < h);
        assert(0 <= y && y < w);
        ll left = max(y - t, 0LL);
        ll right = min(y + t, w - 1);
        ll up = max(x - t, 0LL);
        ll down = min(x + t, h - 1);
        ll size = (right - left + 1) * (down - up + 1);
        ans = (ans * size % mod) % mod;
    }
    cout << ans;
    return 0;
}