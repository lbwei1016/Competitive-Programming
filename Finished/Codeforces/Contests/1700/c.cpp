/*
***Tree / DP***
    Solution:
        For every vertex v, record its two states:
            1. # of vertices can save if v is deleted (SZ[v].first)
            2. # of vertices can save if v is infected (SZ[v].second)
    O(n)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

vector<pair<int, int> > SZ;
int dfs(vector<vector<int> > &G, int at, int p) {
    vector<pair<int, int> > v;
    for (auto u: G[at]) {
        if (u == p) continue;
        SZ[at].first += dfs(G, u, at) + 1;
        v.push_back(SZ[u]);
    }

    for (int i=v.size(); i<2; ++i) v.push_back({0, 0});
    SZ[at].second = max(v[0].first+v[1].second, v[0].second+v[1].first);
    return SZ[at].first;
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        SZ.clear();
        SZ.resize(n+1);
        vector<vector<int> > G(n+1, vector<int>());
        for (int i=0; i<n-1; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(G, 1, 0);
        cout << SZ[1].second << '\n';
    }
    return 0;
}