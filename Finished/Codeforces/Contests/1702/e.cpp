#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct E {
    int to, id;
};

int tme;
vector<int> in;

int dfs(int at, int pree, vector<vector<E>> &G) {
    in[at] = ++tme;
    for (auto to: G[at]) {
        if (to.id == pree) continue;
        if (in[to.to] > 0) return in[at] - in[to.to] + 1;
        return dfs(to.to, to.id, G);
    }
    return 0;
}

bool solve() {
    int n; cin >> n;
    vector<vector<E>> G(n+1, vector<E>());
    tme = 0;
    in.clear(); in.resize(n+1, 0);

    map<int, int> mp;
    bool good = true;
    for (int i=0, cnt=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b) good = false;
        G[a].push_back(E{b, cnt});
        G[b].push_back(E{a, cnt});
        mp[a]++; mp[b]++;
        ++cnt;
    }

    for (auto p: mp) {
        if (p.second != 2) {
            good = false;
            break;
        }
    }
    if (!good) return false;

    for (int i=1; i<=n; ++i) {
        int cyc;
        if (in[i] == 0)
            cyc = dfs(i, -1, G);
        if (cyc & 1) return false;
    }
    return true;
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        bool ans = solve();
        if (ans) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}