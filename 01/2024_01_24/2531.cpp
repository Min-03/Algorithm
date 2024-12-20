#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int eaten[3'001];

int main() {
    FastIO
    int n, d, k, c, cnt = 0, ans = 0;
    cin >> n >> d >> k >> c;
    queue<int> q, front;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (q.size() >= k) {
            int leftDish = q.front(); q.pop();
            eaten[leftDish]--;
            if (!eaten[leftDish]) cnt--;
        }
        int newDish;
        cin >> newDish;
        if (i < k - 1) front.push(newDish);
        if (!eaten[newDish]) cnt++;
        eaten[newDish]++;
        q.push(newDish);
        if (ans < cnt) {
            ans = cnt;
            ok = eaten[c] == 0;
        } else if (ans == k && !ok) {
            ok = eaten[c] == 0;
        }
    }

    while (!front.empty()) {
        if (q.size() >= k) {
            int leftDish = q.front(); q.pop();
            eaten[leftDish]--;
            if (!eaten[leftDish]) cnt--;
        }
        int newDish = front.front(); front.pop();
        if (!eaten[newDish]) cnt++;
        eaten[newDish]++;
        q.push(newDish);
        if (ans < cnt) {
            ans = cnt;
            ok = eaten[c] == 0;
        } else if (ans == k && !ok) {
            ok = eaten[c] == 0;
        }
    }
    cout << (ok ? ans + 1 : ans);
    return 0;
}