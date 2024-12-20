#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isPath[31][11];
int n, m, h;

bool canBuild(int r, int c) {
    return !isPath[r][c] && !isPath[r][c - 1] && !isPath[r][c - 1];
}

int getDest(int r, int c) {
    if (r > h) return c;
    if (isPath[r][c - 1]) return getDest(r + 1, c - 1);
    else if (isPath[r][c]) return getDest(r + 1, c + 1);
    else return getDest(r + 1, c);
}

void setPath(int r, int c, int curr, int tot) {
    if (curr > tot) {
        return;
    } else if (r > h) {
        for (int i = 1; i <= n; i++) {
            if (getDest(1, i) != i) return;
        }
        cout << tot;
        exit(0);
    }
    int nr = r, nc = c + 1;
    if (nc == n) {
        nc = 1;
        nr++;
    }
    if (canBuild(r, c)) {
        isPath[r][c] = true;
        setPath(nr, nc, curr + 1, tot);
        isPath[r][c] = false;
    }
    setPath(nr, nc, curr, tot);

}

int main() {
    FastIO
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        isPath[a][b] = true;
    }

    for (int i = 0; i <= 3; i++) {
        setPath(1, 1, 0, i);
    }
    cout << -1;
    return 0;
}