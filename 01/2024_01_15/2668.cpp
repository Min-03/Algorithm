#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> res;
vector<int> graph[101];
int parent[101], type[101];


void updateRes(int curr, int start) {
    res.push_back(curr);
    if (curr == start) {
        return;
    }
    updateRes(parent[curr], start);
}

void dfs(int x, int color) {
    type[x] = color;
    for (int ngb : graph[x]) {
        if (type[ngb] == 0) {
            parent[ngb] = x;
            dfs(ngb, color);
        } else if (type[ngb] == color) {
            updateRes(x, ngb);
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        graph[i].push_back(j);
    }

    int color = 1;
    for (int i = 1; i <= n; i++) {
        if (type[i] == 0) dfs(i, color++);
    }

    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int num : res) {
        cout << num << '\n';
    }
    return 0;
}