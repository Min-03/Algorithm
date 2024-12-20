#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<string, string> passwords;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    while (n--) {
        string site, pw;
        cin >> site >> pw;
        passwords.insert({site, pw});
    }
    while (m--) {
        string site;
        cin >> site;
        cout << passwords[site] << '\n';
    }
    return 0;
}