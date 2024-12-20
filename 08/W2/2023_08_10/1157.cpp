#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[26];

int main() {
    FastIO
    string str;
    cin >> str;
    for (char ch : str) {
        if (islower(ch)) {
            cnts[ch - 'a'] += 1;
        } else {
            cnts[ch - 'A'] += 1;
        }
    }
    bool ok = true;
    int hi = 0;
    char maxAlpha = ' ';
    for (int i = 0; i < 26; i++) {
        if (cnts[i] > hi) {
            hi = cnts[i];
            maxAlpha = i + 'A';
            ok = true;
        } else if (cnts[i] == hi) {
            ok = false;
        }
    }
    if (ok) {
        cout << maxAlpha;
    } else {
        cout << '?';
    }
    return 0;
}