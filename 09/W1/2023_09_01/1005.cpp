#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[1001];
int times[1001], inDegrees[1001], total[1001];

int topological(int n, int target) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            inDegrees[ngb]--;
            total[ngb] = max(total[ngb], times[ngb] + total[curr]);
            if (inDegrees[ngb] == 0) {
                q.push(ngb);
            }
        }
    }
    return total[target];
}

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> times[i];
            total[i] = times[i];
        }
        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            inDegrees[v] += 1;
        }
        int w;
        cin >> w;
        cout << topological(n, w) << '\n';
        memset(inDegrees, 0, sizeof(inDegrees));
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
    }
    return 0;
}