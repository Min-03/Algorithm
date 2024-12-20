#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0) break;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        cout << (a * a + b * b == c * c ? "right\n" : "wrong\n");
    }
    return 0;
}