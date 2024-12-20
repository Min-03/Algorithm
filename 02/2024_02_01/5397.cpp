#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        deque<char> left, right;
        string str;
        cin >> str;
        for (char ch : str) {
            if (ch == '-') {
                if (!left.empty()) left.pop_back();
            } else if (ch == '<') {
                if (left.empty()) continue;
                right.push_front(left.back());
                left.pop_back();
            } else if (ch == '>') {
                if (right.empty()) continue;
                left.push_back(right.front());
                right.pop_front();
            } else {
                left.push_back(ch);
            }
        }
        while (!left.empty()) {
            cout << left.front(); left.pop_front();
        }
        while (!right.empty()) {
            cout << right.front(); right.pop_front();
        }
        cout << '\n';
    }
    return 0;
}