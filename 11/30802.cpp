#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int nums[6];

int main() {
  FASTIO
  int n, t, p, ansT = 0;
  cin >> n;
  for (int i = 0; i < 6; i++) cin >> nums[i];
  cin >> t >> p;
  for (int i = 0; i < 6; i++) {
    ansT += (nums[i] % t == 0) ? (nums[i] / t) : (nums[i] / t + 1);
  }
  cout << ansT << '\n' << n / p << ' ' << n % p;
  return 0;
}