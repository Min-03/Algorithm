#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int wins[101];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'o') wins[i]++;
        }
    }
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    sort(nums.begin(), nums.end(), [] (int a, int b) {
        if (wins[a] == wins[b]) {
            return a < b;
        } else {
            return wins[a] > wins[b];
        }
    });
    for (int num : nums) {
        cout << num << ' ';
    }
    return 0;
}