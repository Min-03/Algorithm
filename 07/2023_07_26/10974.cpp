#include <bits/stdc++.h>

using namespace std;

int calScore(vector<int> &vec) {
    int score = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        score += abs(vec.at(i + 1) - vec.at(i));
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int ans = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    do {
        ans = max(ans, calScore(vec));
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans;
    return 0;
}