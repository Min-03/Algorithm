#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int go(int x, int y, int size) {
    if (size == 1) {
        return 0;
    }
    int ret = 0;
    if (x >= size / 2) {
        ret += 2 * (size / 2) * (size / 2);
        x -= size / 2;
    }
    if (y >= size / 2) {
        ret += (size / 2) * (size / 2);
        y -= size / 2;
    }
    
    return ret + go(x, y, size / 2);
}

int main() {
    FastIO
    int n, r, c;
    cin >> n >> r >> c;
    cout << go(r, c, (1 << n));
    return 0;
}