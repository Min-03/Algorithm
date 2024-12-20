#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    stack<int> s;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            s.pop();
        } else {
            s.push(n);
        }
    }
    long long sum = 0;
    while (!s.empty()) {
        sum += s.top(); s.pop();
    }
    cout << sum;
    return 0;
}