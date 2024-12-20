#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<double, int> pdi;
const double eps = 1e-6;

vector<pair<int, double>> graph[101];
pair<double, double> pos[101];
double dists[101];
bool visited[101];

double getDist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double prim() {
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    dists[1] = 0;
    pq.push({dists[1], 1});
    double ret = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (abs(dists[curr] - w) > eps) continue;
        ret += w;
        visited[curr] = true;
        for (auto [next, nw] : graph[curr]) {
            if (nw < dists[next] && !visited[next]) {
                dists[next] = nw;
                pq.push({nw, next});
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            auto [x1, y1] = pos[i];
            auto [x2, y2] = pos[j];
            double dist = getDist(x1, y1, x2, y2);
            graph[i].push_back({j, dist});
            graph[j].push_back({i, dist});
        }
        dists[i] = 1e6;
    }
    printf("%.8f", prim());
    return 0;
}