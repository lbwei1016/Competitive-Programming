#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P { 
    ll val, frq; 
    bool operator==(const P p) const {
        return p.frq == frq && p.val == val;
    }
};

void calc(vector<P> &v, ll n, ll m) {
    for (int i=0; i<n; ++i) {
        ll x; cin >> x;
        ll cnt = 1;
        while (x % m == 0) {
            x /= m;
            cnt *= m;
        }
        if (v.size() && v.back().val == x) {
            v.back().frq += cnt;
        }
        else v.push_back({x, cnt});
    }
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m;
        vector<P> a, b;
        calc(a, n, m);
        cin >> k;
        calc(b, k, m);
        if (a == b) cout << "Yes\n";
        else cout << "No\n";
    }    
    return 0;
}