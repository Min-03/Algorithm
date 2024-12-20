#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isAbove[300'001];

int main() {
    FastIO
    int n, hi = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!isAbove[num - 1]) hi = max(hi, num);
        isAbove[num] = true;
    }
    cout << hi - 1;
    return 0;
}