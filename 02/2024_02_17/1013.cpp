#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int tc;
    cin >> tc;
    regex re("(100+1+|01)+");
    while (tc--) {
        string str;
        cin >> str;
        cout << (regex_match(str, re) ? "YES" : "NO") << '\n';
    }
    return 0;
}