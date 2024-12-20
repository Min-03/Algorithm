#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int limit = 100'000;
const int mod = (int) 1e9 + 7;

int main() {
    FastIO
    for (int i = -mod; i <= mod + 1; i++) {
        if (i % mod != -(-i % mod)) {
            cout << i << '\n';
        }
    }
    return 0;
}