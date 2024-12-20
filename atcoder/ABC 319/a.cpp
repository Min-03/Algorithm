#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    map<string, int> rates;
    vector<string> names = {"tourist", "ksun48", "Benq", "Um_nik", "apiad", "Stonefeang", "ecnerwala", "mnbvmar", "newbiedmy", "semiexp"};
    vector<int> scores = {3858, 3679, 3658, 3648, 3638, 3630, 3613, 3555, 3516, 3481};
    for (int i = 0; i < 10; i++) {
        rates.insert({names[i], scores[i]});
    }
    string name;
    cin >> name;
    cout << rates[name];
    return 0;
}