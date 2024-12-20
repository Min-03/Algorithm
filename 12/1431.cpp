#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int getNum(const string& s) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) ret += s[i] - '0';
    }
    return ret;
}

struct serial {
    string data;
    bool operator<(const serial& oth) const {
        if (data.length() != oth.data.length()) return data.length() < oth.data.length();
        int res = getNum(data) - getNum(oth.data);
        if (res != 0) return res < 0;
        return data < oth.data;
    }
};

int main() {
    FASTIO
    int n;
    cin >> n;
    vector<serial> serials;
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;
        serials.push_back({data});
    }
    sort(serials.begin(), serials.end());
    for (serial& serial : serials) cout << serial.data << '\n';
    return 0;
}