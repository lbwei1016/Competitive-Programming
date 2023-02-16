#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 105;
int G[N][N], GG[N][N];

void solve() {
    int n; cin >> n;
    memset(G, 0, sizeof(G));
    int tar = 0, at = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n-1; ++j) {
            int x; cin >> x;
            GG[i][j] = x;
            if (++G[x][j] == n - 1) {
                tar = x;
                at = j;
            }
        }
    }

    vector<int> res;
    res.reserve(n);
    for (int i=0; i<n; ++i) {
        if (GG[i][at] != tar) {
            for (int j=0; j<n-1; ++j) {
                res.push_back(GG[i][j]);
            }
            if (at != 0) at++;
            res.insert(res.begin() + at, tar);
            for (auto x: res) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}