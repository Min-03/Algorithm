#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[1001];
    int increase[1001]; // i를 끝으로 하는 lis
    int decrease[1001]; // i를 시작으로 하는 lds
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        increase[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        decrease[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[j] < a[i]) { //a[j]가 더 뒤에 있음!
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
//        cout << increase[i] << " " << decrease[i] << '\n';
        int length = increase[i] + decrease[i] - 1;
        answer = max(answer, length);
    }
    cout << answer;
    return 0;
}