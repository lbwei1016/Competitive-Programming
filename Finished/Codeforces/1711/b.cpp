#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n+1), deg(n+1);
    vector<pair<int, int>> edge(m+1);
    for (int i=1; i<=n; ++i) cin >> A[i];
    for (int i=1; i<=m; ++i) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        edge[i] = {u, v};
    }

    if (m % 2 == 0) return 0;
    int mn = 2e9;
    for (int i=1; i<=n; ++i) {
        if (deg[i] & 1) mn = min(mn, A[i]);
    }
    for (int i=1; i<=m; ++i) {
        auto e = edge[i];
        mn = min(mn, A[e.first] + A[e.second]);
    }
    return mn;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve() << '\n';
    }
    return 0;
}