#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int sums[100'001];
int honeys[100'001];

int main() {
  FASTIO
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> honeys[i];
    sums[i + 1] = sums[i] + honeys[i];
  }
  //벌, 벌, 벌통
  int base = sums[n] - sums[1], hi = -1e4;
  for (int i = 1; i < n - 1; i++) {
    int add = sums[n] - sums[i + 1] - honeys[i];
    hi = max(hi, add);
  }
  ans = base + hi;
  //벌통, 벌, 벌
  base = sums[n - 1], hi = -1e4;
  for (int i = 1; i < n - 1; i++) {
    int add = sums[i] - honeys[i];
    hi = max(hi, add);
  }
  ans = max(ans, base + hi);
  //벌, 벌통, 벌
  hi = 0;
  for (int i = 1; i < n - 1; i++) {
    int left = sums[i + 1] - sums[1];
    int right = sums[n - 1] - sums[i];
    hi = max(hi, left + right);
  }
  ans = max(ans, hi);
  cout << ans;
  return 0;
}