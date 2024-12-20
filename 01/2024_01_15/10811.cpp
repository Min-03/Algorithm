#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[101];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        nums[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        stack<int> s;
        for (int j = x; j <= y; j++) {
            s.push(nums[j]);
        }
        for (int j = x; j <= y; j++) {
            nums[j] = s.top(); s.pop();
        }

    }

    for (int i = 1; i <= n; i++) {
        cout << nums[i] << ' ';
    }
    FastIO
    return 0;
}