#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

vector<char> ops;
vector<ll> nums;
bool used[10];
int n;
ll ans = -1e10;

ll cal(ll a, ll b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a;
}

void go(int curr) {
    if (curr == n / 2) {
        vector<ll> temp(nums);
        for (int i = 0; i < n / 2; i++) {
            if (!used[i]) continue;
            ll res = cal(nums[i], nums[i + 1], ops[i]);
            temp[i] = res;
            temp[i + 1] = res;
        }
        ll ret;
        for (int i = 0; i < n / 2; i++) {
            if (used[i]) continue;
            if (i != 0 && used[i - 1]) {
                temp[i] = temp[i - 1];
            }
            ll res = cal(temp[i], temp[i + 1], ops[i]);
            temp[i + 1] = res;
            ret = res;
        }
        ans = max(ans, ret);
        return;
    }
    go(curr + 1);
    if (curr != 0 && used[curr - 1]) return;
    used[curr] = true;
    go(curr + 1);
    used[curr] = false;
}

int main() {
    FastIO
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i & 1) ops.push_back(s[i]);
        else nums.push_back(s[i] - '0');
    }
    if (n == 1) {
        cout << nums[0];
        return 0;
    } else if (n == 3) {
        cout << cal(nums[0], nums[1], ops[0]);
        return 0;
    }
    go(0);
    cout << ans;
    return 0;
}