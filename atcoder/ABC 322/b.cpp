#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool checkPrefix(string &s, string& t) {
    int sPos = 0, tPos = 0;
    while (sPos < s.length() && tPos < t.length()) {
        if (s[sPos] != t[tPos]) return false;
        sPos++, tPos++;
    }
    return true;
}

bool checkSuffix(string &s, string& t) {
    int sPos = s.length() - 1, tPos = t.length() - 1;
    while (sPos >= 0 && tPos >= 0) {
        if (s[sPos] != t[tPos]) return false;
        sPos--, tPos--;
    }
    return true;
}

int main() {
    FastIO
    string s, t;
    int n, m;
    cin >> n >> m >> s >> t;
    if (checkPrefix(s, t)) {
        cout << (checkSuffix(s, t) ? 0 : 1);
    } else {
        cout << (checkSuffix(s, t) ? 2 : 3);
    }
    return 0;
}