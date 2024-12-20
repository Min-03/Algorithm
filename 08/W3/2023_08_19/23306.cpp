#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, start, end;
    cin >> n;
    cout << "? " << 1 << endl;
    cin >> start;
    cout << "? " << n << endl;
    cin >> end;
    if (start < end) {
        cout << "! " << 1 << endl;
    } else if (start > end) {
        cout << "! " << -1 << endl;
    } else {
        cout << "! " << 0 << endl;
    }
    return 0;
}