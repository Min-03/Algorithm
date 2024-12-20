#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int getMode(vector<int> &v) {
  int hi = 0, ret;
  bool passed = false;
  map<int, int> cnts;
  for (int n : v) cnts[n]++;
  for (auto [n, cnt] : cnts) {
    if (cnt > hi) {
      ret = n;
      hi = cnt;
      passed = false;
    } else if (cnt == hi && !passed) {
      ret = n;
      passed = true;
    }
  }
  return ret;
}

int main(){
  FASTIO
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int mean = round(accumulate(v.begin(), v.end(), 0.0) / n);
  cout << (mean == 0 ? 0 : mean) << '\n';
  cout << v[n / 2] << '\n';
  cout << getMode(v) << '\n';
  cout << v[n - 1] - v[0]<< '\n';
  return 0;
}