#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
  FASTIO
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x,y});
  }

  for (int i = 0; i < n; i++) {
    auto [x1, y1] = v[i];
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      auto [x2, y2] = v[j];
      if (x1 < x2 && y1 < y2) cnt++;
    }
    cout << cnt + 1 << ' ';
  }
  return 0;
}