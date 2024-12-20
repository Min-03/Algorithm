#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min({x, y, w - x, h - y});
    return 0;
}