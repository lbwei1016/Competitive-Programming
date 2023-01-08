/*
***Tree*** -- heavy-light decomposition
    Description:
        原先權重在邊上，要轉換使得權重在點上。
        注意邊界查詢。
    Complexity:
        initialization: O(n)
        query: O((lg n)^2)
        update: O(lg n)
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v) + 1)
#define RC(v) (2*(v) + 2)
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int to, val, id;
};

const int N = 1e4 + 5, INF = 1e9 + 7;
vector<P> G[N];
vector<int> par, dep;
vector<int> heavy; // heavy[v]: v's next node on the heavy path
vector<int> head; // head[v]: the head of the path v is in

// 同一條鍊上，node 的 pos 會在一連續區間，以利線段樹操作
int cur_pos;
vector<int> pos; 

int n; // number of nodes
vector<int> arr;
vector<int> mp; // mp[id]: 第 id 條邊對應到 mp[id] 號點

int seg[2 * N];
void pull(int v);
void build(int v, int l, int r, vector<int> &arr);
void update(int v, int l, int r, int pos, int val);
int query(int v, int l, int r, int ql, int qr);

// calculate subtree sizes and mark the heavy paths
int dfs(int v) {
    int sz = 1;
    int mx_chlsz = 0;
    for (auto e: G[v]) {
        int u = e.to;
        if (u == par[v]) continue;
        mp[e.id] = u; 
        arr[u] = e.val; par[u] = v;
        dep[u] = dep[v] + 1;
        int chlsz = dfs(u);
        sz += chlsz;
        if (chlsz > mx_chlsz) {
            mx_chlsz = chlsz;
            heavy[v] = u;
        }
    }
    return sz;
}

void decompose(int v, int hd) {
    head[v] = hd;
    pos[v] = cur_pos++;
    // 先把鍊找出來
    if (heavy[v] != -1) decompose(heavy[v], hd);
    for (auto e: G[v]) {
        int u = e.to;
        if (u != par[v] && u != heavy[v]) {
            // 脫離現有的鍊，自成一新鍊
            decompose(u, u);        
        }
    }
}

void init() {
    arr = vector<int>(n, -INF);
    par = vector<int>(n);
    dep = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    mp = vector<int>(n);

    dfs(0);
    decompose(0, 0);

    // 將同一鍊上的 data 放在一起，才能用 segment tree 操作。
    vector<int> rearr(n);  
    for (int i=0; i<n; ++i) {
        rearr[pos[i]] = arr[i];
    }
    build(0, 0, n, rearr);
}

// Query for the maximum value on the path between two vertices a and b.
// Values are assigned to vertices.
// [a, b]
int trquery(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (dep[head[a]] > dep[head[b]]) 
            swap(a, b);
        // segment tree query
        int cur_heavy_path_mx = query(0, 0, n, pos[head[b]], pos[b] + 1);
        res = max(res, cur_heavy_path_mx);
        b = par[head[b]]; // 往上跳一條鍊
    }

    // 最後判斷，當 a and b 在同一條鍊上的時候
    if (dep[a] > dep[b])
        swap(a, b);
    // pos[a] + 1: 現在權重不在邊上，而在點上；交叉點的權重要略過。
    int last_heavy_path_mx = query(0, 0, n, pos[a] + 1, pos[b] + 1);
    res = max(res, last_heavy_path_mx);
    return res;
}

// segment tree
void pull(int v) {
    seg[v] = max(seg[LC(v)], seg[RC(v)]);
}

void build(int v, int l, int r, vector<int> &vec) {
    if (r - l == 1) {
        seg[v] = vec[l];
        return;
    }
    int mid = (r + l) / 2;
    build(LC(v), l, mid, vec);
    build(RC(v), mid, r, vec);
    pull(v);
}

void update(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        seg[v] = val;
        return;
    }
    int mid = (r + l) /2;
    if (pos < mid) 
        update(LC(v), l, mid, pos, val);
    else 
        update(RC(v), mid, r, pos, val);
    pull(v);
}

int query(int v, int l, int r, int ql, int qr) {
    if (qr <= ql) return -INF; // prevent empty-range query
    if (ql <= l && r <= qr) return seg[v];
    int mid = (r + l) / 2;
    if (qr <= mid) 
        return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid) 
        return query(RC(v), mid, r, ql, qr);
    else {
        return max(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
    }
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            G[i].clear();
        }
        // edges
        for (int i=0; i<n-1; ++i) {
            int u, v, w; 
            cin >> u >> v >> w;
            --u; --v;
            G[u].push_back(P{v, w, i});
            G[v].push_back(P{u, w, i});
        }
        init();

        string op;
        while (cin >> op) {
            if (op[0] == 'D') break;
            int a, b; cin >> a >> b;
            --a;
            if (op[0] == 'C') {
                update(0, 0, n, pos[mp[a]], b);
            }
            else {
                --b;
                cout << trquery(a, b) << '\n';
            }
        }
    }
    return 0;
}
/*
1
11
1 2 2
1 3 4
2 4 5
2 5 3
3 6 -1 
3 7 1
6 8 3
8 9 6
8 10 -2
8 11 7
Q 6 7
*/