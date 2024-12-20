#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[1'000'001], ranks[1'000'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranks[a] > ranks[b]) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parents[i] = i;
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op) cout << (find_set(a) == find_set(b) ? "yes\n" : "no\n");
        else union_set(a, b);
    }
    return 0;
}