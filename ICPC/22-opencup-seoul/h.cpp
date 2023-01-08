#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

struct P {
    ll val;
    int at;
    P (): val(-1) {}
    P(ll _v, int _a): val(_v), at(_a) {}
};

int main() {
    io;
    int n; cin >> n;
    vector<ll> H(n);
    for (int i=0; i<n; ++i) {
        cin >> H[i];
    }
    vector<P> premx(n + 1);
    for (int i=0; i<n; ++i) {
        if (H[i] > premx[i].val) {
            premx[i+1] = P(H[i], i);
        }
        else {
            premx[i+1] = premx[i];
        }
    }
    int at = premx[n].at;
    ll prod = 1;
    while (at > 0) {
        int to = premx[at].at;
        ll tm = (at - to) + 1;
        prod *= tm;
        prod %= MOD;
        at = to;
    }
    cout << prod << '\n';
    return 0;
}