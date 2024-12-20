#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int score[51][10];
int seq[10];
bool selected[10];
int n, ans = 0;

int getScore() {
    int curr = 1, round = 1, ret = 0;
    while (round <= n) {
        int out = 0;
        bool isPerson[4] = {false, false, false, false};
        while (out < 3) {
            int type = score[round][seq[curr]];
            if (type == 0) {
                out++;
            } else {
                for (int i : {3, 2, 1}) {
                    if (!isPerson[i]) continue;
                    isPerson[i] = false;
                    int nxt = i + type;
                    if (nxt >= 4) ret++;
                    else isPerson[nxt] = true;
                }
                if (type == 4) ret++;
                else isPerson[type] = true;
            }
            curr = curr % 9 + 1;
        }
        round++;
    }
    return ret;
}

void go(int curr) {
    if (curr == 10) {
        int res = getScore();
        ans = max(ans, res);
//        for (int i = 1; i <= 9; i++) cout << seq[i] << ' ';
//        cout << res << '\n';
        return;
    }
    if (curr == 4) {
        seq[curr] = 1;
        go(curr + 1);
        selected[1] = true;
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (selected[i]) continue;
        seq[curr] = i;
        selected[i] = true;
        go(curr + 1);
        selected[i] = false;
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) cin >> score[i][j];
    }
    go(1);
    cout << ans;
    return 0;
}