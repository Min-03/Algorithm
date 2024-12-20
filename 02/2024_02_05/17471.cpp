#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[11];
int cnts[11];
bool isA[11], visited[11];
int n, ans = 1e9;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (visited[ngb] || isA[curr] != isA[ngb]) continue;
            q.push(ngb);
            visited[ngb] = true;
        }
    }
}

void go(int curr, int chooseNum) {
    if (curr == n + 1) {
        if (chooseNum == 0 || chooseNum == n) return;
        memset(visited, 0, sizeof(visited));
        bool travelA = false, travelB = false;
        for (int i = 1; i <= n; i++) {
            if (isA[i] && !travelA) {
                travelA = true;
                bfs(i);
            } else if (!isA[i] && !travelB) {
                travelB = true;
                bfs(i);
            }
            if (!visited[i]) return;
        }
        int aSum = 0, bSum = 0;
        for (int i = 1; i <= n; i++) {
            if (isA[i]) aSum += cnts[i];
            else bSum += cnts[i];
        }
        ans = min(ans, abs(aSum - bSum));
        return;
    }
    isA[curr] = true;
    go(curr + 1, chooseNum + 1);
    isA[curr] = false;
    go(curr + 1, chooseNum);
}

int main() {
    FastIO
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cnts[i];
    for (int i = 1; i <= n; i++) {
        int iter;
        cin >> iter;
        for (int j = 0; j < iter; j++) {
            int e;
            cin >> e;
            graph[i].push_back(e);
        }
    }
    go(1, 0);
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}