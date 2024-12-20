#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FastIO
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    sort(costs.begin(), costs.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < n; i += d) {
        long long regular = 0;
        for (int j = i; j < min(n, i + d); j++) {
            regular += costs[j];
        }
        ans += min(regular, (long long) p);
    }
    cout << ans;
    return 0;
}