#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int h, w;
int sx, sy;
ll G[N][N];
bool vis[N][N];

struct P {
    int x, y;
    ll dep;
    bool operator < (const P p) const {
        return dep > p.dep;
    }
};

void bfs() {
    priority_queue<P> pq;
    pq.push(P{sx, sy, G[sx][sy]});
    vis[sx][sy] = true;

    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        G[p.x][p.y] = p.dep;
        for (int i=0; i<8; ++i) {
            P to = P{p.x + dx[i], p.y + dy[i]};
            if (to.x <= 0 || to.x > h || to.y <= 0 || to.y > w) continue;
            if (vis[to.x][to.y]) continue;
            vis[to.x][to.y] = true;
            to.dep = max(G[to.x][to.y], p.dep);
            pq.push(to);
        }
    }
}

int main() {
    io;
    cin >> h >> w;
    for (int i=1; i<=h; ++i) {
        for (int j=1; j<=w; ++j) {
            cin >> G[i][j];
        }
    }
    cin >> sx >> sy;
    bfs();

    ll res = 0;
    for (int i=1; i<=h; ++i) {
        for (int j=1; j<=w; ++j) {
            if (G[i][j] < 0)
                res += G[i][j];
        }
    }

    cout << -res << '\n';

    return 0;
}