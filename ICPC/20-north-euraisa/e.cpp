#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    io;
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        ll b, d;
        cin >> b >> d;
        ll GCD = __gcd(b, d);
        ll r = b * b / GCD;
        b /= GCD; d /= GCD;
        ll cnt = r / lcm(b, d);
        if (r % lcm(b, d) == 0) --cnt;
        cout << cnt << '\n';
    }
    return 0;
}