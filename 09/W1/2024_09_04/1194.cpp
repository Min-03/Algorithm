#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int fruits[200'000];
int n;

int go(int a, int b) {
    int ret = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (fruits[i] == a || fruits[i] == b) {
            curr += 1;
        } else {
            ret = max(ret, curr);
            curr = 0;
        }
    }
    ret = max(ret, curr);
    return ret;
}

int main() {
    int hi = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> fruits[i];
    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            hi = max(hi, go(i, j));
        }
    }
    cout << hi;
    return 0;
}