#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[3][3];
bool seen[3][3];
int total;
int disappoints;

bool check(int x, int y) {
    if (seen[x][(y + 1) % 3] && seen[x][(y + 2) % 3] && graph[x][(y + 1) % 3] == graph[x][(y + 2) % 3]) return true;
    if (seen[(x + 1) % 3][y] && seen[(x + 2) % 3][y] && graph[(x + 1) % 3][y] == graph[(x + 2) % 3][y]) return true;
    if (x - y == 0) {
        if (x == 0 && seen[1][1] && seen[2][2] && graph[1][1] == graph[2][2]) return true;
        if (x == 1 && seen[0][0] && seen[2][2] && graph[0][0] == graph[2][2]) return true;
        if (x == 2 && seen[0][0] && seen[1][1] && graph[0][0] == graph[1][1]) return true;
    }
    if (x + y == 2) {
        if (x == 0 && seen[1][1] && seen[2][0] && graph[1][1] == graph[2][0]) return true;
        if (x == 1 && seen[0][2] && seen[2][0] && graph[0][2] == graph[2][0]) return true;
        if (x == 2 && seen[0][2] && seen[1][1] && graph[0][2] == graph[1][1]) return true;
    }
    return false;
}

void go(int x, int y, int selected, bool disappointed) {
    if (check(x, y)) disappointed = true;

    if (selected == 9) {
        total++;
        if (disappointed) disappoints++;
        return;
    }

    //다음 이동
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!seen[i][j]) {
                seen[i][j] = true;
                go(i, j, selected + 1, disappointed);
                seen[i][j] = false;
            }
        }
    }
}

int main() {
    FastIO
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> graph[i][j];
        }
    }
    go(-1, -1, 0, false);
//    cout << disappoints << ' ' << total;
    cout << fixed << setprecision(15) << (double) (total - disappoints) / total;
    return 0;
}