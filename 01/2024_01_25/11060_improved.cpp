#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int a[1000], dist[1000];
int n;

int bfs() {
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int i = 1; i <= a[curr]; i++) {
            int next = curr + i;
            if (next >= n || dist[next] != -1) continue;
            q.push(next);
            dist[next] = dist[curr] + 1;
        }
    }
    return dist[n - 1];
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dist, -1, sizeof(dist));
    cout << bfs();
    return 0;
}