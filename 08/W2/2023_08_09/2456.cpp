#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

tuple<int, int, int> candidates[3]; // (총 점수, 3점 횟수, 2점 횟수)

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int score;
            cin >> score;
            get<0>(candidates[j]) += score;
            if (score == 3) {
                get<1>(candidates[j]) += 1;
            } else if (score == 2) {
                get<2>(candidates[j]) += 1;
            }
        }
    }
    bool ok = true;
    int index = 0;
    auto hi = candidates[0];
    for (int i = 1; i < 3; i++) {
        if (hi < candidates[i]) {
            index = i;
            hi = candidates[i];
            ok = true;
        } else if (hi == candidates[i]) {
            ok = false;
        }
    }
    if (ok) {
        cout << index + 1 << ' ' << get<0>(hi);
    } else {
        cout << 0 << ' ' << get<0>(hi);
    }
    return 0;
}