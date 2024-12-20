#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int costs[100'000], weights[100'000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    long long ans = 0;
    int lo = 1e9;
    for (int i = 0; i < n; i++) {
        lo = min(lo, costs[i]);
        if (i != n - 1) ans += (long long) lo * weights[i];
    }
    cout << ans;
    return 0;
}