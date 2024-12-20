#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] != '0') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}