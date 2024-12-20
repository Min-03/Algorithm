#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[100];
bool possible[100][100];
bool visited[100];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok;
            cin >> ok;
            if (ok) {
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        bfs(i);
        for (int j = 0; j < n; j++) {
            if (visited[j]) possible[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << possible[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}