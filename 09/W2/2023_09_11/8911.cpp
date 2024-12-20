#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int loX, loY, hiX, hiY, dir = 0, x = 500, y = 500;
        loX = loY = hiX = hiY = 500;
        string str;
        cin >> str;
        for (char ch : str) {
            if (ch == 'F') {
                x += dx[dir];
                y += dy[dir];
            } else if (ch == 'B') {
                x -= dx[dir];
                y -= dy[dir];
            } else if (ch == 'L') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir - 1 + 4) % 4;
            }
            loX = min(loX, x);
            loY = min(loY, y);
            hiX = max(hiX, x);
            hiY = max(hiY, y);
        }
        cout << (hiX - loX) * (hiY - loY) << '\n';
    }
    return 0;
}