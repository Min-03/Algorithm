#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

set<string> strs, dance;

int main() {
    FastIO
    int n;
    cin >> n;
    dance.insert("ChongChong");
    while (n--) {
        string a, b;
        cin >> a >> b;
        strs.insert(a);
        strs.insert(b);
        if (dance.find(a) != dance.end() || dance.find(b) != dance.end()) {
            dance.insert(a);
            dance.insert(b);
        }
    }
    int ans = 0;
    for (const string &str : strs) {
        if (dance.find(str) != dance.end()) ans++;
    }
    cout << ans;
    return 0;
}