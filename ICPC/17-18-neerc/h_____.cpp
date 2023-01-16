#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
struct P {
    int r;
    vector<int> chl;
    bool operator<(P &p) const {
        return chl.size() > p.chl.size();
    }
};
vector<int> G[N];

void dfs(int u, int p, int root, vector<bool> &chosen, vector<int> &vac) {
    if (!chosen[u]) vac.push_back(u);
    for (auto v: G[u]) {
        if (v == p) continue;
        dfs(v, u, root, chosen, vac);
    }
    return;
}

int main() {
    // io;
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    int n; cin >> n;
    vector<int> root, par(n + 1), deg(n + 1);
    root.push_back(1);
    for (int i=2; i<=n; ++i) {
        int p; cin >> p;
        par[i] = p;
        if (p == 0) root.push_back(i);
        else {
            deg[p]++;
            G[p].push_back(i);
        }
    }

    queue<int> que;
    for (int i=1; i<=n; ++i) {
        if (deg[i] == 0) que.push(i);
    }

    int res = 0;
    vector<bool> chosen(n + 1);
    while (que.size()) {
        int u = que.front(); que.pop();
        int p = par[u];
        if (p == 0) continue;
        if (!chosen[u] && !chosen[p]) {
            chosen[u] = chosen[p] = true;
            res++;
        }
        if (--deg[p] == 0) que.push(p);
    }

    vector<P> vacant;
    vacant.reserve(root.size() + 1);
    vector<int> vac1;
    dfs(1, 0, 1, chosen, vac1);
    for (auto r: root) {
        if (r == 1) continue;
        vector<int> vac;
        dfs(r, 0, r, chosen, vac);
        if (chosen[r]) {
            for (auto x: vac) {
                vac1.push_back(x);
            }
            par[r] = 1;
        }
        else {
            vacant.push_back(P{r, vac});
        }
    }
    if (vac1.size())
        vacant.push_back(P{1, vac1});
    sort(vacant.begin(), vacant.end());

    // cout << "before vacant: " << res << '\n';

    auto &p = vacant.front();
    for (int i=1; i<vacant.size(); ++i) {
        auto &x = vacant[i];
        if (x.r == 1) continue;
        if (p.chl.empty()) {
            par[x.r] = 1;
            continue;
        }
        res++;
        chosen[p.chl.back()] = chosen[x.r] = true;
        par[x.r] = p.chl.back(); p.chl.pop_back();
        for (auto ele: x.chl) {
            if (ele == x.r) continue;
            p.chl.push_back(ele);
        }
    }

    if (p.r != 1) {
        if (vac1.size() && !chosen[p.r]) {
            res++;
            par[p.r] = vac1.back(); vac1.pop_back();
        }
        else par[p.r] = 1;
    }

    cout << res << '\n';
    for (int i=2; i<=n; ++i) {
        if (par[i] == 0) cout << "1 ";
        else cout << par[i] << ' ';
    }

    return 0;
}
/*
(6)
12
1 1 1 2 2 3 0 8 8 9 10

(4)
10
1 1 0 4 5 0 7 7 7

(4)
10
1 1 0 4 4 4 0 8 9

(4)
10
1 2 0 4 5 0 7 7 7

(6)
13
1 2 0 4 5 0 7 8 0 10 10 10
*/