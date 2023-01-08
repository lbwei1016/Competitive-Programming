#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll MOD = 1e18 + 31;
ll a0 = 960002411612632915;
ll g = 42;
const int N = 1e6;

ll fpow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    io;
    int n; cin >> n;
    vector<ll> res(N + 1);
    res[N] = 300;
    res[0] = a0;
    for (int i=N-1; i>=1; --i) {
        ll val = fpow(g, res[i+1]);
        res[i] = fpow(g, res[i+1]);
    }
    cout << res[n] << '\n';
    return 0;
}