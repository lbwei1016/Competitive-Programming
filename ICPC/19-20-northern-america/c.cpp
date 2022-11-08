#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5, INF = 1e9 + 7;
int n, m;
vector<int> G[N];

// struct P {
//     ll d, at;
//     bool operator>(P p) const {
//         return d < p.d;
//     }
// };

void go(int st) {
    queue<int> que;
    que.push(st);
    vector<ll> dis(N, INF);
    dis[st] = 0;
    while (que.size()) {
        int u = que.front(); que.pop();
        for (auto v: G[u]) {
            if (dis[v] == INF) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    cout << dis[n]-1 << '\n';
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    go(1);
    return 0;
}