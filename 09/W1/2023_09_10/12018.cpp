#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        vector<int> people(p);
        for (int j = 0; j < p; j++) {
            cin >> people[j];
        }
        sort(people.begin(), people.end(), greater<int>());
        if (p < l) {
            candidates[i] = 1;
        } else {
            candidates[i] = people[l - 1];
        }
    }
    sort(candidates.begin(), candidates.end());
    int ans = 0;
    for (int candidate : candidates) {
        if (m >= candidate) {
            ans++;
            m -= candidate;
        }
    }
    cout << ans;
    return 0;
}