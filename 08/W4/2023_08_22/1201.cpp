#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, k;

string getDummies(int num) {
    string ret;
    for (int i = num; i < min(n - k + 1, num + m - 1); i++) {
        ret += to_string(i);
        ret += ' ';
    }
    return ret;
}

int main() {
    FastIO
    cin >> n >> m >> k;
    if (n < m + k - 1 || n > m * k) {
        cout << -1;
        return 0;
    }
    string vital;
    for (int i = 1; i <= m - 1; i++) {
        vital += to_string(i);
        vital += ' ';
    }
    for (int i = n; i > n - k; i--) {
        vital += to_string(i);
        vital += ' ';
    }
    string dummy;
    stack<string> s;
    for (int i = m; i <= n - k; i += (m - 1)) {
        s.push(getDummies(i));
    }
    while (!s.empty()) {
        cout << s.top(); s.pop();
    }
    cout << (dummy + vital) << '\n';
    return 0;
}