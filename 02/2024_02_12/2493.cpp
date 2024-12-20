#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

stack<pair<int, int>> s;
int receive[500'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        while (!s.empty() && s.top().first < num) s.pop();
        if (!s.empty()) receive[i] = s.top().second;
        s.push({num, i});
    }
    for (int i = 1; i <= n; i++) cout << receive[i] << ' ';
    return 0;
}