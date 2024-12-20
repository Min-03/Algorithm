#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

bool isDivided[1'001'001], isBanned[1'000'001];
vector<ll> primes;

int main() {
    FastIO
    isDivided[0] = true;
    isDivided[1] = true;
    for (int i = 2; i * i <= 1'001'000; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j <= 1'001'000; j += i) {
            isDivided[j] = true;
        }
    }
    for (int i = 2; i <= 1'001'000; i++) {
        if (!isDivided[i]) primes.push_back(i);
    }
    ll s, e, ans = 0;
    cin >> s >> e;
    for (ll prime : primes) {
        ll square = prime * prime;
        ll st = (s / square) * square;
        if (st < s) st += square;
        for (ll i = st; i <= e; i += square) {
            if (!isBanned[i - s]) {
                isBanned[i - s] = true;
                ans++;
            }
        }
    }
    cout << e - s + 1 - ans;
    return 0;
}