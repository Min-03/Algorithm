#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FastIO
    int n, jimin, hansu, cnt = 0;
    cin >> n >> jimin >> hansu;
    while (jimin != hansu) {
        jimin = (jimin + 1) / 2;
        hansu = (hansu + 1) / 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}