#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int costs[10'001], parents[10'001];
bool isFriend[10'001];

int find(int a) {
    if (a == parents[a]) {
        return a;
    } else {
        return parents[a] = find(parents[a]);
    }
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (costs[a] > costs[b]) swap(a, b);
    parents[b] = a;
}

int main() {
    FastIO
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!isFriend[find(i)]) {
            isFriend[find(i)] = true;
            res += costs[find(i)];
        }
    }
    cout << (res > k ? "Oh no" : to_string(res));
    return 0;
}