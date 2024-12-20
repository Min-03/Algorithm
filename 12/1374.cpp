#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
  FASTIO
  int n;
  cin >> n;
  vector<pair<int, int>> classes(n);
  for (int i = 0; i < n; i++) {
    int num, s, e;
    cin >> num >> s >> e;
    classes[i] = {s, e};
  }
  sort(classes.begin(), classes.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [s, e] : classes) {
    pq.push(e);
    if (!pq.empty() && pq.top() <= s) pq.pop();
  }
  cout << pq.size();
  return 0;
}