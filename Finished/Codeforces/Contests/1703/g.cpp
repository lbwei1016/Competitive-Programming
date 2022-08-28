#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    ll n, k, mx = 0; cin >> n >> k;
    vector<ll> v(n), psum(n+1);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        psum[i+1] = psum[i] + (v[i]-k);
        mx = max(mx, v[i]);
    }

    vector<ll> ssum(n+1);
    ll u = 2;
    for (int i=0; i<n; ++i) {
        ssum[0] += v[i] / u;
        if (u <= mx)
            u <<= 1;
        else break;
    }

    ll lg = log2(mx)+1;
    vector<ll> odd(n);
    for (int j=0; j<n; ++j) {
        for (int i=j, r=1; i<n && r<=lg; ++i) {
            ll y = v[i] >> r;
            odd[j] += (y & 1);
            ++r;
        }    
    }

    u = 2;
    for (int i=1, r=1; i<n; ++i, ++r) {
        ssum[i] = ssum[i-1] - v[i-1]/u;
        ssum[i] *= 2;
        ssum[i] += odd[i];
    }

    ll sum = 0;
    for (int i=0; i<=n; ++i) {
        sum = max(sum, psum[i]+ssum[i]);
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