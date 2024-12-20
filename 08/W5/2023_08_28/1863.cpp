#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    stack<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (s.empty() || s.top() < y) {
            s.push(y);
            continue;
        }

        while (!s.empty() && s.top() > y) {
            if (s.top() != 0) cnt++;
            s.pop();
        }
        if (s.empty() || s.top() != y) {
            s.push(y);
        }
    }
    while (!s.empty()) {
        if (s.top() != 0) cnt++;
        s.pop();
    }
    cout << cnt;
    return 0;
}