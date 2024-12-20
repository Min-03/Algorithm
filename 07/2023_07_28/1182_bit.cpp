#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    int nums[20];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int cnt = 0;
    for (int set = 1; set < (1 << n); set++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((set & (1 << i)) != 0) {
                sum += nums[i];
            }
        }
        if (sum == s) {
            cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}