#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<int, int> order;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n), copied(n);
    for (int &i : nums) {
        cin >> i;
    }
    copy(nums.begin(), nums.end(), copied.begin());
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        order[nums[i]] = i;
    }
    for (int num : copied) {
        cout << order[num] << ' ';
    }
    return 0;
}