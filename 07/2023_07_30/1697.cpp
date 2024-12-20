#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[100'001];
bool visited[100'001];

int bfs() {
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    visited[n] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == k) {
            return dist[k];
        }
        if (curr * 2 <= 100'000 && !visited[curr * 2]) {
            q.push(curr * 2);
            dist[curr * 2] = dist[curr] + 1;
            visited[curr * 2] = true;
        }
        if (curr + 1 <= 100'000 && !visited[curr + 1]) {
            q.push(curr + 1);
            dist[curr + 1] = dist[curr] + 1;
            visited[curr + 1] = true;
        }
        if (curr - 1 >= 0 && !visited[curr - 1]) {
            q.push(curr - 1);
            dist[curr - 1] = dist[curr] + 1;
            visited[curr -1] = true;
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    if (k <= n) {
        cout << n - k;
        return 0;
    }
    cout << bfs();
    return 0;
}