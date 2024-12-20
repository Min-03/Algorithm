#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, l, w;
    cin >> n >> l >> w;
    queue<pair<int, int>> q;
    queue<int> weights;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        weights.push(weight);
    }
    int time = 1, totW = 0;
    while (true) {
        if (!q.empty() && q.front().first + l <= time) {
            totW -= q.front().second;
            q.pop();
        }
        if (q.empty() && weights.empty()) break;
        if (!weights.empty() && q.size() < l && totW + weights.front() <= w) {
            totW += weights.front();
            q.push({time, weights.front()});
            weights.pop();
        }
        time++;
    }
    cout << time;
    return 0;
}