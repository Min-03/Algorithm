#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[26];

int main() {
    FastIO
    string s;
    cin >> s;
    for (char ch : s) {
        cnts[ch - 'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (cnts[s[i] - 'a'] == 1) {
            cout << i + 1;
        }
    }
    return 0;
}