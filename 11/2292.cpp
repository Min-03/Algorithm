#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, base = 1, tot = 1;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  while (tot < n) {
    tot += base++ * 6;
  }
  cout << base;
  return 0;
}