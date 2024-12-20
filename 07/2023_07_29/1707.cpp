#include <bits/stdc++.h>
using namespace std;
vector<int> graph[20'001];
int color[20'001];
bool dfs(int curr, int preColor) {
    color[curr] = 3 - preColor;
    for (int ngb : graph[curr]) {
        if (color[ngb] == 0) {
            if (!dfs(ngb, 3 - preColor)) return false;
        } else {
            if (color[curr] == color[ngb]) return false;
        }
    }
    return true;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, v, e;
    cin >> k;
    while (k--) {
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool isBipartite = true;
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0 && !dfs(i, 2)) {
                isBipartite = false;
                break;
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
        //graph, color 초기화
        for (int i = 1; i <= v; i++) {
            graph[i].clear();
        }
        memset(color, 0, sizeof(color));
    }
    return 0;
}