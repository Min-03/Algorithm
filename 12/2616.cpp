#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int dp[50'000][4];
int sums[50'001], trains[50'000];

int main() {
  FASTIO
  int n, d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> trains[i];
    sums[i + 1] = sums[i] + trains[i];
  }
  cin >> d;
  for (int i = d - 1; i < n; i++) {
    int st = i - d + 1;
    for (int j : {1, 2, 3}) {
      int before = (st == 0) ? 0 : dp[st - 1][j - 1];
      dp[i][j] = max(dp[i - 1][j], before + sums[i + 1] - sums[st]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i][3]);
  cout << ans << '\n';
}