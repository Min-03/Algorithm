#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> houses;
int n, c;

bool check(int x) {
    int cnt = 1;
    int dist = 0;
    for (int i = 1; i < houses.size(); i++) {
        dist += houses[i] - houses[i - 1];
        if (dist >= x) {
            cnt++;
            dist = 0;
        }
    }
    return cnt >= c;
}

int main() {
    FastIO
    cin >> n >> c;
    houses.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
    int lo = 0, hi = houses.back() + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}