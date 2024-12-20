#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[10000];
int dist[10000];

int changeDigit(string currStr, int to, int digit) {
    currStr[4 - digit] = to + '0';
    return stoi(currStr);
}

int bfs(int start, int end) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == end) {
            return dist[end];
        }
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j <= 9; j++) {
                int next = changeDigit(to_string(curr), j, i);
                if (next < 1000 || dist[next] != -1 || isDivided[next]) continue;
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    int t;
    cin >> t;
    isDivided[0] = isDivided[1] = true;
    for (int i = 2; i * i < 10000; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j < 10000; j += i) {
            isDivided[j] = true;
        }
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        memset(dist, -1, sizeof(dist));
        int res = bfs(a, b);
        if (res == -1) {
            cout << "Impossible\n";
        } else {
            cout << res << '\n';
        }
    }
    return 0;
}