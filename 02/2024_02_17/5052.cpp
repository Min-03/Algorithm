#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

unordered_set<string> used;

bool check(string& str) {
    string temp = "";
    for (char ch : str) {
        temp += ch;
        if (used.find(temp) != used.end()) return false;
    }
    return true;
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        used.clear();
        int n;
        cin >> n;
        vector<string> nums(n);
        for (string &i : nums) cin >> i;
        sort(nums.begin(), nums.end(), [] (auto a, auto b) {
            return a.size() < b.size();
        });
        bool ok = true;
        for (string num : nums) {
            if (!check(num)) {
                ok = false;
                break;
            }
            used.insert(num);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}