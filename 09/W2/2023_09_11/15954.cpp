#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    vector<int> dolls(n);
    for (int i = 0; i < n; i++) {
        cin >> dolls[i];
    }
    sort(dolls.begin(), dolls.end());
    double ans = 1e13;
    for (int i = 0; i + k - 1 < n; i++) {
        //i부터 i + k - 1까지 선택
        int sum = 0;
        for (int j = i; j <= i + k - 1; j++) {
            sum += dolls[j];
        }
        double avg = (double) sum / k;
        double bunsan = 0;
        for (int j = i; j <= i + k - 1; j++) {
            bunsan += (dolls[j] - avg) * (dolls[j] - avg);
        }
        ans = min(ans, bunsan);
        cout << i << ' ' << avg << ' ' << bunsan << '\n';
    }
    cout << fixed << setprecision(12) << sqrt(ans / k);
    return 0;
}