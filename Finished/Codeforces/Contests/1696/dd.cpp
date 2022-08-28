#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 1e9+7;
struct P {
    int val, at;
};
vector<P> pmin, pmax, smin, smax;

int rec(int l, int r, vector<int> &v, int st, vector<P> &mxs, vector<P> &mns) {
    if (l > r) return 0;

    int tar;
    if (mxs.size() == v.size()) tar = r; // prefix
    else tar = l;
    int mx_at = mxs[tar].at, mn_at = mns[tar].at;
    if ((l==mx_at && r==mn_at) || (l==mn_at && r==mx_at) || l==r)
        return 1;
    
    int at;
    if (st) at = mx_at; // find max
    else at = mn_at;

    return rec(l, at, v, st^1, mxs, mns) + rec(at, r, v, st^1, mxs, mns);
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n+1);
        pmin.clear(); pmax.clear(); smin.clear(); smax.clear();
        pmin.resize(n+1, {INF, 0}); pmax.resize(n+1);
        smin.resize(n+2, {INF, 0}); smax.resize(n+2);

        for (int i=1; i<=n; ++i) cin >> v[i];

        if (n == 1) {
            cout << "0\n";
            continue;
        }
        for (int i=1; i<=n; ++i) {  
            if (v[i] < pmin[i-1].val) pmin[i] = {v[i], i};
            else pmin[i] = pmin[i-1];
            if (v[i] > pmax[i-1].val) pmax[i] = {v[i], i};
            else pmax[i] = pmax[i-1];
        }
        for (int i=n; i>=1; --i) {
            if (v[i] < smin[i+1].val) smin[i] = {v[i], i};
            else smin[i] = smin[i+1];
            if (v[i] > smax[i+1].val) smax[i] = {v[i], i};
            else smax[i] = smax[i+1];
        }

        int mx_at = pmax[n].at, mn_at = pmin[n].at;        
        int ans = 0;
        if ((1==mx_at && n==mn_at) || (1==mn_at && n==mx_at))
            ans = 1;
        else {
            if (mx_at != 1 && mx_at != n)
                ans = rec(1, mx_at, v, 0, pmax, pmin) + rec(mx_at, n, v, 0, smax, smin);
            else 
                ans = rec(1, mn_at, v, 1, pmax, pmin) + rec(mn_at, n, v, 1, smax, smin);
        }
        cout << ans << '\n';
    }
    return 0;
}