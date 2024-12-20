#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll cnts[200'001]; //소인수분해할 때 추가로 필요한 숫자

void factorization(int x) {
    map<int, int> primes;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            if (primes.find(i) == primes.end()) primes[i] = 1;
            else primes[i]++;
            x /= i;
        }
    }
    if (x > 1) primes[x]++;
    int tot = 1;
    for (auto [num, cnt] : primes) {
        if (cnt & 1) tot *= num;
    }
    if (tot == 1) cnts[0]++;
    else cnts[tot]++;
}

int main() {
    FastIO
    ll n, zeros = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        if (num == 0) zeros++;
        else factorization(num);
    }
    //0과 0 아닌 수
    ans += zeros * (n - zeros);
    //0들끼리
    ans += zeros * (zeros - 1) / 2;
    //0 아닌 수들끼리
    for (int i = 0; i <= 200'000; i++) {
        ans += cnts[i] * (cnts[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}