#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[3'000'001];
int before[3'000'001];

int bfs(int n) {
    memset(cnts, -1, sizeof(cnts));
    cnts[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == 1) {
            return cnts[1];
        }
        if (curr % 3 == 0 && cnts[curr / 3] == -1) {
            before[curr / 3] = curr;
            cnts[curr / 3] = cnts[curr] + 1;
            q.push(curr / 3);
        }
        if (curr % 2 == 0 && cnts[curr / 2] == -1) {
            before[curr / 2] = curr;
            cnts[curr / 2] = cnts[curr] + 1;
            q.push(curr / 2);
        }
        if (cnts[curr - 1] == -1) {
            before[curr - 1] = curr;
            cnts[curr - 1] = cnts[curr] + 1;
            q.push(curr - 1);
        }
    }
    return -1;
}

int main() {
    FastIO
    int n;
    cin >> n;
    int ans = bfs(n);
    int curr = 1;
    stack<int> s;
    while (curr != n) {
        s.push(curr);
        curr = before[curr];
    }
    cout << ans << '\n';
    cout << n << ' ';
    while (!s.empty()) {
        cout << s.top() << ' '; s.pop();
    }
    return 0;
}