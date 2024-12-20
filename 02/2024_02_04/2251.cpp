#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int capacity[3];
bool visited[201][201];

pair<int, int> getMove(int x, int y, int yIdx) {
    int moveSize = min(x, capacity[yIdx] - y);
    return {x - moveSize, y + moveSize};
}

void dfs(int a, int b, int c) {
    visited[a][b] = true;
    int na, nb, nc;
    tie(na, nb) = getMove(a, b, 1);
    if (!visited[na][nb]) dfs(na, nb, c);

    tie(na, nc) = getMove(a, c, 2);
    if (!visited[na][b]) dfs(na, b, nc);

    tie(nb, na) = getMove(b, a, 0);
    if (!visited[na][nb]) dfs(na, nb, c);

    tie(nb, nc) = getMove(b, c, 2);
    if (!visited[a][nb]) dfs(a, nb, nc);

    tie(nc, na) = getMove(c, a, 0);
    if (!visited[na][b]) dfs(na, b, nc);

    tie(nc, nb) = getMove(c, b, 1);
    if (!visited[a][nb]) dfs(a, nb, nc);
}

int main() {
    FastIO
    for (int i = 0; i < 3; i++) cin >> capacity[i];
    dfs(0, 0, capacity[2]);
    for (int i = capacity[2]; i >= 0; i--) {
        if (visited[0][i]) {
            cout << capacity[2] - i << ' ';
        }
    }
    return 0;
}