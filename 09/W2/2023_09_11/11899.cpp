#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string str;
    cin >> str;
    stack<char> s;
    int ans = 0;
    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else {
            if (s.empty()) ans++;
            else s.pop();
        }
    }
    ans += s.size();
    cout << ans;
    return 0;
}