#include <bits/stdc++.h>
using namespace std;

bool visited[10001];
pair<int, char> before[10001];

void printAns(int num, int start) {
    if (before[num].first == start) {
        cout << before[num].second;
        return;
    } else {
        printAns(before[num].first, start);
        cout << before[num].second;
    }
}

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == end) {
            printAns(end, start);
            cout << '\n';
            return;
        }
        int next;
        //L
        next = (x / 1000) + (x % 1000) * 10;
        if (!visited[next]) {
            visited[next] = true;
            before[next].first = x;
            before[next].second = 'L';
            q.push(next);
        }
        //R
        next = (x % 10) * 1000 + (x / 10);
        if (!visited[next]) {
            visited[next] = true;
            before[next].first = x;
            before[next].second = 'R';
            q.push(next);
        }
        //D
        next = (2 * x) % 10000;
        if (!visited[next]) {
            visited[next] = true;
            before[next].first = x;
            before[next].second = 'D';
            q.push(next);
        }
        //S
        next = (x == 0 ? 9999 : x - 1);
        if (!visited[next]) {
            visited[next] = true;
            before[next].first = x;
            before[next].second = 'S';
            q.push(next);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;
        for (int i = 0; i <= 10000; i++) {
            before[i].first = -1;
        }
        memset(visited, 0, sizeof(visited));
        bfs(start, end);
    }
    return 0;
}