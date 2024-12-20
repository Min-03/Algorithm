#include <bits/stdc++.h>
using namespace std;

bool check[2'000'001];
int nums[20];
int n;

void go(int index, int val) {
    if (index == n) {
        check[val] = true;
        return;
    }
    go(index + 1, val + nums[index]);
    go(index + 1, val);

}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    go(0, 0);

    for (int i = 1; i <= 2'000'000; i++) {
        if (!check[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}