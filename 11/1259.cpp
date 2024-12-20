#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool isPalindrome(const string& s) {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) return false;
  }
  return true;
}

int main() {
  while (true) {
    string s;
    cin >> s;
    if (stoi(s) == 0) return 0;
    cout << (isPalindrome(s) ? "yes" : "no") << '\n';
  }
}