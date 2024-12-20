#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[201];
bool visited[201], can[201][201];

void bfs(int s) {
    memset(visited, 0, sizeof(visited));
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        can[s][curr] = true;
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                visited[ngb] = true;
                q.push(ngb);
            }
        }
    }
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool flag;
            cin >> flag;
            if (flag) graph[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    int curr, prev = -1;
    for (int i = 0; i < m; i++) {
        cin >> curr;
        if (prev != -1 && !can[prev][curr]) {
            cout << "NO";
            return 0;
        }
        prev = curr;
    }
    cout << "YES";
    return 0;
}