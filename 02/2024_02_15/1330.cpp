#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int a, b;
    cin >> a >> b;
    if (a > b) cout << '>';
    else if (a < b) cout << '<';
    else cout << "==";
    return 0;
}