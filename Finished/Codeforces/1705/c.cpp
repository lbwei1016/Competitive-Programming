#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, c, q; cin >> n >> c >> q;
    string s; 
    s.resize(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> s[i];
    }
    map<ll, ll> mp;

    ll ed1 = n + 1, ed2;
    for (int i=0; i<c; ++i) {
        ll l, r;
        cin >> l >> r;
        ed2 = ed1 + (r-l);
        mp[ed1] = l;
        mp[ed2] = r;
        ed1 = ed2 + 1;
    }

    while (q--) {
        ll k; cin >> k;
        while (k > n) {
            auto it = mp.lower_bound(k);
            ll diff = it->first - k;
            k = it->second - diff;
        }
        cout << s[(int)k] << '\n';
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