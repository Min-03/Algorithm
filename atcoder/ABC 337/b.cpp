#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    bool a = true, b = true;
    string str;
    cin >> str;
    for (char ch : str) {
        if (ch == 'A') {
            if (!a) {
                cout << "No";
                return 0;
            }
        } else if (ch == 'B') {
            a = false;
            if (!b) {
                cout << "No";
                return 0;
            }
        } else {
            b = false;
        }
    }
    cout << "Yes";
    return 0;
}