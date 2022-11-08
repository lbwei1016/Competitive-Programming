#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int n, k, m;
// vector<int> G[N];
vector<int> jobid;

int main() {
    io;
    cin >> n >> k >> m;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        // G[u].push_back(v);
    }
    int prod = n * k;
    jobid.resize(prod);
    for (int i=0; i<prod; ++i) {
        cin >> jobid[i];
    }
    map<int, int> mp;
    vector<int> runid(prod);
    for (int i=0; i<prod; ++i) {
        runid[i] = ++mp[jobid[i]];
    }
    for (auto x: runid) cout << x << ' ';
    return 0;
}