#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<int>> vecs;

long long cal(vector<int> &vec) {
    int start = vec[0];
    long long ret = 0, cnt = 1, idxSum = 0;
    for (int i = 1; i < vec.size(); i++) {
        ret += cnt * (vec[i] - start - 1) - idxSum;
        cout << cnt * (vec[i] - start - 1) - idxSum << '\n';
        idxSum += vec[i] - start + 1;
        cnt++;
    }
    return ret;
}

int main() {
    FastIO
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec[i] = {num, i};
    }
    sort(vec.begin(), vec.end());
    vector<int> same;
    int before = vec[0].first;
    same.push_back(vec[0].second);
    for (int i = 1; i < vec.size(); i++) {
        auto [num, pos] = vec[i];
        if (num == before) {
            same.push_back(pos);
        } else {
            if (same.size() > 1) vecs.push_back(same);
            same.clear();
            same.push_back(pos);
            before = num;
        }
    }
    if (!same.empty()) vecs.push_back(same);
    long long ans = 0;
    for (auto &idxs : vecs) {
        ans += cal(idxs);
    }
    cout << ans;
    return 0;
}