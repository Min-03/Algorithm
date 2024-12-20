#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<string, int> m;
int parents[200'001], ranks[200'001], cnts[200'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranks[a] > ranks[b]) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
    cnts[b] += cnts[a];
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int f, cnt = 0;
        cin >> f;
        for (int i = 1; i <= 200'000; i++) {
            ranks[i] = 0;
            parents[i] = i;
            cnts[i] = 1;
        }
        while (f--) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s1) == m.end()) m[s1] = ++cnt;
            if (m.find(s2) == m.end()) m[s2] = ++cnt;
            int n1 = m[s1], n2 = m[s2];
            union_set(n1, n2);
            cout << cnts[find_set(n1)] << '\n';
        }
    }
    return 0;
}