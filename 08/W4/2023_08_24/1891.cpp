#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string input;
int n;
bool ok = true;

long long power(long long a, long long b) {
    long long ret = 1;
    while (b != 0) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    assert(ret != 0);
    return ret;
}

void change(int pos, bool horizon) {
    int num = input[pos] - '0';
    int moveX[] = {0, 2, 1, 4,
                   3};
    int moveY[] = {0, 4, 3, 2, 1};
    assert(1 <= num && num <= 4);
    if (horizon) {
        input[pos] = moveX[num] + '0';
    } else {
        input[pos] = moveY[num] + '0';
    }
}

void update(int pos, bool horizon, bool positive) {
    if (pos < 0) {
        ok = false;
        return;
    }
    change(pos, horizon);
    int num = input[pos] - '0';
    if (horizon) {
        if (positive && (num == 2 || num == 3)) {
            update(pos - 1, horizon, positive);
        } else if (!positive && (num == 1 || num == 4)) {
            update(pos - 1, horizon, positive);
        }
    } else {
        if (positive && (num == 4 || num == 3)) {
            update(pos - 1, horizon, positive);
        } else if (!positive && (num == 2 || num == 1)) {
            update(pos - 1, horizon, positive);
        }
    }
}

void go(long long x, long long y) {
    bool xPositive = true, yPositive = true;
    if (x < 0) {
        x = -x;
        xPositive = false;
    }
    if (y < 0) {
        y = -y;
        yPositive = false;
    }
    for (int i = 0; i < n; i++) {
        long long needed = power(2, n - i - 1);
        if (x >= needed) {
            update(i, true, xPositive);
            x -= needed;
        }
    }
    if (x > 0) {
        ok = false;
        return;
    }
    for (int i = 0; i < n; i++) {
        long long needed = power(2, n - i - 1);
        if (y >= needed) {
            update(i, false, yPositive);
            y -= needed;
        }
    }
    if (y > 0) {
        ok = false;
    }
}

int main() {
    FastIO
    long long x, y;
    cin >> n;
    cin >> input;
    cin >> x >> y;
    go(x, y);
    if (ok) cout << input;
    else cout << -1;
    return 0;
}
