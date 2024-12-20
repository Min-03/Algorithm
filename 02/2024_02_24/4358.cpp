#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<string, int> cnts;

int main() {
    FastIO
    int tot = 0;
    string name;
    while (getline(cin, name)) {
        if (cnts.find(name) != cnts.end()) cnts[name]++;
        else cnts[name] = 1;
        tot++;
    }
    for (auto [str, cnt] : cnts) {
        printf("%s %.4f\n", str.c_str(), cnt / (double) tot * 100);
    }
    return 0;
}