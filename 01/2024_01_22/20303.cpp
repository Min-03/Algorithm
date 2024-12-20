#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool visited[30'001];
int parent[30'001], ranks[30'001], cnt[30'001], candies[30'001], dp[3001];

int find_set(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranks[a] > ranks[b]) swap(a, b);
    parent[a] = b;
    ranks[b] += ranks[a] == ranks[b];
    candies[b] += candies[a];
    cnt[b] += cnt[a];
}

int main() {
    FastIO
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) cnt[i] = 1;
    for (int i = 1; i <= n; i++) cin >> candies[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }
    vector<int> vals, costs;
    for (int i = 1; i <= n; i++) {
        int p = find_set(i);
        if (!visited[p]) {
            visited[p] = true;
            vals.push_back(candies[p]);
            costs.push_back(cnt[p]);
        }
    }

    for (int i = 0; i < costs.size(); i++) {
        int cost = costs[i];
        int val = vals[i];
        for (int j = k; j >= cost; j--) dp[j] = max(dp[j], dp[j - cost] + val);
    }
    cout << dp[k - 1];
    return 0;
}