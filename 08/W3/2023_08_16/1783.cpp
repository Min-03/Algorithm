#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << 1;
    } else if (n == 2) {
        cout << min(4, (int) ceil((double) m / 2));
    } else {
        if (m <= 5) {
            cout << min(4, m);
        } else {
            cout << m - 2;
        }
    }
    return 0;
}