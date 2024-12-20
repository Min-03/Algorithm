#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int a, b, d;
    cin >> a >> b >> d;
    for (int i = a; i <= b; i += d) {
        cout << i << ' ';
    }
    return 0;
}