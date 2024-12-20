#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[2187][2187];
int cnts[3];

void go(int x, int y, int size) {
    if (size == 1) {
        cnts[graph[x][y] + 1]++;
        return;
    }
    bool ok = true;
    int num = graph[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (graph[i][j] != num) {
                ok = false;
                goto exit;
            }
        }
    }
    if (ok) {
        cnts[graph[x][y] + 1]++;
        return;
    }

    exit:
    for (int i = x; i < x + size; i += size / 3) {
        for (int j = y; j < y + size; j += size / 3) {
            go(i, j, size / 3);
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
    for (int cnt : cnts) {
        cout << cnt << '\n';
    }
    return 0;
}