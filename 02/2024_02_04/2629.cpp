#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool check[15'001];

int main() {
    FastIO
    int n;
    cin >> n;
    check[0] = true;
    vector<int> nums(n);
    for (int &i : nums) cin >> i;

    for (int num : nums) {
        vector<int> add;
        for (int j = 0; j <= 15'000; j++) {
            if (check[j]) {
                if (!check[j + num]) add.push_back(j + num);
            }
        }
        for (int x : add) {
            check[x] = true;
        }
        add.clear();
    }

    for (int num : nums) {
        vector<int> add;
        for (int j = 0; j <= 15'000; j++) {
            if (check[j]) {
                if (j >= num && !check[j - num]) add.push_back(j - num);
            }
        }
        for (int x : add) check[x] = true;
        add.clear();
    }

    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        if (num > 15'000 || !check[num]) cout << "N ";
        else cout << "Y ";
    }
    return 0;
}