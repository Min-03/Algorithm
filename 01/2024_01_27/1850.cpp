#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    long long a, b;
    cin >> a >> b;
    for (long long i = 0; i < gcd(a, b); i++) {
        cout << 1;
    }
    return 0;
}