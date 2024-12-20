#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[1'000'001];

int main() {
    FastIO
    int m, n;
    cin >> m >> n;
    isDivided[0] = isDivided[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            isDivided[j] = true;
        }
    }
    for (int i = m; i <= n; i++) {
        if (!isDivided[i]) cout << i << '\n';
    }
    return 0;
}