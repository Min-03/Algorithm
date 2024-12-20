#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    FastIO
    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible." << '\n';
            continue;
        }

        if (n & 1) {
            cout << 2 << ' ' << 3 << ' ';
            n -= 5;
        } else {
            cout << 2 << ' ' << 2 << ' ';
            n -= 4;
        }

        for (int i = 2; i < n; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << ' ' << n - i << '\n';
                break;
            }
        }
    }

    return 0;
}