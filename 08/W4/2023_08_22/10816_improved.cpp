#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int add = 10'000'000;
int cnts[2 * add + 1];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnts[num + add] += 1;
    }
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << cnts[num + add] << ' ';
    }
    return 0;
}