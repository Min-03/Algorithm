#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int imos[500'001];

int main() {
    FastIO
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        if (i & 1) { //종유석
            imos[h - size + 1] += 1;
        } else { //석순
            imos[1] += 1;
            imos[size + 1] -= 1;
        }
    }

    int now = 0;
    for (int i = 1; i <= h; i++) {
        imos[i] += now;
        now = imos[i];
    }

    int lo = n;
    int num = 1;
    for (int i = 1; i <= h; i++) {
        if (lo > imos[i]) {
            lo = imos[i];
            num = 1;
        } else if (lo == imos[i]) {
            num += 1;
        }
    }
    cout << lo << ' ' << num;
    return 0;
}