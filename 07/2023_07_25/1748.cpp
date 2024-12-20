#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int length = 0;
    int level = 1;
    while (pow(10,level) <= n) {
        length += level * (pow(10, level) - pow(10, level - 1));
        level += 1;
    }
    length += level * (n - pow(10, level - 1) + 1);
    cout << length;
}
