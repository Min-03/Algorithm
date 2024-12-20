#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[32'001];
int inDegrees[32'001];

void topological(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << ' ';
        for (int ngb : graph[curr]) {
            inDegrees[ngb]--;
            if (inDegrees[ngb] == 0) q.push(ngb);
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
        inDegrees[e]++;
    }
    topological(n);
    return 0;
}