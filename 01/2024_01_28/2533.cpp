#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[1'000'001];
int degree[1'000'001];
bool early[1'000'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (early[curr]) continue;
        for (int ngb : graph[curr]) {
            if (!early[ngb]) {
                early[ngb] = true;
                ans++;
                for (int ngb2 : graph[ngb]) {
                    if (--degree[ngb2] == 1) q.push(ngb2);
                }
            }
        }
    }
    cout << ans;
    return 0;
}