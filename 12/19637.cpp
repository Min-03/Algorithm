#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
  FASTIO
  int n, m;
  cin >> n >> m;
  vector<string> names(n);
  vector<int> powers(n);
  for (int i = 0; i < n; i++) cin >> names[i] >> powers[i];
  for (int i = 0; i < m; i++) {
    int power;
    cin >> power;
    int idx = lower_bound(powers.begin(), powers.end(), power) - powers.begin();
    cout << names[idx] << '\n';
  }
  return 0;
}