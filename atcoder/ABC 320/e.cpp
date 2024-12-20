#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

long long eaten[200'001];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> wait;
    priority_queue<int, vector<int>, greater<int>> curr;
    for (int i = 1; i <= n; i++) {
        curr.push(i);
    }
    for (int i = 0; i < m; i++) {
        int t, w, s;
        cin >> t >> w >> s;
        while (!wait.empty() && wait.top().first <= t) {
            curr.push(wait.top().second);
            wait.pop();
        }
        if (!curr.empty()) {
            int person = curr.top();
            eaten[person] += w;
            curr.pop();
            wait.push({t + s, person});
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << eaten[i] << '\n';
    }
    return 0;
}