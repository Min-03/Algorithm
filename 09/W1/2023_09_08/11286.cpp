#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        } else {
            return abs(a) > abs(b);
        }
    }
};

int main() {
    FastIO
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    while (n--) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }
    return 0;
}