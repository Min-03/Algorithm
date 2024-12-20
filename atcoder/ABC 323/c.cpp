#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int problem[100];
int total[100];
priority_queue<int> notSolved[100];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> problem[i];
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'o') total[i] += problem[j];
            else {
                notSolved[i].push(problem[j]);
            }
        }
        total[i] += i + 1;
    }

    for (int i = 0; i < n; i++) {
        int hi = 0, add = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) hi = max(hi, total[j]);
        }
        while (add + total[i] <= hi) {
            add += notSolved[i].top(); notSolved[i].pop();
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}