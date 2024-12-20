#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

set<string> s;

int main() {
    FastIO
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string str;
        cin >> str;
        if (str == "ENTER") {
            s.clear();
        } else {
            if (s.find(str) == s.end()) ans++;
            s.insert(str);
        }
    }
    cout << ans;
    return 0;
}