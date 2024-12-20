#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int input[50][50];
int ans[50][50];
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            input[i][j] = numStr[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            ans[i][j] = numStr[j] - '0';
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (input[i][j] != ans[i][j]) {
                cnt += 1;
                int x = i + 1;
                int y = j + 1;
                for (int k = 0; k < 9; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    input[nx][ny] = 1 - input[nx][ny];
                }
            }
        }
    }

    bool matched = true;
    for (int i = 0; i < n; i++) {
        if (!equal(input[i], input[i] + m, ans[i])) {
            matched = false;
            break;
        }
    }

    cout << (matched ? cnt : -1);
    return 0;
}