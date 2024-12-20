#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int ranks[500'000];
int parents[500'000];

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
    for (int i = 0; i < n; i++) parents[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) == find_set(b)) {
            cout << i;
            return 0;
        }
        union_set(a, b);
    }
    cout << 0;
    return 0;
}