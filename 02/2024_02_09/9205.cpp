#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> pos;
vector<int> graph[102];
bool visited[102];
int n;

bool bfs() {
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == n + 1) return true;
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                visited[ngb] = true;
                q.push(ngb);
            }
        }
    }
    return false;
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        pos.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n + 2; i++) graph[i].clear();
        pos.resize(n + 2);
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            pos[i] = {x, y};
        }
        for (int i = 0; i < n + 2; i++) {
            auto [px, py] = pos[i];
            for (int j = i + 1; j < n + 2; j++) {
                auto [nx, ny] = pos[j];
                int dist = abs(nx - px) + abs(ny - py);
                if (dist > 1000) continue;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        cout << (bfs() ? "happy" : "sad") << '\n';
    }
    return 0;
}