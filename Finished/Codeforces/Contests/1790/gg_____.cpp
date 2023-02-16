#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
struct P {
    int tok, bon;
};

bool solve() {
    int n, m;
    cin >> n >> m;
    int p, b;
    cin >> p >> b;
    vector<P> info(n + 1);
    vector<int> tok(p), bon(b);
    for (int i=0; i<p; ++i) {
        int x; cin >> x;
        info[x].tok = 1;
        tok[i] = x;
    }
    for (int i=0; i<b; ++i) {
        int x; cin >> x;
        info[x].bon = 1;
        bon[i] = x;
    }

    vector<vector<int>> G(n + 1);
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto bfs = [&]()->int {
        queue<int> que;
        vector<int> dis(n + 1, INF);
        que.push(1);
        dis[1] = 0;
        while (que.size()) {
            int v = que.front(); que.pop();
            for (auto u: G[v]) {
                if (dis[u] == INF && info[u].bon) {
                    que.push(u);
                    dis[u] = dis[v] + 1;
                }
                else if (info[u].tok) {
                    dis[u] = dis[v] + 1;
                }
            }
        }

        vector<int> valid;
        for (int i=1; i<=n; ++i) {
            if (info[i].tok && dis[i] != INF) {
                // return 0: finish
                if (dis[i] == 1) {
                    cout << "dis = 1\n";
                    return 0;
                }
                valid.push_back(i);
            }
        }
        if (valid.size() > 1) {
            cout << "Multi path\n";
            return 0;
        }
        else if (valid.size() == 1) return dis[valid.back()];
        // invalid
        cout << "NO path\n";
        return INF;
    };

    int res = bfs();
    if (res == 0) return true;
    else if (res == INF) return false;

    cout << "dis: " << res << '\n';

    vector<bool> vis(n + 1, false);
    function<void(int, int&, vector<int>&)> dfs = [&](int v, int &t_cnt, vector<int> &cbon) {
        vis[v] = true;
        if (info[v].tok) t_cnt++;
        if (info[v].bon) cbon.push_back(v);
        for (auto u: G[v]) {
            if (vis[u]) continue;
            if (info[u].bon || (info[v].bon && info[u].tok)) {
                dfs(u, t_cnt, cbon);
            }
        }  
    };

    int tot_cnt = 0;
    for (auto &v: bon) {
        if (vis[v]) continue;
        int t_cnt = 0;
        vector<int> cbon;
        dfs(v, t_cnt, cbon);

        bool good = false;
        for (auto &x: cbon) {
            for (auto &y: G[x]) {
                if (info[y].bon) {
                    good = true;
                    break;
                }
            }
            if (good) break;
            // isolated overlapping vertex
            else if (info[x].tok) --t_cnt;
        }
        if (good && t_cnt) {
            cout << "who: " << v << "; ";
            cout << "infinite\n";
            return true;
        }
        tot_cnt += t_cnt;
    }

    return tot_cnt >= res - 1;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
1
8 8
2 4
3 7
6 8 4 2
1 4
4 2
2 3
2 5
5 8
8 7
7 6
6 8
*/