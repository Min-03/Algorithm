#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Jewel {
    int weight, value;
    Jewel(int weight, int value) : weight(weight), value(value) {};
    //무게 역순으로 정렬
    bool operator < (const Jewel other) const {
        return this -> weight > other.weight;
    }
};

int weights[300'000];

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    priority_queue<Jewel> jewels;
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        jewels.push({weight, value});
    }

    for (int i = 0; i < k; i++) {
        cin >> weights[i];
    }
    sort(weights, weights + k);

    long long ans = 0;
    priority_queue<int> values;
    for (int i = 0; i < k; i++) {
        while (!jewels.empty() && jewels.top().weight <= weights[i]) {
            values.push(jewels.top().value);
            jewels.pop();
        }
        if (!values.empty()) {
            ans += values.top();
            values.pop();
        }
    }
    cout << ans;
    return 0;
}