#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    if (next_permutation(vec.begin(), vec.end())) {
        for (int i = 0; i < n; i++) {
            cout << vec.at(i) << ' ';
        }
    } else {
        cout << -1;
    }
}