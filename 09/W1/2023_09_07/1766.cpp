#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[32001];
int inDegrees[32001];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        inDegrees[e] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        cout << curr << ' ';
        for (int ngb : graph[curr]) {
            inDegrees[ngb] -= 1;
            if (inDegrees[ngb] == 0) pq.push(ngb);
        }
    }
    return 0;
}