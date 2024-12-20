#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m, p, curr, cnt = 1;
    cin >> n >> m >> p;
    if (n < m) {
        cout << 0;
        return 0;
    }
    curr = 1;
    while (curr <= n - m) {
        if (curr % p == 0) {
            cnt++;
        }
        curr++;
    }
    cout << cnt;
    return 0;
}