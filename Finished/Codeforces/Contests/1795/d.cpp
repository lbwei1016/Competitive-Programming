#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll P = 998244353;
const int N = 1e5 + 5;

ll fact[N];

void calc() {
    fact[0] = 1;
    for (int i=1; i<N; ++i) {
        fact[i] = fact[i - 1] * i % P;
    }   
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a; // gcd(a, b)
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else {
        x = 1; y = 0;
    }
    // Procedure.push_back({x, y});
    return d;
}

ll inv(ll z) {
    ll x = 0, y = 0;
    extgcd(z, P, x, y);
    return (x + P) % P;
}

ll bi(int n, int k) {
    return fact[n] * inv(fact[k] * fact[n - k] % P) % P;
}

void solve() {
    calc();
    int n; cin >> n;
    vector<ll> w(n);
    ll res = 1;

    for (int i=0; i<n; i+=3) {
        int a[3];
        for (int j=0; j<3; ++j) {
            cin >> a[j];
        }
        sort(a, a + 3);
        if (a[0] == a[1] && a[1] == a[2]) {
            res *= 3;
            res %= P;
        }
        else if (a[0] == a[1]) {
            res *= 2;
            res %= P;
        }
    }
    res *= bi(n / 3, n / 6);
    res %= P;
    cout << res << '\n';
}

int main() {
    io;
    // int tt; cin >> tt;
    // while (tt--) {
    //     solve();
    // }
    solve();
    return 0;
}