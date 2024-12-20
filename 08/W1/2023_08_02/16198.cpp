#include <bits/stdc++.h>
using namespace std;

int power[10];
bool used[10];

int left(int curr) {
    curr -= 1;
    while (used[curr]) {
        curr -= 1;
    }
    return curr;
}

int right(int curr) {
    curr += 1;
    while (used[curr]) {
        curr += 1;
    }
    return curr;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> power[i];
    }
    vector<int> vec(n - 2);
    for (int i = 0; i < n - 2; i++) {
        vec[i] = i + 1;
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    do {
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int curr = vec[i];
            used[curr] = true;
            res += power[left(curr)] * power[right(curr)];
        }
        ans = max(ans, res);
        memset(used, 0, sizeof(used));
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans;
    return 0;
}