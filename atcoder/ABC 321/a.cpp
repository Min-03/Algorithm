#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] >= s[i - 1]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No");
    return 0;
}