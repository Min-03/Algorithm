#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[50];
bool visited[50];

int dfs(int x) {
    visited[x] = true;
    int ret = 0;
    for (int ngb : graph[x]) {
        if (!visited[ngb]) {
            ret += dfs(ngb);
        }
    }
    return (ret == 0 ? 1 : ret);
}

int main() {
    FastIO
    int n, s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == -1) {
            s = i;
            continue;
        }
        graph[p].push_back(i);
    }
    int ban;
    cin >> ban;
    visited[ban] = true;
    cout << (s == ban ? 0 : dfs(s));
    return 0;
}