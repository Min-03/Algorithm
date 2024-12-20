#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    FASTIO
    int n, nxt = 1;
    cin >> n;
    queue<int> lines;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lines.push(num);
    }
    stack<int> s;
    while (!lines.empty() || !s.empty()) {
        if (!s.empty() && s.top() == nxt) {
            s.pop();
            nxt++;
            continue;
        }
        if (lines.empty()) {
            break;
        }
        if (lines.front() == nxt) {
            lines.pop();
            nxt++;
        } else {
            s.push(lines.front()); lines.pop();
        }
    }
    cout << (nxt == n + 1 ? "Nice" : "Sad");
    return 0;
}