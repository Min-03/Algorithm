#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<long long, long long> pll;

struct planet {
    int num, x, y, z;
};

vector<planet> planets;
vector<pll> graph[100'001];
long long dists[100'001];
bool visited[100'001];

long long prim() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dists[1] = 0;
    pq.push({dists[1], 1});
    visited[1] = true;
    long long ret = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] != w) continue;
        visited[curr] = true;
        ret += dists[curr];
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
    planets.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planet p = {i + 1, x, y, z};
        planets[i] = p;
    }

    sort(planets.begin(), planets.end(), [](planet a, planet b) {
        return a.x < b.x;
    });
    for (int i = 1; i < n; i++) {
        planet p1 = planets[i - 1];
        planet p2 = planets[i];
        long long dist = abs(p1.x - p2.x);
        graph[p1.num].push_back({p2.num, dist});
        graph[p2.num].push_back({p1.num, dist});
    }

    sort(planets.begin(), planets.end(), [](planet a, planet b) {
        return a.y < b.y;
    });
    for (int i = 1; i < n; i++) {
        planet p1 = planets[i - 1];
        planet p2 = planets[i];
        long long dist = abs(p1.y - p2.y);
        graph[p1.num].push_back({p2.num, dist});
        graph[p2.num].push_back({p1.num, dist});
    }

    sort(planets.begin(), planets.end(), [](planet a, planet b) {
        return a.z < b.z;
    });
    for (int i = 1; i < n; i++) {
        planet p1 = planets[i - 1];
        planet p2 = planets[i];
        long long dist = abs(p1.z - p2.z);
        graph[p1.num].push_back({p2.num, dist});
        graph[p2.num].push_back({p1.num, dist});
    }

    fill(dists, dists + 100'001, 1e10);
    cout << prim();
    return 0;
}