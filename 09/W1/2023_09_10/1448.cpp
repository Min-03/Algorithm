#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }
    sort(lengths.begin(), lengths.end(), greater<int>());
    for (int i = 0; i < n - 2; i++) {
        if (lengths[i] < lengths[i + 1] + lengths[i + 2]) {
            cout << lengths[i] + lengths[i + 1] + lengths[i + 2];
            return 0;
        }
    }
    cout << -1;
    return 0;
}