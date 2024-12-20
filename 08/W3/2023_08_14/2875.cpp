#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m, k;
    cin >> n >> m >> k;
    int team = min(n / 2, m);
    k -= n + m - 3 * team;
    while (k > 0) {
        team--;
        k -= 3;
    }
    cout << team;
    return 0;
}