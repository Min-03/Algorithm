#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y, num;
    Point (int X, int Y, int NUM) : x(X), y(Y), num(NUM) {};
    Point (Point &other) {
        x = other.x;
        y = other.y;
        num = other.num;
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, ans = 0;


void go(int graph[][20], int cnt) {
    if (cnt > 5) return;
    for (int k = 0; k < 4; k++) {
        int temp[20][20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = graph[i][j];
            }
        }

        int xStart, yStart;
        //왼쪽, 위쪽으로 이동
        if (dx[k] + dy[k] == 1) {
            xStart = (dx[k] == 0 ? 0 : -1);
            yStart = (dx[k] == 0 ? -1 : 0);
            Point curr(0, 0, temp[0][0]);
            Point before(xStart, yStart, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    curr.num = temp[curr.x][curr.y];
                    temp[curr.x][curr.y] = 0;
                    if (curr.num == 0) {
                        //before 유지
                    } else if (curr.num == before.num) {
                        //before 위치에 합치기
                        temp[before.x][before.y] = 2 * before.num;
                        before.num = -1;
                        ans = max(ans, curr.num * 2);
                    } else {
                        //before 다음 칸에 놓기 -> before 변경
                        ans = max(ans, curr.num);
                        if (xStart == -1) {
                            temp[before.x + 1][before.y] = curr.num;
                            before.x += 1;
                            before.num = curr.num;
                        } else {
                            temp[before.x][before.y + 1] = curr.num;
                            before.y += 1;
                            before.num = curr.num;
                        }
                    }
                    if (xStart == -1) {
                        curr.x += 1;
                    } else {
                        curr.y += 1;
                    }
                }

                if (xStart == -1) {
                    before.x = -1;
                    before.y += 1;
                    before.num = -1;
                    curr.x = 0;
                    curr.y += 1;
                } else {
                    before.x += 1;
                    before.y = -1;
                    before.num = -1;
                    curr.x += 1;
                    curr.y = 0;
                }
            }
            //오른쪽, 아래쪽으로 이동
        } else {
            xStart = (dx[k] == 0 ? n - 1 : n);
            yStart = (dx[k] == 0 ? n : n - 1);
            Point curr(n - 1, n - 1, temp[n - 1][n - 1]);
            Point before(xStart, yStart, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    curr.num = temp[curr.x][curr.y];
                    temp[curr.x][curr.y] = 0;
                    if (curr.num == 0) {
                        //before 유지
                    } else if (curr.num == before.num) {
                        //before 위치에 합치기
                        temp[before.x][before.y] = 2 * before.num;
                        before.num = -1;
                        ans = max(ans, curr.num * 2);
                    } else {
                        //before 다음 칸에 놓기 -> before 변경
                        ans = max(ans, curr.num);
                        if (xStart == n) {
                            temp[before.x - 1][before.y] = curr.num;
                            before.x -= 1;
                            before.num = curr.num;
                        } else {
                            temp[before.x][before.y - 1] = curr.num;
                            before.y -= 1;
                            before.num = curr.num;
                        }
                    }
                    if (xStart == n) {
                        curr.x -= 1;
                    } else {
                        curr.y -= 1;
                    }
                }

                if (xStart == n) {
                    before.x = n;
                    before.y -= 1;
                    before.num = -1;
                    curr.x = n - 1;
                    curr.y -= 1;
                } else {
                    before.x -= 1;
                    before.y = n;
                    before.num = -1;
                    curr.x -= 1;
                    curr.y = n - 1;
                }
            }
        }
        go(temp, cnt + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int graph[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    go(graph, 1);
    cout << ans;
    return 0;
}