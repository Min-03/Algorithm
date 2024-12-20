#include <bits/stdc++.h>
using namespace std;
int go(int left) {
    if (left < 0) {
        return 0;
    } else if (left == 0) {
        return 1;
    } else {
        return go(left - 1) + go(left - 2) + go(left - 3);
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = go(n);
        cout << cnt << '\n';
    }
    return 0;
}
