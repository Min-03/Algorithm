#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    string numStr;
    cin >> numStr;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += numStr[i] - '0';
    }
    cout << ans;
    return 0;
}
