#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> a;

int main() {
    FastIO
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[i] = {num, i};
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    stack<int> s;
    s.push(a[n - 1].second);
    for (int i = n - 2; i >= 0; i--) {
        int pos = a[i].second;
        while (!s.empty() && s.top() < pos) {
            s.pop();
            cnt++;
        }
        s.push(pos);
    }
    cout << cnt + 1;
    return 0;
}