#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100];
string ans;

bool check(int x, int y, int size) {
    int target = graph[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (graph[i][j] != target) return false;
        }
    }
    return true;
}

void go(int x, int y, int size) {
    if (check(x, y, size)) {
        ans += graph[x][y] + '0';
        return;
    }
    int next = size / 2;
    ans += '(';
    for (int i = x; i < x + size; i += next) {
        for (int j = y; j < y + size; j += next) {
            go(i, j, next);
        }
    }
    ans += ')';
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < n; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }
    go(0, 0, n);
    cout << ans;
    return 0;
}