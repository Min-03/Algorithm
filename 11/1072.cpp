#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

long long x, y, winRate;

bool check(int add) {
  int newWinRate = round(floor(((100 * (y + add)) / (double) (x + add))));
  return newWinRate != winRate;
}

int main() {
  FASTIO
  cin >> x >> y;
  winRate = round(floor(((100 * y) / (double) x)));
  if (winRate >= 99) {
    cout << -1;
    return 0;
  }
  int lo = -1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  cout << hi;
  return 0;
}