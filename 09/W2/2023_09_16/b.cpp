#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int s;
    cin >> s;
    if (s % 4763 != 0) {
        cout << 0;
        return 0;
    }
    s /= 4763;
    vector<pair<int, int>> ans;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            int temp = s;
            if (i > j) temp -= (i - j) * 508;
            else temp -= (j - i) * 108;
            bool flag1 = false, flag2 = false;
            if (temp % 212 == 0 && 0< temp / 212 && temp / 212 <= 200) {
                ans.push_back({abs(i - j), abs(temp / 212)});
                flag1 = true;
            }
            if (temp % 305 == 0 && 0<= temp / 305 && temp / 305 <= 200) {
                ans.push_back({abs(i - j), abs(temp / 305)});
                flag2 = true;
            }
            assert(!flag1 || !flag2);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
    return 0;
}