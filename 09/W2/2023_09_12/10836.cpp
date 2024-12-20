#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int lengths[2000];
int m, n;

int main() {
    FastIO
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int zero, one, two;
        cin >> zero >> one >> two;
        if (zero < 2 * m - 1) lengths[zero] += 1;
        if (zero + one < 2 * m - 1) lengths[zero + one] += 1;
    }

    for (int i = 1; i < 2 * m - 1; i++) {
        lengths[i] += lengths[i - 1];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) cout << lengths[m - 1 - i] + 1 << ' ';
            else cout << lengths[m - 1 + j] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}