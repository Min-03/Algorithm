#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<char, char> pairs;

int main() {
    FastIO
    string str;
    pairs['('] = ')';
    pairs['['] = ']';
    while (true) {
        getline(cin, str);
        if (str.length() == 1 && str[0] == '.') break;
        stack<char> s;
        bool ok = true;
        for (char ch : str) {
            if (ch == '(' || ch == '[') {
                s.push(ch);
            } else if (ch == ')' || ch == ']') {
                if (s.empty()) {
                    ok = false;
                    cout << "no\n";
                    break;
                }
                if (pairs[s.top()] != ch) {
                    ok = false;
                    cout << "no\n";
                    break;
                }
                s.pop();
            }
        }
        if (!ok) continue;
        cout << (s.empty() ? "yes\n" : "no\n");
    }
    return 0;
}