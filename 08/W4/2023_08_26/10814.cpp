#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<tuple<int, int, string>> people(n);
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        people[i] = {age, i, name};
    }
    sort(people.begin(), people.end());
    for (auto [age, dummy, name] : people) {
        cout << age << ' ' << name << '\n';
    }
    return 0;
}