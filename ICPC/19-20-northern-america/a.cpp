#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n;
ll T[N];
struct P {
    ll to, w;
};
vector<P> G[N];
ll dep[N], depsum;
ll Tsum[N];
ll res;
ll sumTD;
ll chlsz[N];

ll dfs(int v, int p) {
    int sz = 1;
    Tsum[v] = T[v];
    for (auto e: G[v]) {
        if (e.to == p) continue;
        dep[e.to] = dep[v] + e.w;
        sz += dfs(e.to, v);
        depsum += dep[e.to];
        Tsum[v] += Tsum[e.to];
    }
    sumTD += dep[v] * T[v];
    return chlsz[v] = sz;
}

vector<pair<ll, ll>> vec;
void calc(int v, int p, ll dsum, ll sTD, ll cum_sz, ll cum_T) {
    res += T[v] * dsum + sTD;
    vec.emplace_back(v, T[v] * dsum + sTD);
    for (auto e: G[v]) {
        int u = e.to;
        if (u == p) continue;
    
        ll diff = (chlsz[v] - chlsz[u] + cum_sz);
        // depsum += diff - chlsz[u];
        ll diff2 = Tsum[v] - Tsum[u] + cum_T;
        // sumTD += diff2 - Tsum[u];
        calc(u, v, dsum + (diff - chlsz[u])*e.w, sTD + (diff2 - Tsum[u])*e.w, diff, diff2);
    }
}

int main() {
    io;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> T[i];
    for (int i=1; i<n; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(P{v, w});
        G[v].push_back(P{u, w});
    }
    dfs(1, 0);
    calc(1, 0, depsum, sumTD, 0, 0);
    // cout << res << '\n';
    sort(vec.begin(), vec.end());
    for (auto x: vec) {
        cout << x.second << '\n';
    }
    return 0;
}