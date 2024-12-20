#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[500][500];
int temp[500][500];

int main() {
    FastIO
    int n, m;
    long long b;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    long long ans = 1e15, h;
    //높이를 k로 설정
    for (int k = 0; k <= 256; k++) {
        long long left = b, res = 0;
        memcpy(temp, graph, sizeof(graph));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] > k) {
                    res += 2 * (temp[i][j] - k);
                    left += temp[i][j] - k;
                    temp[i][j] = k;
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] != k) {
                    assert(temp[i][j] < k);
                    res += k - temp[i][j];
                    left -= k - temp[i][j];
                    temp[i][j] = k;
                    if (left < 0) {
                        ok = false;
                        goto END;
                    }
                }
            }
        }
        END:
        if (ok && res <= ans) {
            ans = res;
            h = k;
        }
    }
    cout << ans << ' ' << h;
    return 0;
}