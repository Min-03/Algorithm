#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    char base, add;
    cin >> base;
    double score;
    if (base == 'A') score = 4;
    else if (base == 'B') score = 3;
    else if (base == 'C') score = 2;
    else if (base == 'D') score = 1;
    else score = 0;
    if (score == 0) {
        cout << "0.0";
        return 0;
    }
    cin >> add;
    if (add == '+') score += 0.3;
    else if (add == '-') score -= 0.3;
    cout << fixed << setprecision(1) << score;
    return 0;
}