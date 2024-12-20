#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int MAX = 1e9;

map<int, int> cnts;
map<int, pair<int, char>> before;
int s, t;

bool bfs() {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        long long x = q.front(); q.pop();
        if (x == t) {
            return true;
        }
        long long next = x * x;
        if (next <= MAX && (cnts.find(next) == cnts.end())) {
            cnts[next] = cnts[x] + 1;
            before[next] = {x, '*'};
            q.push(next);
        }

        next = 2 * x;
        if (next <= MAX && (cnts.find(next) == cnts.end())) {
            cnts[next] = cnts[x] + 1;
            before[next] = {x, '+'};
            q.push((int) next);
        }

        next = 1;
        if (next <= MAX && (cnts.find(next) == cnts.end() || cnts[next] > cnts[x] + 1)) {
            cnts[next] = cnts[x] + 1;
            before[next] = {x, '/'};
            q.push(next);
        }
    }
    return false;
}

void go(int curr) {
    if (before[curr].first == s) {
        cout << before[curr].second;
        return;
    } else {
        go(before[curr].first);
        cout << before[curr].second;
    }
}

int main() {
    FastIO
    cin >> s >> t;
    if (s == t) {
        cout << 0;
        return 0;
    } else if (t == 0) {
        cout << '-';
        return 0;
    }

    if (bfs()) {
        go(t);
    } else {
        cout << -1;
        return 0;
    }
    return 0;
}