#include <bits/stdc++.h>
using namespace std;

int nums[11];
vector<char> ops;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        int freq;
        cin >> freq;
        for (int j = 0; j < freq; j++) {
            if (i == 0) {
                ops.push_back('+');
            } else if (i == 1) {
                ops.push_back('-');
            } else if (i == 2) {
                ops.push_back('*');
            } else {
                ops.push_back('/');
            }
        }
    }

    sort(ops.begin(), ops.end());
    int low = 1e9, high = -1e9;
    do {
        int val = nums[0];
        for (int i = 0; i < n - 1; i++) {
            char op = ops[i];
            switch (op) {
                case '+':
                    val += nums[i + 1];
                    break;
                case '-':
                    val -= nums[i + 1];
                    break;
                case '*':
                    val *= nums[i + 1];
                    break;
                case '/':
                    val /= nums[i + 1];
                    break;
            }
        }
        low = min(low, val);
        high = max(high, val);
    } while (next_permutation(ops.begin(), ops.end()));
    cout << high << '\n' << low;
    return 0;
}