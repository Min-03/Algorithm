#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int x, y;
    cin >> x >> y;
    if (x > 0) {
        if (y > 0) cout << 1;
        else cout << 4;
    } else {
        if (y > 0)  cout << 2;
        else cout << 3;
    }
    return 0;
}