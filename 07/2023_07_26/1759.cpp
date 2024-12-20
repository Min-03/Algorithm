#include <bits/stdc++.h>
using namespace std;
char choose[15];
char chars[15];
const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
int l, c;
void go(int currIndex, int chooseNum) {
    if (chooseNum == l) {
        int vowel = 0, consonant = 0;
        for (int i = 0; i < chooseNum; i++) {
            if (find(vowels, vowels + 5, choose[i]) != vowels + 5) {
                vowel += 1;
            } else {
                consonant += 1;
            }
        }
        if (vowel < 1 || consonant < 2) return;
        for (int i = 0; i < chooseNum; i++) {
            cout << choose[i];
        }
        cout << '\n';
        return;
    } else if (currIndex >= c) {
        return;
    }
    choose[chooseNum] = chars[currIndex];
    go(currIndex + 1, chooseNum + 1);
    go(currIndex + 1, chooseNum );
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> chars[i];
    }
    sort(chars, chars + c);
    go(0, 0);
    return 0;
}