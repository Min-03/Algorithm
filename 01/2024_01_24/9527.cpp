#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll getOnes(ll x) {
    ll step = 1;
    ll ret = 0;
    while ((1LL << (step - 1)) <= x) {
        ll unitSize = 1LL << step, minus = (1LL << (step - 1)) - 1;
        ll group = (x - minus) / unitSize, remainder = (x - minus) % unitSize;
        ret += group * unitSize / 2;
        ret += min(remainder, unitSize / 2);
        step++;
    }
    return ret;
}

int main() {
    FastIO
    ll a, b;
    cin >> a >> b;
    cout << getOnes(b) - getOnes(a - 1);
    return 0;
}