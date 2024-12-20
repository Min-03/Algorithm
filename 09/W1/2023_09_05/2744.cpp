#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string str;
    cin >> str;
    for (char ch : str) {
        if (islower(ch)) {
            cout << (char) toupper(ch);
        } else {
            cout << (char) tolower(ch);
        }
    }
    return 0;
}