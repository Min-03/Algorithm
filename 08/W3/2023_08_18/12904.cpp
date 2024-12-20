#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool go(string &base, string &curr) {
    if (curr.length() == base.length()) {
        return curr == base;
    } else {
        if (curr.back() == 'B') {
            reverse(curr.begin(), curr.end() - 1);
            curr.pop_back();
            return go(base, curr);
        } else {
            curr.pop_back();
            return go(base, curr);
        }
    }
}

int main() {
    FastIO
    string s, t;
    cin >> s >> t;
    cout << (go(s, t) ? 1 : 0);
    return 0;
}