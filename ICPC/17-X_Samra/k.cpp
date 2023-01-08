#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll INF = 1e18;
struct P {
    int l, r;
    ll w;
    bool operator<(P p) const {
        return l < p.l;
    }
};

const int N = 4e5 + 5;
ll dp[2][N];

int main() {
    // io;
    int n; cin >> n;
    vector<P> pt(n);
    vector<int> vals;
    ll mnr = INF, mxr = 0;
    for (int i=0; i<n; ++i) {
        int l, r; ll w;
        cin >> l >> r >> w;
        pt[i] = P{l, r, w}; 
        // mnr = min(mnr, (ll)r);
        // mxr = max(mxr, (ll)r);
        vals.push_back(l);
        vals.push_back(r);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i=0; i<n; ++i) {
        pt[i].l = lower_bound(vals.begin(), vals.end(), pt[i].l) - vals.begin();
        pt[i].r = lower_bound(vals.begin(), vals.end(), pt[i].r) - vals.begin();
        mnr = min(mnr, (ll)pt[i].r);
        mxr = max(mxr, (ll)pt[i].r);
    }

    sort(pt.begin(), pt.end());
    dp[1][pt[0].r] = pt[0].w;
    int cnt = 1;
    for (int i=pt[cnt].l; i<=mxr; i=pt[++cnt].l) {
        for (int j=i; j<pt[cnt].r; ++j) {
            dp[0][j] = dp[1][j] = dp[1][pt[cnt-1].r];
        }
        dp[0][pt[cnt].r] = dp[1][pt[cnt-1].r];
        dp[1][pt[cnt].r] = pt[cnt].w + dp[1][pt[cnt].l];
    }
    cout << max(dp[1][mxr], dp[0][mxr]);
    return 0;
}
