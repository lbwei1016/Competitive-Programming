#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 21;
vector<int> G[N], par(N);
int n;

vector<bool> vis(1 << N);
int res;
int S0 = 2;

vector<int> seq;

bool check(int S, int x) {
    for (auto u: G[x]) {
        if ((S >> u) & 1) return false;
    }
    return true;
}

void rec(int S, int d, set<int> &ok, bool fg) {
    if (fg && S == S0) {
        res = max(res, d);
        return;
    }
    for (auto x: ok) {
        if (!check(S, x)) continue;
        int nxt = S ^ (1 << x);
        if (vis[nxt]) continue;

        vis[nxt] = true;
        set<int> tmp = ok;
        for (auto u: G[x]) {
            ok.insert(u);
        }
        rec(nxt, d + 1, ok, 1);
        vis[nxt] = false;
        ok = tmp;
    }
}

int main() {
    io;
    cin >> n;
    set<int> ok;
    for (int i=2; i<=n; ++i) {
        int p; cin >> p;
        G[p].push_back(i);
        if (p == 1) ok.insert(i);
    }

    vis[2] = true;
    rec(S0, 0, ok, 0);
    cout << res - 1 << '\n';
    return 0;
}