#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << str[0] << str.back() << '\n';
    }
    return 0;
}