#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long n, k;

bool check(long long x) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min(n, x / i);
    }
    return cnt >= k;
}
int main() {
    FastIO
    cin >> n >> k;
    long long lo = 0, hi = n * n;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}