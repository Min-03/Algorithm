#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[300'001];
int orders[300'001];

void dfs(int x, int order) {
    orders[x] = order;
    cout << x << ' ';
    for (int ngb : graph[x]) {
        if (orders[ngb] == 0) {
            dfs(ngb, ++order);
        }
    }
}

int main() {
    FastIO
    int n, start;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int prev;
        cin >> prev;
        if (prev == -1) start = i;
        else graph[prev].push_back(i);
    }
    dfs(start, 1);

    return 0;
}