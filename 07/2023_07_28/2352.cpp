#include <bits/stdc++.h>
using namespace std;
int lis[40'000];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int curr;
    cin >> curr;
    lis[0] = curr;
    int ptr = 1;
    while (n-- > 1) {
        cin >> curr;
        if (curr > lis[ptr - 1]) {
            lis[ptr] = curr;
            ptr++;
        } else {
            int pos = lower_bound(lis, lis + ptr, curr) - lis;
//            cout << pos << ' ' << curr << '\n';
            lis[pos] = curr;
        }
    }
    cout << ptr;
    return 0;
}