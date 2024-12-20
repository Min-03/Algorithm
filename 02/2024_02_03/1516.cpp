#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[501];
int inDegrees[501], dists[501], costs[501];

void topological(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            inDegrees[ngb]--;
            dists[ngb] = max(dists[ngb], dists[curr] + costs[ngb]);
            if (inDegrees[ngb] == 0) q.push(ngb);
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
        dists[i] = costs[i];
        while (true) {
            int j;
            cin >> j;
            if (j == -1) break;
            graph[j].push_back(i);
            inDegrees[i]++;
        }
    }
    topological(n);
    for (int i = 1; i <= n; i++) {
        cout << dists[i] << '\n';
    }
    return 0;
}