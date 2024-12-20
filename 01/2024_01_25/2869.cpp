#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int a, b, v;
    cin >> a >> b >> v;
    int quotient = (v - a) / (a - b) + 1;
    int remainder = (v - a) % (a - b);
    cout << (remainder == 0 ? quotient : quotient + 1);
    return 0;
}