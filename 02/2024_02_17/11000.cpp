#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> classes;

int main() {
    FastIO
    int n;
    cin >> n;
    classes.resize(n);
    for (int i = 0; i < n; i++) cin >> classes[i].first >> classes[i].second;
    sort(classes.begin(), classes.end());
    priority_queue<int, vector<int>, greater<>> endTimes;
    for (auto [s, e] : classes) {
        endTimes.push(e);
        if (!endTimes.empty() && endTimes.top() <= s) endTimes.pop();
    }
    cout << endTimes.size();
    return 0;
}