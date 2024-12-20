#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    lo.push(-1e5);
    hi.push(1e5);
    while (n--) {
        int num;
        cin >> num;
        if (lo.size() > hi.size()) {
            int l = lo.top(); lo.pop();
            int r = num;
            if (l > r) swap(l, r);
            lo.push(l);
            hi.push(r);
        } else {
            int l = hi.top(); hi.pop();
            int r = num;
            if (l > r) swap(l, r);
            lo.push(l);
            hi.push(r);
        }
        cout << lo.top() << '\n';
    }
    return 0;
}