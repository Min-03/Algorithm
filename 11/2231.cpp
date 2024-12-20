#include<bits/stdc++.h>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++){
    int tot = i;
    int tmp = i;
    while (tmp) {
      tot += tmp % 10;
      tmp /= 10;
    }
    if (tot == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}