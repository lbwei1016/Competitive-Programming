#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    vector<pair<ll, ll>> seq;
    multimap<ll, ll> S;
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
        if (i > v[i]) {
            S.insert({v[i], 0});
            seq.push_back({v[i], i});
        }
    }

    int cnt = 0;
    for (auto &p: S) {
        p.second = cnt++;
    }

    ll sum = 0, sz = S.size();
    for (int i=0; i<seq.size(); ++i) {
        auto p = seq[i];
        auto it = S.upper_bound(p.second);
        // S.erase(p.first);
        if (it == S.end()) continue;
        sum += sz - it->second;
    }
    cout << sum << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
/*
1 1 2 3 8 2 1 4
x o x x x o o o
*/