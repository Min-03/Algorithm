#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    if (m > (n / 2) * ((n + 1) / 2)) {
        cout << -1;
        return 0;
    }
    string ans;
    int cntA = 0;
    for (int i = (n + 1) / 2; i > 0; i--) {
        int iterNum = m / i;
        for (int j = 0; j < iterNum; j++) {
            ans += 'A';
            cntA += 1;
        }
        m = m % i;
        ans += 'B';
    }
    for (int i = cntA; i < n / 2; i++) {
        ans += 'A';
    }
    cout << ans;
    return 0;
}