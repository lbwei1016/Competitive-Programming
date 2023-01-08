#include <bits/stdc++.h>
// #define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int N = 1e5+5, M = 1e6+5;
const ll INF = 1e16;
struct P {
    ll fr, to, w;
};
int n, m;
vector<ll> G[N], pre(N);
vector<bool> vis(M), used(N);
vector<P> edge(M);
vector<ll> dis(N);

void dij(int st) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dis.begin(), dis.end(), INF);
    fill(pre.begin(), pre.end(), -1);
    // fill(used.begin(), used.end(), 0);
    dis[st] = 0;
    pq.push(pll(0, st));

    while (pq.size()) {
        pll p = pq.top(); pq.pop();
        int v = p.second;
        if (dis[v] < p.first) continue;
        // used[v] = true;

        for (auto id: G[v]) {
            if (vis[id]) continue;
            auto e = edge[id];
            int to;
            if (e.to == v) to = e.fr;
            else to = e.to;
            if (dis[to] > dis[v] + e.w) {
                dis[to] = dis[v] + e.w;
                pre[to] = id;
                pq.push(pll(dis[to], to));
            }
        }
    }
}

int main() {
    // io;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    fill(vis.begin(), vis.end(), 0);
    for (int i=0; i<m; ++i) {
        ll u, v, d;
        // cin >> u >> v >> d;
        scanf("%lld %lld %lld", &u, &v, &d);
        G[u].push_back(i);
        G[v].push_back(i);
        edge[i] = P{u, v, d};
    }

    dij(1);
    // if (dis[0] == INF) {
    //     // cout << "impossible\n";
    //     puts("impossible");
    //     return 0;
    // }

    for (int i=0; i<n; ++i) {
        if (pre[i] < 0) continue;
        vis[pre[i]] = true;
    }

    dij(0);
    if (dis[1] == INF) {
        // cout << "impossible\n";
        puts("impossible");
        return 0;
    }

    vector<ll> route;
    for (int i=1; i!=0;) {
        route.push_back(i);
        auto e = edge[pre[i]];
        if (i != e.fr) i = e.fr;
        else i = e.to;
    }

    // cout << route.size()+1  << " 0 ";
    printf("%lu 0", route.size()+1);
    while (route.size()) {
        // cout << route.back() << ' ';
        printf(" %lld", route.back());
        route.pop_back();
    }
    // cout << '\n';
    puts("");
    return 0;
}
/*
4 5
0 1 800
1 3 500
2 3 300
2 0 1000
0 3 1100
*/