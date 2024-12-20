#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dists[1'000'001];

int main() {
    FastIO
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    memset(dists, -1, sizeof(dists));
    dists[s] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == g) {
            cout << dists[g];
            return 0;
        }
        if (curr + u <= f && dists[curr + u] == -1) {
            dists[curr + u] = dists[curr] + 1;
            q.push(curr + u);
        }
        if (curr - d >= 1 && dists[curr - d] == -1) {
            dists[curr - d] = dists[curr] + 1;
            q.push(curr - d);
        }
    }
    cout << "use the stairs";
    return 0;
}