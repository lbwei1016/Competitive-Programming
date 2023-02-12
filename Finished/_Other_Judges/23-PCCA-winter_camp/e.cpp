#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int N = 1e5 + 5;
struct P {
    ll v, w;
    bool operator<(const P &p) const {
        return w > p.w;
    }
};

int n, m; 
vector<P> G[N];
vector<ll> a(N);

ll dij(int st, int ed) {
    priority_queue<P> pq;
    vector<ll> dis(n, INF);
    pq.push(P{st, 0});
    dis[st] = 0;
    ll mn = a[0];
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (p.w > dis[p.v]) continue;
        for (auto e: G[p.v]) {
            bool update = false;
            if (dis[e.v] > dis[p.v] + e.w) {
                dis[e.v] = dis[p.v] + e.w;
                update = true;
            }
            if (dis[e.v] > mn + a[e.v]) {
                dis[e.v] = mn + a[e.v];
                update = true;
            }
            if (update) pq.push(P{e.v, dis[e.v]});
            mn = min(mn, dis[e.v] + a[e.v]);
        }
    }
    return dis[ed];
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<n; ++i) cin >> a[i];
    vector<bool> vis(n, false);
    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        w = min((ll)w, a[u] + a[v]);
        if (u == 0) vis[v] = true;
        if (v == 0) vis[u] = true;
        G[u].push_back(P{v, w});
        G[v].push_back(P{u, w});
    }

    for (int i=1; i<n; ++i) {
        if (vis[i]) continue;
        G[0].push_back(P{i, a[0] + a[i]});
        G[i].push_back(P{0, a[0] + a[i]});
    }

    cout << dij(0, n - 1);

    return 0;
}
/*
4 4
6 2 1 2
1 2 1
2 3 6
1 3 8
3 4 2
(5)
*/