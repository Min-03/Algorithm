#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int main() {
    FastIO
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> graph(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
        }
    }
    int ans = inf;
    for (int i = 0; i < h; i++) {
        int cntTot = 0, cntCir = 0;
        for (int j = 0; j < w; j++) {
            if (graph[i][j] == 'x') {
                cntTot = 0;
                cntCir = 0;
                continue;
            }
            cntTot++;
            if (graph[i][j] == 'o') cntCir++;

            if (cntTot < k) continue;
            else if (cntTot > k && graph[i][j - k] == 'o') cntCir--;
            int res = k - cntCir;
            ans = min(ans, res);
        }
    }

    for (int j = 0; j < w; j++) {
        int cntTot = 0, cntCir = 0;
        for (int i = 0; i < h; i++) {
            if (graph[i][j] == 'x') {
                cntTot = 0;
                cntCir = 0;
                continue;
            }
            cntTot++;
            if (graph[i][j] == 'o') cntCir++;

            if (cntTot < k) continue;
            else if (cntTot > k && graph[i - k][j] == 'o') cntCir--;
            int res = k - cntCir;
            ans = min(ans, res);
        }
    }
    cout << (ans == inf ? -1 : ans);
    return 0;
}