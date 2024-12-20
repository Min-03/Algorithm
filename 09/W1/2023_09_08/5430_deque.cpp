#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        string p, str;
        int n;
        cin >> p >> n >> str;
        deque<int> dq;
        int curr = 0;
        for (char ch : str) {
            if (isdigit(ch)) {
                curr = curr * 10 + ch - '0';
            } else {
                if (curr != 0) dq.push_back(curr);
                curr = 0;
            }
        }

        bool reversed = false, error = false;
        for (char ch : p) {
            if (ch == 'R') {
                reversed ^= 1;
            } else {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reversed) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        cout << '[';
        while (!dq.empty()) {
            if (reversed) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            if (!dq.empty()) cout << ',';
        }
        cout << "]\n";
    }
    return 0;
}