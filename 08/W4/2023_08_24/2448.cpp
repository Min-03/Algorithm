#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[3072][10000];

void go(int x, int y, int size) {
    if (size == 3) {
        graph[x][y] = graph[x + 1][y + 1] = graph[x + 1][y - 1] = '*';
        memset(graph[x + 2] + (y - 2), '*', 5);
        return;
    }
    go(x, y, size / 2);
    go(x + size / 2, y - size / 2, size / 2);
    go(x + size / 2, y + size / 2, size / 2);
}

int main() {
    FastIO
    int n;
    cin >> n;
    int width = 5 * (n / 3) + (n / 3 - 1);
    memset(graph, ' ', sizeof(graph));
    go(0, n - 1, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width; j++) cout << graph[i][j];
        cout << '\n';
    }
    return 0;
}