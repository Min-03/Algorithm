#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100'001];

int bfs() {
    deque<int> dq;
    dq.push_back(n);
    visited[n] = 0;
    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();
        if (curr == k) {
            return visited[curr];
        }
        if (curr * 2 <= 100'000 && visited[curr * 2] > visited[curr]) {
            dq.push_front(curr * 2);
            visited[curr * 2] = visited[curr];
        }
        if (curr - 1 >= 0 && visited[curr - 1] > visited[curr] + 1) {
            dq.push_back(curr - 1);
            visited[curr - 1] = visited[curr] + 1;
        }
        if (curr + 1 <= 100'000 && visited[curr + 1] > visited[curr] + 1) {
            dq.push_back(curr + 1);
            visited[curr + 1] = visited[curr] + 1;
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    fill(visited, visited + 100'001, 1'000'000);
    cout << bfs();
    return 0;
}