#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll n, m, k;

bool check(ll x) {
    ll num = x / n + x / m - 2 * (x / lcm(n, m));
    return num >= k;
}

int main() {
    FastIO
    cin >> n >> m >> k;
    ll lo = 0, hi = 1e18;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}