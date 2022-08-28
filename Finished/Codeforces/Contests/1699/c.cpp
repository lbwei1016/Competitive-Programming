#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> v(n), p(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        p[v[i]] = i;
    }

    int l = p[0], r = p[1];
    if (l > r) swap(l, r);
    ll sum = 1;
    for (int i=2; i<n; ++i) {
        int pos = p[i];
        if (l < pos && pos < r) 
            sum *= ((r - l + 1) - i);
        else {
            l = min(l, pos);
            r = max(r, pos);
        }
        sum %= MOD;
    }
    cout << sum << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}