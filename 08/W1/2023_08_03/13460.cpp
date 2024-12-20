#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char graph[10][10];
int n, m, ans = -1;

bool redFirst(pii red, pii blue, string dir) {
    if (dir == "up") {
        return red.first < blue.first;
    } else if (dir == "down") {
        return red.first > blue.first;
    } else if (dir == "left") {
        return red.second < blue.second;
    } else {
        return red.second > blue.second;
    }
}

bool inHole(pii ball) {
    return graph[ball.first][ball.second] == 'O';
}

bool check(char ch) {
    return ch != '#' && ch != 'R' && ch != 'B';
}

//만약 hole에 들어갔으면 (-1, -1) 반환
pii moveBall(pii ball, string dir) {
    if (dir == "up") {
        while (check(graph[ball.first - 1][ball.second])) {
            ball.first -= 1;
            if (inHole(ball)) {
                return make_pair(-1, -1);
            }
        }
    } else if (dir == "down") {
        while (check(graph[ball.first + 1][ball.second])) {
            ball.first += 1;
            if (inHole(ball)) {
                return make_pair(-1, -1);
            }
        }
    } else if (dir == "left") {
        while (check(graph[ball.first][ball.second - 1])) {
            ball.second -= 1;
            if (inHole(ball)) {
                return make_pair(-1, -1);
            }
        }
    } else {
        while (check(graph[ball.first][ball.second + 1])) {
            ball.second += 1;
            if (inHole(ball)) {
                return make_pair(-1, -1);
            }
        }
    }
    return ball;
}

void setGraph(pii curr, pii res, bool closed, char color) {
    if (!closed) {
        graph[curr.first][curr.second] = '.';
        graph[res.first][res.second] = color;
    } else {
        graph[curr.first][curr.second] = color;
        graph[res.first][res.second] = '.';
    }
}

void go(pii red, pii blue, int cnt, string dir) {
    if (cnt > 10 || (ans != -1 && cnt >= ans)) return;
    pii resR, resB;
    bool success = false;
    if (redFirst(red, blue, dir)) {
        resR = moveBall(red, dir);
        if (resR.first != -1) {
            setGraph(red, resR, false, 'R');
        } else {
            graph[red.first][red.second] = '.';
            success = true;
        }
        resB = moveBall(blue, dir);
        if (resB.first != -1) {
            setGraph(blue, resB, false, 'B');
        } else {
            if (resR.first != -1) setGraph(red, resR, true, 'R');
            return;
        }
    } else {
        resB = moveBall(blue, dir);
        if (resB.first != -1) {
            setGraph(blue, resB, false, 'B');
        } else {
            return;
        }
        resR = moveBall(red, dir);
        if (resR.first != -1) {
            setGraph(red, resR, false, 'R');
        } else {
            success = true;
        }
    }
    if (success) {
        graph[red.first][red.second] = 'R';
        setGraph(blue, resB, true, 'B');
        if (ans == -1) {
            ans = cnt;
        } else {
            ans = min(ans, cnt);
        }
        return;
    }

    go(resR, resB, cnt + 1, "up");
    go(resR, resB, cnt + 1, "down");
    go(resR, resB, cnt + 1, "left");
    go(resR, resB, cnt + 1, "right");
    setGraph(red, resR, true, 'R');
    setGraph(blue, resB, true, 'B');
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    pii blue, red;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
            } else if (graph[i][j] == 'R') {
                red.first = i;
                red.second = j;
            }
        }
    }
    go(red, blue, 1, "up");
    go(red, blue, 1, "down");
    go(red, blue, 1, "left");
    go(red, blue, 1, "right");
    cout << ans;
    return 0;
}
