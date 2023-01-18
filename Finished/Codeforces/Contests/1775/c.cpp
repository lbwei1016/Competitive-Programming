#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll solve() {
    ll n, x; cin >> n >> x;
    if (x == n) return n;
    if (x > n) return -1;

    if (x == 0) {
        ll n2 = 1;
        while (n2 <= n) n2 <<= 1;
        return n2;
    }

    ll x2 = 1;
    while (x2 <= x) x2 <<= 1;
    x2 >>= 1;

    ll n2 = 1, len = 0;
    while (n2 <= n) {
        n2 <<= 1;
        ++len;
    }
    n2 >>= 1; --len;
    if (n2 != x2) return -1;

    for (int i=len-1; i>=0; --i) {
        bool a = n & (1LL << i), b = x & (1LL << i);
        if (a != b) {
            if (!a && b) return -1;
            // below a=1; b=0
            bool trail = x & ((1LL << i) - 1);
            if (trail) return -1;
            if (n & (1LL << (i + 1))) return -1;
            return (n & ~((1LL << (i + 1)) - 1)) | (1LL << i + 1);
        }
    }
    return -1;
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}