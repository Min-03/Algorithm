#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void hanoi(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    hanoi(n - 1, b, a, c);
}

string getDouble(string s) {
    int carry = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        int num = s[i] - '0';
        int nxt = 2 * num + carry;
        carry = 0;
        if (nxt >= 10) {
            carry++;
            nxt = nxt - 10;
        }
        s[i] = nxt + '0';
    }
    if (carry != 0) s = '1' + s;
    return s;
}

int main() {
    FastIO
    int n;
    cin >> n;
    string s = "1";
    for (int i = 0; i < n; i++) {
        s = getDouble(s);
    }
    for (int i = 0; i < s.length(); i++) {
        if (i != s.length() - 1) cout << s[i];
        else cout << (char) ((int) s[i] - 1) << '\n';
    }
    if (n <= 20) hanoi(n, 1, 2, 3);
    return 0;
}