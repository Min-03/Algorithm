#include <bits/stdc++.h>
using namespace std;

int dp[16];
pair<int, int> work[16];
int n;

int go(int day) {
    if (day == n + 1) return 0;
    if (day > n + 1) return -100'000;
    if (dp[day] != 0) {
        return dp[day];
    }
    int noWork = go(day + 1);
    int withWork = go(day + work[day].first) + work[day].second;
    return dp[day] = max(noWork, withWork);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> work[i].first >> work[i].second;
    }
    cout << go(1);
    return 0;
}
