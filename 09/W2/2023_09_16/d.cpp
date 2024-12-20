#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FastIO
    int n;
    cin >> n;
    queue<pair<string, int>> q;
    for (int i = 0; i < n; i++) {
        string ch;
        int num;
        cin >> ch >> num;
        q.push({ch, num});
    }
    if (n == 1) {
        cout << q.front().first;
        return 0;
    }
    while (q.size() > 1) {
        auto [curr, num] = q.front(); q.pop();
        for (int i = 0; i < num - 1; i++) {
            auto temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    cout << q.front().first;
    return 0;
}