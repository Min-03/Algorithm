#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long power(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int a, b;
    cin >> a >> b;
    cout << power(a, b) + power(b, a);
    return 0;
}