#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> h(n);
    for (int i=0; i<n; ++i) cin >> h[i];
    vector<ll> psum(n+5), ssum(n+5);
    for (int i=1; i<n; ++i) {
        psum[i] = psum[i-1] + max(0LL, h[i-1]-h[i]);
    }
    for (int i=n-1; i>0; --i) {
        ssum[i] = ssum[i+1] + max(0LL, h[i]-h[i-1]);
    }
    while (m--) {
        int a, b; cin >> a >> b;
        --a; --b;
        ll res = 0;
        if (a < b) {
            res = psum[b] - psum[a];
        }
        else res = ssum[b+1] - ssum[a+1];
        cout << res << '\n';
    }
}

int main() {
    io;
    // int tt; cin >> tt;
    // while (tt--) {
        solve();
    // }
    return 0;
}