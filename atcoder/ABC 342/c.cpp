#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char to[26];

void change(char prev, char nxt) {
    for (int i = 0; i < 26; i++) {
        if (to[i] == prev) to[i] = nxt;
    }
}

int main() {
    FastIO
    for (int i = 0; i < 26; i++) to[i] = i + 'a';
    int n, q;
    string str;
    cin >> n >> str >> q;
    while (q--) {
        char c, d;
        cin >> c >> d;
        change(c, d);
    }
    for (char ch : str) {
        cout << to[ch - 'a'];
    }
    return 0;
}