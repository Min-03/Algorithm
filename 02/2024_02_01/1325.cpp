#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> edges;
vector<int> graph[10'001];
int dp[10'001], parents[10'001], ranks[10'001], cnts[10'001], type[10'001], prevs[10'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (ranks[a] > ranks[b]) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
    cnts[b] += cnts[a];
}

int dfs(int x) {
    if (dp[x] != -1) return dp[x];
    dp[x] = cnts[x];
    for (int ngb : graph[x]) {
        dp[x] += dfs(ngb);
    }
    return dp[x];
}

void union_cycle(int curr, int st) {
    if (curr == st) return;
    union_set(curr, st);
    union_cycle(prevs[curr], st);
}
 
void get_cycle(int x) {
    type[x] = 1;
    for (int ngb : graph[x]) {
        if (type[ngb] == 0) {
            prevs[ngb] = x;
            get_cycle(ngb);
        } else if (type[ngb] == 1) {
            union_cycle(x, ngb);
        }
    }
    type[x] = 2;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    edges.reserve(m);
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
        cnts[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> e >> s;
        graph[s].push_back(e);
        edges.push_back({s, e});
    }
    for (int i = 1; i <= n; i++) {
        if (type[i] == 0) get_cycle(i);
    }
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (auto [s, e] : edges) {
        int ps = find_set(s);
        int pe = find_set(e);
        if (ps == pe) continue;
        graph[ps].push_back(pe);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }
    
    int hi = 0;
    vector<int> ans;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int res = dfs(find_set(i));
        if (res > hi) {
            hi = res;
            ans.clear();
            ans.push_back(i);
        } else if (res == hi) {
            ans.push_back(i);
        }
    }
    for (int i : ans) cout << i << ' ';
    return 0;
}