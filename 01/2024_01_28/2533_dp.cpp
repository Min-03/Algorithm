#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool visited[2'000'001];
vector<int> graph[2'000'001];

pair<int, int> dfs(int x) {
    visited[x] = true;
    int ret[] = {0, 0};
    ret[1] = 1;
    for (int ngb : graph[x]) {
        if (visited[ngb]) continue;
        auto [cnt1, cnt2] = dfs(ngb);
        ret[0] += cnt2;
        ret[1] += min(cnt1, cnt2);
    }
    return {ret[0], ret[1]};
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto [ans1, ans2] = dfs(1);
    cout << min(ans1, ans2);
    return 0;
}