#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string voca[] = {"cow", "dog", "sea", "rug", "row", "mob", "box", "tab", "bar", "ear", "tar"};
    sort(voca, voca + 11);
    for (string &str : voca) {
        cout << str << '\n';
    }
    return 0;
}