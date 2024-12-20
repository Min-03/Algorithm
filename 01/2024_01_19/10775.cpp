#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[100'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
}

int main() {
    FastIO
    int g, p;
    cin >> g >> p;
    for (int i = 1; i <= g; i++) {
        parents[i] = i;
    }
    int cnt = 0;
    while (cnt < p) {
        int num;
        cin >> num;
        int parent = find_set(num);
        if (parent == 0) break;
        union_set(num, parent - 1);
        cnt++;
    }
    cout << cnt;
    return 0;
}