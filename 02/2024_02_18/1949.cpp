#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[10'001];
bool visited[10'001];
int people[10'001];

pair<int, int> dfs(int curr) {
    visited[curr] = true;
    int ret0 = 0, ret1 = people[curr];
    for (int nxt : graph[curr]) {
        if (visited[nxt]) continue;
        auto [cnt0, cnt1] = dfs(nxt);
        ret0 += max(cnt0, cnt1);
        ret1 += cnt0;
    }
    return {ret0, ret1};
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> people[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto [ans0, ans1] = dfs(1);
    cout << max(ans0, ans1);
    return 0;
}