#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int val[10];

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k / val[i]) {
            cnt += k / val[i];
            k %= val[i];
        }
    }
    cout << cnt;
    return 0;
}