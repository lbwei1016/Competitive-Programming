#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n;
vector<int> G[N];

const int sz = 18;
vector<ll> dep(N);
vector<int> up[N];

ll res;

void precalc(int v, int p){
    up[v].resize(sz + 1);
    dep[v] = dep[p] + 1;
    up[v][0] = p;
    for(int i = 1; i <= sz; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int u: G[v]){
        if(u == p) continue;
        precalc(u, v);
    }
}

int LCA(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    for(int cur = sz; cur >= 0; --cur){
        if (dep[u] - (1 << cur) >= dep[v]) {
            u = up[u][cur];
        }
    }

    // Now dep[u] == dep[v]
    // jump upward together
    for(int cur = sz; cur >= 0; --cur){
        if (up[u][cur] != up[v][cur]) {
            u = up[u][cur];
            v = up[v][cur];
        }
    }
    return u == v ? u : up[u][0];
}

void calc(int v) {
    int k = 2;
    ll var = 0; 
    while (v * k <= n) {
        int u = v * k;
        int lca = LCA(v, u);
        if (lca == 1) {
            var = dep[v] + dep[u] + 1;
        }
        else {
            var = dep[v] + dep[u] - dep[lca] * 2 + 1;
        }
        res += var;
        // printf("%d -> %d: %d\n", v, u, var);
        k++;
    }
    // return k > 2;
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    up[0].resize(sz);
    dep[0] = -1;
    precalc(1, 0);

    for (int i=2; i<=n; ++i) {
        calc(i);
        res += dep[i] + 1;
        // if (!calc(i)) break;
    }
    cout << res << '\n';
    return 0;
}