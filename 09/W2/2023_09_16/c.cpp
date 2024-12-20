#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnts[30];

int main() {
    FastIO
    int n, d, m;
    string str;
    cin >> n >> str >> d >> m;
    int cnt = 0, energy = 0;
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'h' || ch == 'y' || ch == 'u') {
            cnts[ch - 'a']++;
            energy += min(cnt * d, d + m);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt != 0) energy += min(cnt * d, d + m);
    cout << (energy == 0 ? "Nalmeok" : to_string(energy)) << '\n';
    int ans = min({cnts['h' - 'a'], cnts['y' - 'a'], cnts['u' - 'a']});
    cout << (ans == 0 ? "I love HanYang University" : to_string(ans));
    return 0;
}