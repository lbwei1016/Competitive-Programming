#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n+1, -1), res(n+1);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (v[x] == -1) {
            res[x]++;
            v[x] = i;
            continue;
        }
        int k = i - v[x];
        if (k & 1) ++res[x];
        v[x] = i;
    }
    for (int i=1; i<=n; ++i) cout << res[i] << ' ';
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