#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int choose(int a, int b) {
    int ret = 1;
    for (int i = b + 1; i <= a; i++) {
        ret *= i;
        ret /= (i - b);
    }
    return ret;
}

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << choose(m, n) << '\n';
    }
    return 0;
}