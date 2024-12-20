#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<long long> nums;

void go(long long x) {
    nums.push_back(x);
    for (long long nxt : {x * 10 + 4, x * 10 + 7}) {
        if (nxt <= 1'000'000'000) go(nxt);
    }
}

int main() {
    FastIO
    go(4);
    go(7);
    sort(nums.begin(), nums.end());
    long long a, b;
    cin >> a >> b;
    cout << upper_bound(nums.begin(), nums.end(), b) - lower_bound(nums.begin(), nums.end(), a);
    return 0;
}