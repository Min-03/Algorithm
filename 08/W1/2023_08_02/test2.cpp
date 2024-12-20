#include <bits/stdc++.h>
using namespace std;

bool rowUsed[9][10];
bool colUsed[9][10];
bool sqUsed[3][3][10];
int graph[9][9];

void setUsed(int x, int y, int num, bool used) {
    rowUsed[x][num] = used;
    colUsed[y][num] = used;
    sqUsed[x / 3][y / 3][num] = used;
}

bool check(int x, int y, int num) {

    return !rowUsed[x][num] && !colUsed[y][num] && !sqUsed[x / 3][y / 3][num];
}

void go(int x, int y) {
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << graph[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    if (graph[x][y] != 0) {
        if (y < 8) {
            go(x, y + 1);
        } else {
            go(x + 1, 0);
        }
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (!check(x, y, i)) {
                continue;
            }
            graph[x][y] = i;
            setUsed(x, y, i, true);
            if (y < 8) {
                go(x, y + 1);
            } else {
                go(x + 1, 0);
            }
            graph[x][y] = 0;
            setUsed(x, y, i, false);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> graph[i][j];
            setUsed(i, j, graph[i][j], true);
        }
    }
    go(0, 0);
    return 0;
}

