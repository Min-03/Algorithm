#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int limit = 200'000;

long long a[limit + 1], b[limit + 1];
long long aSum[limit + 1], bSum[limit + 1];

int main() {
    FastIO
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++) {
        aSum[i] = aSum[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        bSum[i] = bSum[i - 1] + b[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + b[1] >= p) {
            ans += (long long) m * p;
            continue;
        }
        auto it = lower_bound(b + 1, b + m + 1, p - a[i]);
        int pos = it - (b + 1);
        ans += a[i] * pos + bSum[pos] + (long long) (m - pos) * p;
    }
    cout << ans;
    return 0;
}