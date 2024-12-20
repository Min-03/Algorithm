#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool used[1001];
int add[] = {0, 1, 5, 10, 50};
int n;

void go(int step, int selected, int num) {
    if (selected == n) {
        used[num] = true;
        return;
    }
    if (step == 5) {
        return;
    }

    for (int i = 0; i <= n - selected; i++) {
        go(step + 1, selected + i, num + i * add[step]);
    }
}

int main() {
    FastIO
    cin >> n;
    int cnt = 0;
    go(1, 0, 0);
    for (int i = 1; i <= 1000; i++) {
        if (used[i]) cnt++;
    }
    cout << cnt;
    return 0;
}