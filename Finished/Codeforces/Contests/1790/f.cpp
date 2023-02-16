/*
    This is better: https://codeforces.com/submissions/tourist/contest/1790
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5 + 5, INF = 1e9 + 7;
vector<int> G[N];

void bfs(int n, int st, int &mn, vector<int> &dis, vector<int> &from) {
    queue<int> que;
    que.push(st);
    dis[st] = 0; from[st] = st;

    while (que.size()) {
        int v = que.front(); que.pop();
        if (dis[v] >= mn) return;
        for (auto &u: G[v]) {            
            if (dis[u] > dis[v] + 1) {
                dis[u] = dis[v] + 1;
                from[u] = from[v];
                que.push(u);
            }
            if (from[u] != from[v])
                mn = min(mn, dis[u] + dis[v] + 1);
        }
    }
}

void solve() {
    int n, rt;
    cin >> n >> rt;
    vector<int> seq(n - 1);
    vector<int> dis(n + 1, INF);
    for (auto &x: seq) cin >> x;

    for (int i=1; i<=n; ++i) G[i].clear();
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> from(n + 1);
    int mn = INF;
    bfs(n, rt, mn, dis, from);
    for (auto &x: seq) {
        bfs(n, x, mn, dis, from);
        cout << mn << ' ';
    }
    cout << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}