#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int input[100'000];
bool matched[100'000];

int main() {
    FastIO
    int n;
    cin >> n;
    string numStr;
    cin >> numStr;
    for (int i = 0; i < n; i++) {
        input[i] = numStr[i] - '0';
    }
    cin >> numStr;
    for (int i = 0; i < n; i++) {
        int num = numStr[i] - '0';
        matched[i] = (num == input[i]);
    }
    if (n == 2) {
        if (matched[0] && matched[1]) {
            cout << 0;
        } else if(!matched[0] && !matched[1]) {
            cout << 1;
        } else {
            cout << -1;
        }
        return 0;
    }

    bool temp[100'000];
    memcpy(temp, matched, sizeof(temp));
    int cnt = 0;
    //2 ~ n - 1번째 동전
    for (int i = 0; i < n - 2; i++) {
        if (!matched[i]) {
            cnt += 1;
            for (int j = 0; j < 3; j++) {
                matched[i + j] = !matched[i + j];
            }
        }
    }
    //n번째 동전
    if (!matched[n - 1]) {
        cnt += 1;
        matched[n - 2] = !matched[n - 2];
        matched[n - 1] = !matched[n - 1];
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!matched[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << cnt;
        return 0;
    }

    cnt = 1;
    //1번째 동전 뒤집음
    temp[0] = !temp[0];
    temp[1] = !temp[1];
    //2 ~ n - 1번째 동전
    for (int i = 0; i < n - 2; i++) {
        if (!temp[i]) {
            cnt += 1;
            for (int j = 0; j < 3; j++) {
                temp[i + j] = !temp[i + j];
            }
        }
    }
    //n번째 동전
    if (!temp[n - 1]) {
        cnt += 1;
        temp[n - 2] = !temp[n - 2];
        temp[n - 1] = !temp[n - 1];
    }

    for (int i = 0; i < n; i++) {
        if (!temp[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << cnt;
    return 0;
}