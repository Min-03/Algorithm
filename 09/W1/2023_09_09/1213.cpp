#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[26];

int main() {
    FastIO
    string str;
    cin >> str;
    for (char ch : str) {
        cnts[ch - 'A']++;
    }

    char target = ' ';
    for (int i = 0; i < 26; i++) {
        if (cnts[i] & 1) {
            if (target == ' ') target = i + 'A';
            else {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << string(cnts[i] / 2, i + 'A');
    }
    if (target != ' ') cout << target;
    for (int i = 25; i >= 0; i--) {
        cout << string(cnts[i] / 2, i + 'A');
    }
    return 0;
}