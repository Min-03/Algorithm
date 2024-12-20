#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<long long> nums;

void go(long long num) {
    nums.push_back(num);
    for (int i = 0; i < num % 10; i++) {
        go(num * 10 + i);
    }
}

int main() {
    FastIO
    nums.reserve(500'000);
    for (int i = 0; i <= 9; i++) go(i);
    sort(nums.begin(), nums.end());
    int n;
    cin >> n;
    cout << (n >= nums.size() ? -1 : nums[n]);
    return 0;
}