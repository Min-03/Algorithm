#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string start;

pair<long long, long long> getPos(int index) {
    if (index == start.length()) return {0, 0};
    int num = start[index] - '0';
    auto [x, y] = getPos(index + 1);
    long long add = 1LL << (start.length() - index - 1);
    if (num == 1) {
        x += add;
    } else if (num == 2) {
        //그대로
    } else if (num == 3) {
        y += add;
    } else {
        x += add;
        y += add;
    }
    return {x, y};
}

void print(int level, long long x, long long y) {
    if (level < 0) return;
    long long std = (1LL << level);
    if (x >= std) {
        if (y >= std) {
            cout << 4;
            print(level - 1, x - std, y - std);
        } else {
            cout << 1;
            print(level - 1, x - std, y);
        }
    } else {
        if (y >= std) {
            cout << 3;
            print(level - 1, x, y - std);
        } else {
            cout << 2;
            print(level - 1, x, y);
        }
    }
}

int main() {
    FastIO
    int d;
    cin >> d >> start;
    long long dx, dy;
    cin >> dx >> dy;
    dy = -dy;
    auto [nx, ny] = getPos(0);
    nx += dx;
    ny += dy;
    long long size = (1LL << d);
    if (0 <= nx && nx < size && 0 <= ny && ny < size) {
        print(d - 1, nx, ny);
    } else {
        cout << -1;
    }
    return 0;
}