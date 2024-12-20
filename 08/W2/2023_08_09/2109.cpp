#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Lectures {
    int day, pay;
    Lectures(int day, int pay) : day(day), pay(pay) {};
    //날짜가 느린 게 제일 위에 오도록 정렬
    bool operator < (const Lectures other) const {
        return this -> day < other.day;
    }
};

int main() {
    FastIO
    priority_queue<Lectures> pq;
    int n;
    cin >> n;
    int maxDay = -1;
    for (int i = 0; i < n; i++) {
        int day, pay;
        cin >> pay >> day;
        pq.push(Lectures(day, pay));
        maxDay = max(maxDay, day);
    }
    int ans = 0;
    priority_queue<int> pays;
    for (int i = maxDay; i >= 1; i--) {
        while (!pq.empty() && pq.top().day >= i) {
            pays.push(pq.top().pay);
            pq.pop();
        }
        if (!pays.empty()) {
            ans += pays.top();
            pays.pop();
        }
    }
    cout << ans;
    return 0;
}