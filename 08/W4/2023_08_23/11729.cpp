#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int power(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) a *= ret;
        ret *= ret;
        b >>= 1;
    }
}

void go(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    go(n - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    go(n - 1, b, a, c);
}
int main() {
    FastIO
    int n;
    cin >> n;
    cout << power(2, n) - 1 << '\n';
    go(n, 1, 2, 3);
    return 0;
}