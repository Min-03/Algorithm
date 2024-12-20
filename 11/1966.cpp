#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
  FASTIO
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      q.push({x, i});
      pq.push(x);
    }
    int cnt = 0;
    while (!q.empty()) {
      auto [x, i] = q.front();;
      if (x == pq.top()) {
        pq.pop();
        q.pop();
        cnt++;
        if (i == m) {
          cout << cnt << '\n';
          break;
        }
      } else {
        q.push(q.front()); q.pop();
      }
    }
  }
  return 0;
}