#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int wants[1001];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> wants[i];
    }
    sort(wants + 1, wants + m + 1);

    int limit = min(n, m);
    int ans[2] = {0, 0}; // ans[0] : 책정 가격, ans[1] : 수익
    for (int i = m; i > m - limit; i--) {
        int curr = wants[i] * (m - i + 1);
        if (curr > ans[1]) {
            ans[1] = curr;
            ans[0] = wants[i];
        }
    }
    cout << ans[0] << ' ' << ans[1];
    return 0;
}