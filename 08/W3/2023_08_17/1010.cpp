#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

//base부터 n까지 곱합
long long fac(int n, int base) {
    if (n == base) {
        return base;
    }
    return n * fac(n - 1, base);
}

int main() {
    FastIO
    int t;
    cout << fac(30, 15);
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        cout << fac(m) << ' ' << fac(m - n) << endl;
//        cout << fac(m) / fac(m - n) << '\n';
//    }
    return 0;
}