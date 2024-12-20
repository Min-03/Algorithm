#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input;
    cin >> input;
    string ans;
    ans += input[0];
    char before = input[0];
    for (char ch : input) {
        if (before == '-') ans += ch;
        before = ch;
    }
    cout << ans;
    return 0;
}