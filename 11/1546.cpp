#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<double> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    double hi = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < n; i++) {
        scores[i] = scores[i] / hi * 100;
    }
    printf("%.10lf", accumulate(scores.begin(), scores.end(), 0.0) / n);
    return 0;
}