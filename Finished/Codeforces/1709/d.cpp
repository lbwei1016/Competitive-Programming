#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)

int M;
vector<ll> seg;

void build(int v, int l, int r, vector<ll> &h) {
    if (l >= h.size()) return;
    if (r-l == 1) {
        seg[v] = h[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid, h);
    build(RC(v), mid, r, h);
    seg[v] = max(seg[LC(v)], seg[RC(v)]);
}

ll query(int v, int l, int r, int ql, int qr) {
    if (ql<=l && r<=qr) return seg[v];
    int mid = (l + r) / 2;
    if (qr <= mid) return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid) return query(RC(v), mid, r, ql, qr);
    else {
        return max(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
    }
}

void solve() {
    ll n, m; cin >> n >> m;
    M = 1;
    while (M < m) M <<= 1;
    seg.resize(2*M+5);

    vector<ll> h(m+1);
    for (int i=0; i<m; ++i) {
        cin >> h[i]; --h[i];
    }
    build(0, 0, M, h);

    int q; cin >> q;
    while (q--) {
        ll xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        --xs; --ys; --xf; --yf;
        ll dx = xf - xs, dy = yf - ys;
        if (dx % k != 0 || dy % k != 0) {
            cout << "NO\n"; 
            continue;
        }
        if (yf < ys) {
            swap(yf, ys);
        }
        ll barr = query(0, 0, M, ys, yf+1);
        ll diff = barr - xs;
        if (diff >= 0) {
            ll up = (diff / k + 1LL) * k;
            if (up+xs >= n) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
}

int main() {
    io;
    solve();
    return 0;
}