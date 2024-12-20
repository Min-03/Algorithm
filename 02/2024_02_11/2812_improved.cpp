#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

stack<int> s;
int n, k;

int main() {
    FastIO
    string str;
    int cnt = 0;
    cin >> n >> k >> str;
    for (char ch : str) {
        int num = ch - '0';
        while (cnt < k && !s.empty() && s.top() < num) {
            s.pop();
            cnt++;
        }
        s.push(num);
    }
    string ans = "";
    while (!s.empty()) {
        char ch = s.top() + '0'; s.pop();
        ans += ch;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n - k; i++) cout << ans[i];
    return 0;
}