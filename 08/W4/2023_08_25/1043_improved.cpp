#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[51];
bool know[51];
vector<int> party[50];

int find_set(int a) {
    if (parents[a] == a) return a;
    else return parents[a] = find_set(parents[a]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (know[b]) swap(a, b);
    parents[b] = a;
}

int main() {
    FastIO
    int n, m, knowNum;
    cin >> n >> m >> knowNum;
    for (int i = 0; i < knowNum; i++) {
        int person;
        cin >> person;
        know[person] = true;
    }
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        party[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> party[i][j];
            if (j >= 1) union_set(party[i][j - 1], party[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        bool ok = true;
        for (int person: party[i]) {
            if (know[find_set(person)]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}