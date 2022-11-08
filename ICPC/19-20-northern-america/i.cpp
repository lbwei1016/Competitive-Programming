#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
int n;
string S[N];
vector<int> G[N];    
vector<int> match(N, -1);
bitset<N> vis;

void precalc() {
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int diff = 0;
            for (int k=0; k<S[i].size(); ++k) {
                if (S[i][k] != S[j][k]) ++diff;
            }
            if (diff == 2) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}

bool dfs(int v) {
    for (auto u: G[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int matching() {
    int res = 0;
    for (int i=0; i<n; ++i) {
        if (match[i] == -1) {
            vis.reset();
            if (dfs(i)) ++res;
        }
    }
    return res;
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) cin >> S[i];    
    precalc();
    int res = n - matching();
    cout << res << '\n';
    return 0;
}