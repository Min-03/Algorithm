#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnt[26];

int main() {
    FastIO
    string str;
    cin >> str;
    for (char ch : str) {
        cnt[ch - 'a']++;
    }

    int hi = 0;
    char ans;
    for (int i = 0; i <= 26; i++) {
        if (cnt[i] > hi) {
            hi = cnt[i];
            ans = i + 'a';
        }
    }
    cout << ans;
    return 0;
}