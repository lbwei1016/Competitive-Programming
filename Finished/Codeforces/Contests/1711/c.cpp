#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool calc(ll n, ll m, ll k, vector<ll> &v) {
    // vector<int> rs;
    ll e_sum = 0, o_mx = 0;
    // ll odd = 0;
    for (auto x: v) {
        ll p = x / n;
        // rs.push_back(p);
        if (p & 1) {
            o_mx = max(o_mx, p);
        }
        else o_mx = max(o_mx, p-1);
        
        if (p > 1) e_sum += p;
        // o_mx = max(o_mx, p - (!(p&1)));
    }    
    
    // cout << "\n-------------------\n";
    // for (auto x: rs) cout << x << ' ';

    if (m & 1) {
        if (e_sum >= m && o_mx >= 3) return true;
        else return false;
    }
    else {
        if (e_sum >= m) return true;
        else return false;
    }
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> v(k);
    for (auto &x: v) cin >> x;
    bool ok = calc(n, m, k, v);
    if (!ok) ok = calc(m, n, k, v);
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}