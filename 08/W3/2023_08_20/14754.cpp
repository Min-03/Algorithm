#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[1000][1000];
bool important[1000][1000];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }

    //행별 검사
    for (int i = 0; i < n; i++) {
        int hi = 0;
        int index = -1;
        for (int j = 0; j < m; j++) {
            if (nums[i][j] > hi) {
                index = j;
                hi = nums[i][j];
            }
        }
        important[i][index] = true;
    }

    //열별 검사
    for (int j = 0; j < m; j++) {
        int hi = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i][j] > hi) {
                index = i;
                hi = nums[i][j];
            }
        }
        important[index][j] = true;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!important[i][j]) ans += nums[i][j];
        }
    }
    cout << ans;
    return 0;
}