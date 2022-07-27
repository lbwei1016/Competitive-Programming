/*
***Off-line*** --Segment Tree
    Solution:
        An area is well-defended if only if:
            1. Each row in the area is occupied by at least one rook
            2. ...  column ...,
        either 1. or 2. is satisfied.

        行列分開處理；先看行:
            將 query 依區域行右界(y2)排序(小的先)，同時 rook 依照 y 座標排序(小的先)。
            每次將 rook 更新至小於等於當前 query 行右界的位置，於是所有在場上的 rook 都在
            query 左方。另外維護資訊 last[i]: 第 i 列最後出現的 rook 在 last[i] 行；
            若 min(last[i], for all x1 <= i <= x2) >= y1，則在該 query 為 YES，否則
            再查看列的情形(行列分開處理)。
        列同理，注意參數完全相反，不要改錯或忘記改(像是 N, M, x, y,...)。
    O(klogk + qlogq + klog(nm))
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)
using namespace std;
using ll = long long;

const int MAX_N = 1 << 20;
struct P {
    int x, y;
};
struct Q {
    int x, xx, y, yy;
    int id;
};

int seg[MAX_N];

void update(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        seg[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos < mid) update(LC(v), l, mid, pos, val);
    else update(RC(v), mid, r, pos, val);
    seg[v] = min(seg[LC(v)], seg[RC(v)]);
}

int query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[v];
    int mid = (l + r) / 2;
    if (qr <= mid) return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid) return query(RC(v), mid, r, ql, qr);
    else {
        return min(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
    }
}

int main() {
    io;
    int n, m, k, q, N = 1, M = 1;
    cin >> n >> m >> k >> q;
    vector<P> rook(k);
    vector<Q> Que(q);
    vector<int> ok(q, 0);

    for (int i=0; i<k; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        rook[i] = {x, y};
    }
    for (int i=0; i<q; ++i) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        --x; --xx; --y; --yy;
        Que[i] = {x, xx, y, yy, .id=i};
    }
    while (N < n) N <<= 1;
    while (M < m) M <<= 1;

    // right bound (y axis: column)
    memset(seg, -1, sizeof(seg));
    sort(rook.begin(), rook.end(), [](P p1, P p2) {
        return p1.y < p2.y;
    });
    sort(Que.begin(), Que.end(), [](Q &p1, Q &p2) {
        return p1.yy < p2.yy;
    });

    auto it = rook.begin();
    for (auto &p: Que) {
        while (it != rook.end() && it->y <= p.yy) {
            update(0, 0, N, it->x, it->y);
            ++it;
        }
        int lastpos = query(0, 0, N, p.x, p.xx+1);
        if (lastpos >= p.y) ok[p.id] |= 1;
    }

    // right bound (x axis: row)
    memset(seg, -1, sizeof(seg));
    sort(rook.begin(), rook.end(), [](P p1, P p2) {
        return p1.x < p2.x;
    });
    sort(Que.begin(), Que.end(), [](Q &p1, Q &p2) {
        return p1.xx < p2.xx;
    });

    it = rook.begin();
    for (auto &p: Que) {
        while (it != rook.end() && it->x <= p.xx) {
            update(0, 0, M, it->y, it->x);
            ++it;
        }
        int lastpos = query(0, 0, M, p.y, p.yy+1);
        if (lastpos >= p.x) ok[p.id] |= 1;
    }

    for (auto x: ok) {
        if (x) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}