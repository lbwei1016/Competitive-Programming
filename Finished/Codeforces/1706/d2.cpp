#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n), m;
    for (int i=0; i<n; ++i) cin >> v[i];
    m.resize(v.back()+10);

    for (int i=0; i<n; ++i) {
        int bd = min(k, v[i]);
        int pre = 1e9+7, now = 0;
        for (int j=1; j<=bd; j=(v[i] / (v[i]/j)) + 1) {
            now = v[i] / j;
            m[now+1] = max(m[now+1], pre);
            pre = now;
        }
        m[0] = max(m[0], pre); // least value "0" isn't calculated in the above loop
    }

    int res = 1e9+7, mx = 0;
    for (int i=0; i<=v[0]; ++i) {
        mx = max(mx, m[i]); // in case m[k] doesn't exist for some k
        res = min(res, mx - i);
    }   
    cout << res << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}