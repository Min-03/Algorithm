#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

vector<ll> a, b, c, d, sumsA, sumsB;

int main() {
    FastIO
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    sumsA.reserve(n * n);
    sumsB.reserve(n * n);
    for (ll n1 : a) {
        for (ll n2 : b) {
            sumsA.push_back(n1 + n2);
        }
    }
    for (ll n1 : c) {
        for (ll n2 : d) {
            sumsB.push_back(n1 + n2);
        }
    }
    sort(sumsA.begin(), sumsA.end());
    sort(sumsB.begin(), sumsB.end());
    int lp = 0, rp = n * n - 1;
    ll ans = 0;
    while (lp < n * n && 0 <= rp) {
        ll sum = sumsA[lp] + sumsB[rp];
        if (sum == 0) {
            ll left = sumsA[lp], right = sumsB[rp];
            ll leftCnt = 0, rightCnt = 0;
            while (lp < n * n && sumsA[lp] == left) {
                leftCnt++;
                lp++;
            }
            while (0 <= rp && sumsB[rp] == right) {
                rightCnt++;
                rp--;
            }
            ans += leftCnt * rightCnt;
        } else if (sum > 0) {
            rp--;
        } else {
            lp++;
        }
    }
    cout << ans;
    return 0;
}