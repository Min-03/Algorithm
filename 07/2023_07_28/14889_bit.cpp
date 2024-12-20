#include <bits/stdc++.h>
int s[20][20];
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    int diff = 1e9;
    for (int set = 1; set < (1 << n); set++) {
        vector<int> start, link;
        for (int i = 0; i < n; i++) {
            if ((set & (1 << i)) != 0) {
                start.push_back(i);
            } else {
                link.push_back(i);
            }
        }
        if (start.size() != n / 2) continue;
        int scoreS = 0, scoreL = 0;
        for (int i : start) {
            for (int j : start) {
                scoreS += s[i][j];
            }
        }
        for (int i : link) {
            for (int j : link) {
                scoreL += s[i][j];
            }
        }
        diff = min(diff, abs(scoreS - scoreL));
    }
    cout << diff;
    return 0;
}