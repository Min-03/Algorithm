#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x--;
        y--;
        int limit = lcm(m, n);
        bool isFind = false;
        for (int i = x; i <= limit; i += m) {
            if (i % m == x && i % n == y) {
                cout << i + 1 << '\n';
                isFind = true;
                break;
            }
        }
        if (!isFind) {
            cout << -1 << '\n';
        }
    }
}