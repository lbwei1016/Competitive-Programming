#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);    
    map<ll, pair<ll, ll>> mp;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        mp[v[i]] = {1e17, -1};
    }

    for (ll i=0; i<n; ++i) {
        auto &p = mp[v[i]];
        p.first = min(p.first, i);
        p.second = max(p.second, i);
    }
    
    while (k--) {
        ll a, b; cin >> a >> b;
        bool good = false;
        
        if (mp.count(a) && mp.count(b) && mp[b].second > mp[a].first) good = true;
        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
1

6 3
3 7 1 5 1 4
3 5
1 7
3 10
*/