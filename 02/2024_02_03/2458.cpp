#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[501];
int inVisit[501], outVisit[501];
bool visited[501];

void bfs(int s) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr != s) {
            outVisit[s]++;
            inVisit[curr]++;
        }
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                q.push(ngb);
                visited[ngb] = true;
            }
        }
    }
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (inVisit[i] + outVisit[i] == n - 1) ans++;
    }
    cout << ans;
    return 0;
}