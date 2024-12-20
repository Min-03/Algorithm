#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool visited[501][2001];

void sortThree(int& a, int& b, int& c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

bool bfs(int a, int b, int c) {
    queue<tuple<int, int, int>> q;
    visited[a][b] = true;
    q.emplace(a, b, c);
    while (!q.empty()) {
        tie(a, b, c) = q.front();
        q.pop();
        if (a == c) {
            return true;
        }
        int res1, res2, res3;
        //a와 b를 고름
        res1 = 2 * a;
        res2 = b - a;
        res3 = c;
        sortThree(res1, res2, res3);
        if (!visited[res1][res2]) {
            visited[res1][res2] = true;
            q.emplace(res1, res2, res3);
        }
        //b와 c를 고름
        res1 = 2 * b;
        res2 = c - b;
        res3 = a;
        sortThree(res1, res2, res3);
        if (!visited[res1][res2]) {
            visited[res1][res2] = true;
            q.emplace(res1, res2, res3);
        }
        //a와 c를 고름
        res1 = 2 * a;
        res2 = c - a;
        res3 = b;
        sortThree(res1, res2, res3);
        if (!visited[res1][res2]) {
            visited[res1][res2] = true;
            q.emplace(res1, res2, res3);
        }
    }
    return false;
}

int main() {
    FastIO
    int a, b, c;
    cin >> a >> b >> c;
    sortThree(a, b, c);
    cout << (bfs(a, b, c) ? 1 : 0);
    return 0;
}
