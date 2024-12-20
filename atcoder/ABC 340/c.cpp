#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

map<ll, ll> costs;

ll getCost(ll x) {
    if (x < 2) return 0;
    if (costs.find(x) != costs.end()) return costs[x];
    return costs[x] = x + getCost(x / 2) + getCost((x + 1) / 2);
}

int main() {
    FastIO
    ll n;
    cin >> n;
    cout << getCost(n);
    return 0;
}