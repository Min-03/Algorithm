#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int wheels[5][8];
bool matched[5], visited[5];

void go(int curr, bool clockWise) {
    visited[curr] = true;
    if (clockWise) {
        rotate(wheels[curr], wheels[curr] + 7, wheels[curr] + 8);
    } else {
        rotate(wheels[curr], wheels[curr] + 1, wheels[curr] + 8);
    }
    if (curr > 1 && !matched[curr - 1] && !visited[curr - 1]) go(curr - 1, !clockWise);
    if (curr < 4 && !matched[curr] && !visited[curr + 1]) go(curr + 1, !clockWise);
}

int main() {
    FastIO
    for (int i = 1; i <= 4; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = numStr[j] - '0';
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int target, dir;
        cin >> target >> dir;
        //matched 업데이트
        for (int j = 1; j < 4; j++) {
            if (wheels[j][2] == wheels[j + 1][6]) matched[j] = true;
            else matched[j] = false;
        }
        memset(visited, 0, sizeof(visited));
        //쿼리 수행
        go(target, (dir == 1));
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
//        cout << wheels[i][0] << ' ';
        ans += wheels[i][0] * (1 << (i - 1));
    }
    cout << ans;
    return 0;
}