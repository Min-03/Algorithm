#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
int visited[3001]; //몇 번째 dfs에서 방문했는지 표시, bfs 단계에서는 bool처럼 사용
int before[3001];
bool cycle[3001];
int dist[3001];
int n, cnt = 1;
queue<int> q;

//순환이 존재하면 마지막 노드, 아니면 0 반환
int dfs(int curr, int pre) {
    visited[curr] = cnt;
    for (int ngb : graph[curr]) {
        if (visited[ngb] == 0) {
            before[ngb] = curr;
            int result = dfs(ngb, curr);
            if (result != 0) return result;
        } else if (ngb != pre && visited[ngb] == cnt){
            before[ngb] = curr;
            return curr;
        }
    }
    return 0;
}

void bfs() {
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                q.push(ngb);
                dist[ngb] = dist[curr] + 1;
                visited[ngb] = true;
            }
        }
    }
}

void updateCycle(int start) {
    int curr = start;
    while (before[curr] != start) {
        cycle[curr] = true;
        curr = before[curr];
    }
    cycle[curr] = true;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int result = dfs(i, 0);
            if (result != 0 && visited[result] != 0) {
                updateCycle(result);
            }
            cnt += 1;
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            q.push(i);
            dist[i] = 0;
            visited[i] = true;
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}