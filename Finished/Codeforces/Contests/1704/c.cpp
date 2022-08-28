#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> seg, at(m);
    for (int i=0; i<m; ++i) cin >> at[i];
    sort(at.begin(), at.end());
    for (int i=1; i<m; ++i) {
        ll x = at[i] - at[i-1] - 1;
        if (x > 0)
            seg.push_back(x);
    }

    ll last = at[0] + n - at.back() - 1;
    if (last > 0) {
        seg.push_back(last);
    }

    sort(seg.begin(), seg.end(), greater<int>());
    ll res = 0;
    for (ll i=0; i<seg.size(); ++i) {
        ll k = seg[i] - (4LL*i + 1LL);
        if (k == 0) res++;
        else if (k < 0) break;
        else res += k;
    }
    cout << (n - res) << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}