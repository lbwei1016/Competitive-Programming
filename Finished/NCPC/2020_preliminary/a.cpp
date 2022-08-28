/*
***Mod***
    Solution:
        因為 p, q 互質，所以
        r = px + qy => px - r = qy => px - r ≡ 0 (mod q)
            => px ≡ r (mod q)
        找 p 在 mod q 下的模逆元，即可找出 x。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a; // gcd(a, b)
    if (b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else {
        x = 1;
        y = 0;
    }
    return d;
}

ll calc(ll r, ll p, ll q) {
    ll x = 0, y = 0;
    extgcd(p, q, x, y);
    x += q; x %= q;
    x = r * x % q;
    y = (r - x*p) / q;
    // cout << "x: " << x << "; y: " << y << '\n';
    return abs(x) + abs(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while (t--) {
        ll r, p, q, mn;
        cin >> r >> p >> q;
        ll a = calc(r, p, q), b = calc(r, q, p);
        mn = min(a, b);
        cout << mn << '\n';
        // cout << "a: " << a << "; b: " << b << '\n';
    }
    return 0;
}
/*
4
2 3 5
4 4 3
13 5 7
17 4 9

ans: 2 1 5 3
*/