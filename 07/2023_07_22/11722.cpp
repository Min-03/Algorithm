#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> lis;
    int n;
    cin >> n;
    while (n--) {
        int curr;
        cin >> curr;
        if (lis.empty() || curr < lis.back()) {
            lis.push_back(curr);
            continue;
        }
        int pos = lower_bound(lis.begin(), lis.end(), curr, greater<int>()) - lis.begin();
        lis.at(pos) = curr;
    }
    cout << lis.size();
    return 0;
}