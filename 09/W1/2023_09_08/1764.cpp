#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<string, bool> notHear, notSeen;
vector<string> people;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    people.resize(n + m);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        people[i] = str;
        notHear[str] = true;
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        people[n + i] = str;
        notSeen[str] = true;
    }
    sort(people.begin(), people.end());
    people.erase(unique(people.begin(), people.end()), people.end());
    int ans = 0;
    for (const string &person : people) {
        if (notSeen[person] && notHear[person]) {
            ans++;
        }
    }

    cout << ans << '\n';
    for (const string &person : people) {
        if (notSeen[person] && notHear[person]) {
            cout << person << '\n';
        }
    }
    return 0;
}