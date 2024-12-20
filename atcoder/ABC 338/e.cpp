#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool used[400'001];

int main() {
    FastIO
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    edges.reserve(n);
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        if (e == s + 1 || (s == 1 && e == 2 * n)) {
            used[s] = true;
            used[e] = true;
        }
        edges.push_back({min(s, e), max(s, e)});
    }
    sort(edges.begin(), edges.end());
    deque<int> dq;
    for (int i = 1; i <= 2 * n; i++) {
        dq.push_back(i);
    }
    for (auto [s, e] : edges) {
        if (s != dq.front()) {
            cout << "Yes";
            return 0;
        }
        dq.pop_front();
        if (e == dq.front()) {
            dq.pop_front();
        } else if (e == dq.back()) {
            dq.pop_back();
        } else {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}