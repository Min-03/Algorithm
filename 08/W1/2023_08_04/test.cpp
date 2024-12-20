#include <bits/stdc++.h>
using namespace std;

vector<string> split(string sentence, char delimiter) {
    vector<string> res;
    string str = "";
    for (char ch : sentence) {
        if (ch != delimiter) {
            str += ch;
        } else {
            res.push_back(str);
            str = "";
        }
    }
    if (str != "") res.push_back(str);
    return res;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str = "ab,aa,ba,asdf,fdsf,s";
    string from = "a";
    string to = "CCC";
    str.replace(str.find(from), from.length(), to);
//    str = regex_replace(str, regex(from), to);
    cout << str;
    return 0;
}