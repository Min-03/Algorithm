#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> nums;
vector<char> ops;

int main() {
    FastIO
    string input;
    cin >> input;
    int temp = 0;
    for (char ch : input) {
        if (isdigit(ch)) {
            temp = temp * 10 + (ch - '0');
        } else {
            nums.push_back(temp);
            ops.push_back(ch);
            temp = 0;
        }
    }
    nums.push_back(temp);

    int ans = 0;
    int sign = 1;
    int curr = nums[0];
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            curr += nums[i + 1];
        } else {
            ans += curr * sign;
            sign = -1;
            curr = nums[i + 1];
        }
    }
    ans += curr * sign;
    cout << ans;
    return 0;
}