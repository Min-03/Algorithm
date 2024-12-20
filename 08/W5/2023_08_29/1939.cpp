#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> graph[100'001]; // 가중치, 다음 섬
bool visited[100'001];
int start, dest;

bool check(int x, int curr) {
    if (curr == dest) {
        return true;
    }
    visited[curr] = true;
    for (auto [w, next] : graph[curr]) {
        if (w >= x && !visited[next]) {
            if (check(x, next)) return true;
        }
    }
    return false;
}

int main() {
    FastIO
    int n, m, hi = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
        hi = max(hi, w);
    }
    cin >> start >> dest;

    hi++;
    int lo = 0;
    while (lo + 1 < hi) {
        memset(visited, 0, sizeof(visited));
        int mid = (lo + hi) / 2;
        if (check(mid, start)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}