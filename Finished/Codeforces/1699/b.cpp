#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    int a = 1, b = 0;
    vector<ll> v;

    ll x = 0;
    for (int j=0; j<m/2; ++j) {
        x <<= 1; x |= a; 
        x <<= 1; x |= b;
        a ^= 1, b ^= 1;
    }
    for (int i=0; i<n/2; ++i) {
        v.push_back(x); v.push_back(~x);
        x = ~x;
    }
    for (int i=0; i<n; ++i) {
        ll k = v[i];
        for (int j=0; j<m; ++j) {
            if (k & 1) cout << "1 ";
            else cout << "0 ";
            k >>= 1;
        }        
        cout << '\n';
    }
}

int main() {
    // io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}