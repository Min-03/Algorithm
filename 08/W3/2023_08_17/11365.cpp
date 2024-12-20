#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input;
    while (true) {
        getline(cin, input);
        if (input == "END") return 0;
        stack<char> s;
        for (char ch : input) {
            s.push(ch);
        }
        while (!s.empty()) {
            cout << s.top(); s.pop();
        }
        cout << '\n';
    }
}