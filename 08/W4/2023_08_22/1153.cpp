#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[1'000'001];

int main() {
    FastIO
    int n;
    cin >> n;
    if (n < 8) {
        cout << -1;
        return 0;
    }
    isDivided[0] = isDivided[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isDivided[i]) continue;
        for (int j = i * i; j <= n; j += i) isDivided[j] = true;
    }

    if (n & 1) {
        cout << 2 << ' ' << 3 << ' ';
        n -= 5;
    } else {
        cout << 2 << ' ' << 2 << ' ';
        n -= 4;
    }

    for (int i = 2; i < n; i++) {
        if (!isDivided[i] && !isDivided[n - i]) {
            cout << i << ' ' << n - i;
            break;
        }
    }
    return 0;
}