#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100'001];
int before[100'001];

int bfs() {
    queue<int> q;
    visited[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == k) {
            return visited[k];
        }
        if (curr - 1 >= 0 && visited[curr - 1] == -1) {
            before[curr - 1] = curr;
            visited[curr - 1] = visited[curr] + 1;
            q.push(curr - 1);
        }
        if (curr + 1 <= 100'000 && visited[curr + 1] == -1) {
            before[curr + 1] = curr;
            visited[curr + 1] = visited[curr] + 1;
            q.push(curr + 1);
        }
        if (curr * 2 <= 100'000 && visited[curr * 2] == -1) {
            before[curr * 2] = curr;
            visited[curr * 2] = visited[curr] + 1;
            q.push(curr * 2);
        }
    }
    return -1;
}

void go(int curr) {
    if (curr == n) {
        cout << curr << ' ';
    } else {
        go(before[curr]);
        cout << curr << ' ';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    memset(visited, -1, sizeof(visited));
    cout << bfs() << '\n';
    go(k);
    return 0;
}