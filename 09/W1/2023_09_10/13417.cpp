#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<char> dq;
        char ch;
        cin >> ch;
        dq.push_back(ch);
        for (int i = 1; i < n; i++) {
            cin >> ch;
            if (dq.front() >= ch) dq.push_front(ch);
            else dq.push_back(ch);
        }
        while (!dq.empty()) {
            cout << dq.front(); dq.pop_front();
        }
        cout << '\n';
    }
    return 0;
}