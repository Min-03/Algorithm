#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[128][128];
int ans[2];

bool check(int sx, int sy, int size) {
    int base = graph[sx][sy];
    for (int i = sx; i < sx + size; i++) {
        for (int j = sy; j < sy + size; j++) {
            if (graph[i][j] != base) return false;
        }
    }
    return true;
}

void go(int sx, int sy, int size) {
    if (check(sx, sy, size)) {
        ans[graph[sx][sy]]++;
        return;
    }

    int next = size / 2;
    for (int i = sx; i < sx + size; i += next) {
        for (int j = sy; j < sy + size; j += next) {
            go(i, j, next);
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    go(0, 0, n);
    cout << ans[0] << '\n' << ans[1];
    return 0;
}