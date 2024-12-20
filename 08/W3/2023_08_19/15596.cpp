#include <bits/stdc++.h>

long long sum(std::vector<int> &a) {
    return std::accumulate(a.begin(), a.end(), 0LL);
}

const int num = 2 * 1e9;

int main() {
    std::vector<int> test = {num, num};
    std::cout << sum(test);
    return 0;
}