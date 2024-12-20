#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> calories(n);
    for (int i = 0; i < n; i++) {
        cin >> calories[i];
    }
    int total = c;
    int costs = a;
    double avg = (double) c / a;
    sort(calories.begin(), calories.end(), greater<int>());
    for (int calorie : calories) {
        if ((double) calorie / b <= avg) {
            break;
        }
        total += calorie;
        costs += b;
        avg = (double) total / costs;
    }
    cout << total / costs;
    return 0;
}