#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[100'001];
int type[100'001];
int parent[100'001];
int inCycle = 0;

void updateNum(int curr, int start) {
    inCycle++;
    if (curr == start) return;
    updateNum(parent[curr], start);
}

void dfs(int x, int color) {
    type[x] = color;
    for (int ngb : graph[x]) {
        if (type[ngb] == 0) {
            parent[ngb] = x;
            dfs(ngb, color);
        } else if (type[ngb] == color) {
            updateNum(x, ngb);
        }
    }
}

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int j;
            cin >> j;
            graph[i].clear();
            graph[i].push_back(j);
        }
        memset(type, 0, sizeof(type));
        memset(parent, 0, sizeof(parent));
        inCycle = 0;
        int color = 1;
        for (int i = 1; i <= n; i++) {
            if (type[i] == 0) {
                dfs(i, color++);
            }
        }
        cout << n - inCycle << '\n';
    }
    return 0;
}