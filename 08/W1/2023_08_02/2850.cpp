#include <bits/stdc++.h>
using namespace std;

int graph[9][9];
bool found = false;

bool check(int x, int y, int num) {
    //행 검사
    for (int j = 0; j < 9; j++) {
        if (graph[x][j] == num) {
            return false;
        }
    }
    //열 검사
    for (int i = 0; i < 9; i++) {
        if (graph[i][y] == num) {
            return false;
        }
    }
    //대각선 검사
    int nx = x / 3;
    int ny = y / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (graph[nx * 3 + i][ny * 3 + j] == num) {
                return false;
            }
        }
    }
    return true;
}

void go(int x, int y) {
    if (found) return;
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << graph[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
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
            if (y < 8) {
                go(x, y + 1);
            } else {
                go(x + 1, 0);
            }
            graph[x][y] = 0;
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
        }
    }
    cout << '\n';
    go(0, 0);
    return 0;
}

