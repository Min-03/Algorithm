#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
char graph[6561][6561];

void fillBlank(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) graph[i][j] = ' ';
    }
}

void go(int x, int y, int size) {
    if (size == 3) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) graph[i][j] = '*';
        }
        graph[x + 1][y + 1] = ' ';
        return;
    }
    int step = size / 3;
    for (int i = x; i < x + size; i += step) {
        for (int j = y; j < y + size; j += step) {
            if (i == x + step && j == y + step) {
                fillBlank(i, j, step);
            }
            else {
                go(i, j, step);
            }
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    go(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j];
        }
        cout << '\n';
    }
    return 0;
}