#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define LC(v) (2*(v) + 1)
#define RC(v) (2*(v) + 2)
using ll = long long;
using namespace std;

struct Seg {
    ll val; // range sum
    ll tag; // added value
    ll ass; // assigned value
    ll sz; // # of elements in current segment

    ll ival; 
    ll factor; 
    bool assigned;
    bool added;
} seg[1 << 20];

vector<ll> vec;

void push(int v) {
    auto &lc = seg[LC(v)], &rc = seg[RC(v)];
    // 先判斷 assigned 再 added
    if (seg[v].assigned) {
        lc.ass = rc.ass = seg[v].ass;
        lc.assigned = rc.assigned = true;
        lc.added = rc.added = false;

        lc.val = rc.val = lc.tag = rc.tag = 0;
        lc.ival = rc.ival = 0;

        seg[v].ass = 0;
        seg[v].assigned = false;
    }
    if (seg[v].added) {
        lc.tag += seg[v].tag;
        rc.tag += seg[v].tag;
        lc.added = rc.added = true;

        seg[v].added = false;
        seg[v].tag = 0;
    }
}

void pull(int v) {
    seg[v].val = seg[LC(v)].val + seg[RC(v)].val;
    seg[v].val += (seg[LC(v)].tag + seg[LC(v)].ass) * seg[LC(v)].sz + \
                (seg[RC(v)].tag + seg[RC(v)].ass) * seg[RC(v)].sz;
    seg[v].ival = seg[LC(v)].ival + seg[RC(v)].ival;
    seg[v].ival += (seg[LC(v)].tag + seg[LC(v)].ass) * seg[LC(v)].factor + \
                (seg[RC(v)].tag + seg[RC(v)].ass) * seg[RC(v)].factor;
}

void build(int v, int l, int r) {
    seg[v].sz = r - l;
    seg[v].factor = ll(l+1 + r) * ll(r - l) / 2LL;
    if (r - l == 1) {
        seg[v].val = vec[l];
        seg[v].ival = vec[l] * ll(l + 1);
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid);
    build(RC(v), mid, r);
    pull(v);
}

void update(int v, int l, int r, int ul, int ur, ll val, int op) {
    if (ul <= l && r <= ur) {
        // assign
        if (op == 1) {
            seg[v].assigned = true;
            seg[v].added = false;
            seg[v].ass = val;
            seg[v].ival = seg[v].val = seg[v].tag = 0;
        }
        else {
            seg[v].added = true;
            seg[v].tag += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    push(v);
    if (ur <= mid) {
        update(LC(v), l, mid, ul, ur, val, op);
    }
    else if (ul >= mid) {
        update(RC(v), mid, r, ul, ur, val, op);
    }
    else {
        update(LC(v), l, mid, ul, ur, val, op);
        update(RC(v), mid, r, ul, ur, val, op);
    }
    pull(v);
}

ll query(int v, int l, int r, int ql, int qr, int op) {
    if (ql <= l && r <= qr) {
        if (op == 0)
            return seg[v].val + (seg[v].tag + seg[v].ass) * seg[v].sz;
        if (op == 1) 
            return seg[v].ival + (seg[v].tag + seg[v].ass) * seg[v].factor;
    }
    push(v);

    ll res = 0;
    int mid = (l + r) / 2;
    if (qr <= mid) {
        res += query(LC(v), l, mid, ql, qr, op);
    }
    else if (ql >= mid) {
        res += query(RC(v), mid, r, ql, qr, op);
    }
    else {
        res += query(LC(v), l, mid, ql, qr, op) + query(RC(v), mid, r, ql, qr, op);
    }
    pull(v);
    return res;
}

int main() {
    io;
    int n, q;
    cin >> n >> q;
    vec.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
    } 
    build(0, 0, n);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        if (op == 3) {
            ll num = query(0, 0, n, l, r, 1);
            ll den = query(0, 0, n, l, r, 0);
            if (den == 0) {
                if (num == 0) cout << "Yes\n";
                else cout << "No\n";
            }
            else if (num % den == 0) {
                ll quo = num / den;
                if (l+1 <= quo && quo <= r)
                    cout << "Yes\n";
                else cout << "No\n";
            }
            else cout << "No\n";
        }
        else {
            ll val;
            cin >> val;
            update(0, 0, n, l, r, val, op-1);
        }
    }
    return 0;
}