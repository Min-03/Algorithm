#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[10'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnts[num] += 1;
    }

    for (int i = 1; i <= 10'000; i++) {
        for (int j = 0; j < cnts[i]; j++) cout << i << '\n';
    }
    return 0;
}