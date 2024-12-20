#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[9][9];
bool colUsed[9][10], rowUsed[9][10], sqUsed[3][3][10];

void setNum(int x, int y, int num, bool start) {
    if (start) {
        colUsed[y][num] = true;
        rowUsed[x][num] = true;
        sqUsed[x / 3][y / 3][num] = true;
        graph[x][y] = num;
    } else {
        colUsed[y][num] = false;
        rowUsed[x][num] = false;
        sqUsed[x / 3][y / 3][num] = false;
        graph[x][y] = 0;
    }
}

bool check(int x, int y, int num) {
    return !rowUsed[x][num] && !colUsed[y][num] && !sqUsed[x / 3][y / 3][num];
}

void go(int curr) {
    if (curr == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << graph[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = curr / 9;
    int y = curr % 9;
    if (graph[x][y] != 0) {
        go(curr + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (check(x, y, i)) {
            setNum(x, y, i, true);
            go(curr + 1);
            setNum(x, y, i, false);
        }
    }
}

int main() {
    FastIO
    for (int i = 0; i < 9; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < 9; j++) {
            setNum(i, j, numStr[j] - '0', true);
        }
    }
    go(0);
    return 0;
}