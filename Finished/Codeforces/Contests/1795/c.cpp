#include <bits/stdc++.h>
#define LC(v) (2*(v) + 1)
#define RC(v) (2*(v) + 2)
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
struct Node {
    ll val, tag;
} seg[1 << 20];

void update(int v, int l, int r, int ul, int ur, ll val) {
    if (ul <= l && r <= ur) {
        seg[v].tag += val;
        return;
    }
    int mid = (l + r) / 2;
    if (ur <= mid) update(LC(v), l, mid, ul, ur, val);
    else if (ul >= mid) update(RC(v), mid, r, ul, ur, val);
    else {
        update(LC(v), l, mid, ul, ur, val);
        update(RC(v), mid, r, ul, ur, val);
    }
    seg[v].val += (ll)(min(r, ur) - max(l, ul)) * val;
}

ll query(int v, int l, int r, int pos) {
    if (r - l == 1) return seg[v].val + seg[v].tag;

    int mid = (l + r) / 2;
    if (pos < mid)
        return query(LC(v), l, mid, pos) + seg[v].tag;
    else
        return query(RC(v), mid, r, pos) + seg[v].tag;
}


void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    
    vector<ll> psum(n);
    for (int i=0; i<n; ++i) {
        cin >> b[i];
        if (i == 0) psum[i] = b[i];
        else psum[i] = psum[i - 1] + b[i];
    }

    vector<ll> res(n);
    vector<pair<int, int>> op;
    for (int i=0; i<n; ++i) {
        ll val = a[i];
        if (i > 0) val += psum[i - 1];
        int at = lower_bound(psum.begin(), psum.end(), val) - psum.begin();
        if (at > i) {
            update(0, 0, n, i, at, 1);
            op.push_back({i, at});
        }
        if (at > 0 && at < n) {
            res[at] += val - psum[at - 1];
        }
        else if (at == 0) {
            res[0] += a[0];
        }
    }
    for (int i=0; i<n; ++i) {
        res[i] += query(0, 0, n, i) * b[i];
        cout << res[i] << ' ';
    }
    cout << '\n';

    for (auto &p: op) {
        // cout << p.first << ' ' << p.second << '\n';
        update(0, 0, n, p.first, p.second, -1);
    }
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}