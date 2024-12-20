#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string s, ans;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '.') break;
        ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}