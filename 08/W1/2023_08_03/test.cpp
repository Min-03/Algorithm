#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char graph[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans = -1;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pii red, blue;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') {
                red.first = i;
                red.second = j;
            } else if (graph[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
            }
        }
    }
    cout << n << ' ' << m;
//    go(red, blue, 1);
//    cout << ans;
    return 0;
}
