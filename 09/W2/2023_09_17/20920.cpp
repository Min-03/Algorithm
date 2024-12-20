#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<string> strs;
map<string, int> freq;

bool cmp(string& a, string& b) {
    if (freq[a] != freq[b]) return freq[a] > freq[b];
    if (a.length() != b.length()) return a.length() > b.length();
    return a < b;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    while (n--) {
        string str;
        cin >> str;
        if (str.length() >= m) {
            strs.push_back(str);
            freq[str]++;
        }
    }
    sort(strs.begin(), strs.end(), cmp);
    strs.erase(unique(strs.begin(), strs.end()), strs.end());
    for (const string &str : strs) {
        cout << str << '\n';
    }
    return 0;
}