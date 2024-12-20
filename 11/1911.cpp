#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int main() {
  ll n, l, end = -1, ans = 0;
  cin >> n >> l;
  vector<pair<ll, ll>> pools;
  for (int i = 0; i < n; i++) {
    ll s, e;
    cin >> s >> e;
    pools.push_back({s, e});
  }
  sort(pools.begin(), pools.end());
  for (auto [s, e] : pools) {
    ll start = max(s, end);
    if (start >= e) continue;
    ll addNum = (e - start + l - 1) / l;
    ans += addNum;
    end = start + addNum * l;
  }
  cout << ans;
}