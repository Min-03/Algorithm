#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    vector<int> positives;
    vector<int> negatives;
    bool isZero = false;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > 0) {
            positives.push_back(num);
        } else if (num == 0) {
            isZero = true;
        } else {
            negatives.push_back(num);
        }
    }
    sort(positives.begin(), positives.end(), greater<int>());
    sort(negatives.begin(), negatives.end());

    int ans = 0;
    int length = positives.size();
    for (int i = 0; i < length - 1; i += 2) {
        if (positives[i + 1] == 1) ans += positives[i] + positives[i + 1];
        else ans += positives[i] * positives[i + 1];
    }
    if (length & 1) ans += positives.back();
    length = negatives.size();
    for (int i = 0; i < length - 1; i += 2) {
        ans += negatives[i] * negatives[i + 1];
    }
    if ((length & 1) && !isZero) ans += negatives.back();
    cout << ans;
    return 0;
}