#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[4'000'001];
bool exist[4'000'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[a] = b;
}

int main() {
    FastIO
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) parents[i] = i;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        exist[num] = true;
    }
    for (int i = 1; i < n; i++) {
        if (!exist[i]) union_set(i, i + 1);
    }
    while (k--) {
        int num;
        cin >> num;
        int parent = find_set(num + 1);
        cout << parent << '\n';
        union_set(parent, find_set(parent + 1));
    }
    return 0;
}