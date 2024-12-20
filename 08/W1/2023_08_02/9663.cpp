#include <bits/stdc++.h>
using namespace std;

int queen[15]; //queen[i] = j -> i번째 열 j행에 위치
int n, cnt = 0;

//index열 pos행에 퀸이 위치하는 게 가능?
bool check(int index, int pos) {
    for (int i = 0; i < index; i++) {
        if (queen[i] == pos || queen[i] + (index - i) == pos || queen[i] - (index - i) == pos) {
            return false;
        }
    }
    return true;
}

void go(int index) {
    if (index == n) {
        cnt += 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check(index, i)) continue;
        queen[index] = i;
        go(index + 1);
        queen[index] = -1;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(queen, -1, sizeof(queen));
    cin >> n;
    go(0);
    cout << cnt;
    return 0;
}