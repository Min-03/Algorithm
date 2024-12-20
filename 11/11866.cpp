#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  for (int i = 1; i <= n; i++) q.push(i);
  cout << '<';
  int cnt = 0;
  while (q.size() > 1) {
    cnt++;
    if (cnt == k) {
      cout << q.front() << ", ";
      // cout << q.front() << '\n';
      q.pop();
      cnt = 0;
      continue;
    }
    q.push(q.front()); q.pop();
  }
  cout << q.front() << '>';
  return 0;
}