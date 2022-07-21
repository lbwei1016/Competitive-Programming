#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> h(n+1);
    for (int i=1; i<=n; ++i) cin >> h[i];
    vector<ll> diff(n+1);

    for (int i=2; i<n; ++i) {
        diff[i] = max(max(h[i-1], h[i+1])-h[i]+1, 0LL);
    }
    ll sum = 1e17;
    if (n & 1) {
        sum = 0;
        for (int i=2; i<n; i+=2) sum += diff[i];
    }
    else {
        vector<ll> ssum(n+3), psum(n+3);
        for (int i=n-1; i>1; i-=2) {
            ssum[i] = diff[i] + ssum[i+2];
            ssum[i-1] = ssum[i];
        }
        for (int i=2; i<n; i+=2) {
            psum[i] = diff[i] + psum[i-2];
            psum[i+1] = psum[i];
        }
        for (int i=2; i<n; ++i) {
            // int at = i - (i&1);
            ll k = psum[i-2] + diff[i] + ssum[i+2];
            sum = min(k, sum);
            if (i+3 < n && i % 2 == 0) {
                k = psum[i-2] + diff[i] + ssum[i+3];
                sum = min(k, sum);
            }
        }
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