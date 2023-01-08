/*
***Graph*** -- shortest path
    Description:
        Given a directed graph. On the i-th day, reverse the i-th edge. 
        Reversed edges are restored after the i-th day.
    Solution:
        找出所有最短路徑上的邊(pre[])。這些點和邊會形成一 DAG，找出此圖上的橋，
        也就是最短路徑的必經邊(可以利用 Tarjan's BCC，或是利用 DAG 的特性(?))。

        如果反轉的邊是必經邊，則 SAD；否則判斷走經反轉邊是否縮短距離(SAD 只會在
        必經邊被反轉才會出現)。
    Time Complexity:
        Dijkstra...
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const ll INF = 1e18 + 7;
struct P {
    ll v, w, id;
    bool operator<(const P &p) const {
        return w > p.w;
    }
};
struct Edge { ll u, v, w; };
int n, m;
vector<P> G[N], pre[N];
vector<ll> dis[3];
vector<int> deg(N);
vector<Edge> Es(N);

void dij(int s) {
    priority_queue<P> pq;
    pq.push(P{s, 0});
    dis[s][s] = 0;
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (dis[s][p.v] < p.w) continue;

        for (auto e: G[p.v]) {
            if (s == 1 && e.id == 0) continue;
            if (s == 2 && e.id > 0) continue;
            if (dis[s][e.v] > p.w + e.w) {
                dis[s][e.v] = p.w + e.w;
                pq.push(P{e.v, dis[s][e.v]});

                if (s == 1) {
                    pre[e.v].clear();
                    pre[e.v].push_back(P{p.v, e.w, e.id});
                }
            }
            else if (s == 1 && dis[s][e.v] == p.w + e.w) {
                pre[e.v].push_back(P{p.v, e.w, e.id});
            }
        }
    }
}

vector<int> low(N), dep(N, -1);
set<int> bri; // 可以開一個 bool table，作為 O(1) 查詢的替代
void dfs(int v, int p, int d, int id) {
    low[v] = dep[v] = d;
    for (auto e: pre[v]) {
        int u = e.v;
        if (u == p) continue;
        if (dep[u] != -1) {
            low[v] = min(low[v], dep[u]);
            continue;
        }
        dfs(u, v, d + 1, e.id);
        low[v] = min(low[v], low[u]);
    }

    if (low[v] == dep[v]) {
        bri.insert(abs(id));
    }
}

void solve() {
    dis[1] = dis[2] = vector<ll>(N, INF);
    dij(1); dij(2);

    int sh = dis[1][2]; // length of shortest path
    // 把 DAG 變成 undirected，並去除不在最短路徑上的邊
    for (int u=1; u<=n; ++u) {
        if (dis[1][u] + dis[2][u] != sh) {
            pre[u].clear();
            continue;
        }
        for (auto e: pre[u]) {
            if (e.id < 0) continue;
            int v = e.v;
            pre[v].push_back(P{u, 0, -e.id});
        }
    }

    dfs(2, 0, 0, 0);

    for (int i=1; i<=m; ++i) {
        if (bri.count(i)) cout << "SAD\n";
        else {
            auto e = Es[i];
            if (dis[1][e.v] + dis[2][e.u] + e.w < dis[1][2]) 
                cout << "HAPPY\n";
            else cout << "SOSO\n";
        }
    }
}

int main() {
    io;
    cin >> n >> m;
    for (int i=1; i<=m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(P{v, w, i});
        G[v].push_back(P{u, w, 0}); // reverse edge
        Es[i] = Edge{u, v, w};
    }
    solve();
    return 0;
}