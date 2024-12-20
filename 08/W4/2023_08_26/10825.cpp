#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Student {
    int kor, eng, math;
    string name;
    bool operator < (const Student& other) const {
        if (kor != other.kor) return kor > other.kor;
        if (eng != other.eng) return eng < other.eng;
        if (math != other.math) return math > other.math;
        return name < other.name;
    }
};

Student students[100'000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
    }
    sort(students, students + n);
    for (int i = 0; i < n; i++) {
        auto student = students[i];
        cout << student.name << '\n';
    }
    return 0;
}