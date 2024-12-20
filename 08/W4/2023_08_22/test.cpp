#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int power(int a, int b) {
    int ret = 1;
    while (b != 0) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int n;
    cout << power(3, 5);
//    cin >> n;
//    vector<int> lis, lds;
//    for (int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//        auto upIt = lower_bound(lis.begin(), lis.end(), num);
//        auto downIt = lower_bound(lds.begin(), lds.end(), num, greater<int>());
//        if (upIt == lis.end()) {
//            lis.push_back(num);
//        } else {
//            *upIt = num;
//        }
//
//        if (downIt == lds.end()) {
//            lds.push_back(num);
//        } else {
//            *downIt = num;
//        }
//    }
//    cout << lis.size() << ' ' << lds.size();
    return 0;
}