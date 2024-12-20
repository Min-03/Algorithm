#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int limit = 200'000;

int dists[200'001];
int cnts[200'001];

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    memset(dists, -1, sizeof(dists));
    dists[n] = 0;
    cnts[n] = 1;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (0 <= next && next <= limit) {
                if (dists[next] == -1) {
                    q.push(next);
                    dists[next] = dists[curr] + 1;
                }
                if (dists[next] > dists[curr]) cnts[next] += cnts[curr];
            }
        }
    }
    cout << dists[k] << '\n' << cnts[k];
    return 0;
}