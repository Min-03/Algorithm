#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input, pat;
    cin >> input;
    cin >> pat;
    stack<char> s;
    for (char ch : input) {
        s.push(ch);
        //pat이 s에 있는지 확인, 있으면 제거, 없으면 원래대로
        if (s.size() >= pat.length()) {
            stack<char> temp;
            bool ok = false;
            for (int i = pat.length() - 1; i >= 0; i--) {
                char topCh = s.top(); s.pop();
                temp.push(topCh);
                if (topCh != pat[i]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                while (!temp.empty()) {
                    s.push(temp.top()); temp.pop();
                }
            }
        }
    }

    if (s.empty()) {
        cout << "FRULA";
        return 0;
    }
    string ans;
    while (!s.empty()) {
        ans += s.top(); s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}