#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

vector<ll> squares;

int main() {
    FastIO
    squares.reserve(50'001);
    for (ll i = 1; i <= 50'000; i++) {
        squares.push_back(i * i);
    }
    int g;
    cin >> g;
    int lp = 0, rp = 0;
    bool ok = false;
    while (lp <= rp && rp < 50'000) {
        ll diff = squares[rp] - squares[lp];
        if (diff == g) {
            ok = true;
            cout << rp + 1 << '\n';
            lp++;
            rp++;
        } else if (diff < g) {
            rp++;
        } else {
            lp++;
        }
    }
    if (!ok) cout << -1;
    return 0;
}