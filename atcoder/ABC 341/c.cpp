#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[500][500];
int h, w, n;
string t;

pair<int, int> getNext(int x, int y, char ch) {
    if (ch == 'L') return {x, y - 1};
    if (ch == 'U') return {x - 1, y};
    if (ch == 'D') return {x + 1, y};
    return {x, y + 1};
}

bool check(int x, int y) {
    auto ok = [] (int x, int y) {
        return 0 <= x && x < h && 0 <= y && y < w && graph[x][y] == '.';
    };
    if (!ok(x, y)) return false;
    for (char ch : t) {
        tie(x, y) = getNext(x, y, ch);
        if (!ok(x, y)) return false;
    }
    return true;
}

int main() {
    FastIO
    cin >> h >> w >> n >> t;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> graph[i][j];
    }
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (check(i, j)) cnt++;
        }
    }
    cout << cnt;
    return 0;
}