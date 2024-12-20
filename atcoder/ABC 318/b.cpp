#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool covered[101][101];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= b - 1; i++) {
            for (int j = c; j <= d - 1; j++) covered[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (covered[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}