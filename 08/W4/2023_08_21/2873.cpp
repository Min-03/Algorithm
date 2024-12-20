#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char cmds[] = {'D', 'R', 'U', 'R'};

//2줄 이동 출력
void printMoves(int c, bool beforeTarget) {
    for (int i = 0; i < c - 1; i++) {
        cout << (beforeTarget ? "R" : "L");
    }
    cout << "D";
    beforeTarget = !beforeTarget;
    for (int i = 0; i < c - 1; i++) {
        cout << (beforeTarget ? "R" : "L");
    }
}



//lo가 있는 2줄 출력
void printTarget(int c, int ex, int ey) {
    int x = 0;
    int y = 0;
    int index = 0;
    while (true) {
        int tx = x, ty = y;
        if (cmds[index] == 'U') {
            tx = x - 1;
        } else if (cmds[index] == 'D') {
            tx = x + 1;
        } else {
            ty = y + 1;
        }
        if (tx == 1 && ty == c - 1) {
            cout << cmds[index];
            break;
        } else if (tx == ex && ty == ey) {
            tx = x;
            ty = y + 1;
            index = (index - 1 + 4) % 4;
        }
        cout << cmds[index];
        x = tx;
        y = ty;
        index = (index + 1) % 4;
    }
}

int main() {
    FastIO
    int r, c, x, y, lo = 1000;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int num;
            cin >> num;
            if (((i + j) & 1) && num < lo) {
                x = i;
                y = j;
                lo = num;
            }
        }
    }

    if (r & 1) {
        for (int i = 0; i < r; i++) {
            if (i != 0) cout << "D";
            for (int j = 0; j < c - 1; j++) {
                cout << (i & 1 ? "L" : "R");
            }
        }
        return 0;
    } else if (c & 1) {
        for (int j = 0; j < c; j++) {
            if (j != 0) cout << "R";
            for (int i = 0; i < r - 1; i++) {
                cout << (j & 1 ? "U" : "D");
            }
        }
        return 0;
    }

    //r, c 둘 다 짝수
    bool beforeTarget = true;
    for (int i = 0; i < r; i += 2) {
        if (i != 0) cout << "D";
        if (i / 2 == x / 2) {
            printTarget(c, (x & 1), y);
            beforeTarget = false;
        } else {
            printMoves(c, beforeTarget);
        }
    }

    return 0;
}