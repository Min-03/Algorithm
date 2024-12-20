#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    if (a1 > c) {
        cout << 0;
    } else {
        cout << ((a1 * n0 + a0) <= c * n0 ? 1 : 0);
    }
    return 0;
}