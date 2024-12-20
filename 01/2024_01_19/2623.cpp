#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[1'001];
int inDegrees[1'001];
vector<int> orders;

void topological(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        orders.push_back(curr);
        for (int ngb : graph[curr]) {
            if (--inDegrees[ngb] == 0) q.push(ngb);
        }
    }
    if (orders.size() != n) {
        cout << "0";
        return;
    }

    for (int order : orders) {
        cout << order << '\n';
    }
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num, prev;
        cin >> num >> prev;
        for (int j = 0; j < num - 1; j++) {
            int curr;
            cin >> curr;
            graph[prev].push_back(curr);
            inDegrees[curr]++;
            prev = curr;
        }
    }
    topological(n);
    return 0;
}