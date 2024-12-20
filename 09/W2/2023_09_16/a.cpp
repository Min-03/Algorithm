#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int scores[5];

int main() {
    FastIO
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> scores[i];
    }
    int a, b, c;
    a = b = c = 0;
    if (scores[0] > scores[2]) a = (scores[0] - scores[2]) * 508;
    else a = (scores[2] - scores[0]) * 108;

    if (scores[1] > scores[3]) b = (scores[1] - scores[3]) * 212;
    else b = (scores[3] - scores[1]) * 305;

    if (t == 5) c = scores[4] * 707;
    cout << (a + b + c) * 4763;
    return 0;
}