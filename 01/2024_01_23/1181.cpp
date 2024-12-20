#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct word {
    string str;
    bool operator ==(const word& other) const {
        return str == other.str;
    }
    bool operator <(const word& other) const {
        if (str.size() != other.str.size()) return str.size() < other.str.size();
        else return str < other.str;
    }
};

int main() {
    FastIO
    int n;
    cin >> n;
    vector<word> words(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        word w = {str};
        words[i] = w;
    }
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
    for (auto [word] : words) cout << word << '\n';
    return 0;
}