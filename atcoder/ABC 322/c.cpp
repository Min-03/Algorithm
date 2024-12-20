#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> days(m);
    for (int i = 0; i < m; i++) {
        cin >> days[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << *lower_bound(days.begin(), days.end(), i) - i<< '\n';
    }
    return 0;
}