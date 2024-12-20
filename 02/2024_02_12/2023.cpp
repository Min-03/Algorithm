#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void go(int num, int len) {
    if (len == n) {
        cout << num << '\n';
        return;
    }
    for (int i : {1, 3, 7, 9}) {
        int nxt = num * 10 + i;
        if (isPrime(nxt)) {
            go(nxt, len + 1);
        }
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i : {2, 3, 5, 7}) {
        go(i, 1);
    }
    return 0;
}