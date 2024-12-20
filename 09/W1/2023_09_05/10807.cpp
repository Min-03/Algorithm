#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[201];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnts[num + 100] += 1;
    }
    int v;
    cin >> v;
    cout << cnts[v + 100];
    return 0;
}