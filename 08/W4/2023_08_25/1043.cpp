#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool know[51];
bool spread[50]; // i번째 파티의 사람들이 사실을 알았는지
vector<int> party[50];

int main() {
    FastIO
    int n, m, knowNum;
    cin >> n >> m >> knowNum;
    for (int i = 0; i < knowNum; i++) {
        int person;
        cin >> person;
        know[person] = true;
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        party[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> party[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < m; i++) {
            if (spread[i]) continue;
            bool ok = true;
            for (int person : party[i]) {
                if (know[person]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                for (int person : party[i]) {
                    know[person] = true;
                }
                spread[i] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (!spread[i]) cnt++;
    }
    cout << cnt;
    return 0;
}