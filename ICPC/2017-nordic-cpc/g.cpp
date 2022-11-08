/*
    Solution:
        首先注意到 penalty <= 1000，所以最高處罰只會到 1e8。於是，若將答對一題標記為 +1e9，
        再減去 penalty，就可以用一個變數表示兩個狀態了！
        接著離散化，再用 BIT 取動態前綴和。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const ll D = 1e9; // +D 表示答對一題
int n, m;
ll v[N];

struct P {
    ll pre, now;
} rec[N];

ll one[N];

void Hash(vector<ll> &all) {
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for (int i=1; i<=m; ++i) {
        rec[i].pre = lower_bound(all.begin(), all.end(), rec[i].pre) - all.begin() + 1;
        rec[i].now = lower_bound(all.begin(), all.end(), rec[i].now) - all.begin() + 1;
        one[i] = lower_bound(all.begin(), all.end(), one[i]) - all.begin() + 1;
    }
}

int bit[N];

void update(int i, int val) {
    while (i < N) {
        bit[i] += val;
        i += i & (-i);
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & (-i);
    }
    return res;
}

int main() {
    io;
    cin >> n >> m;
    vector<ll> all(1);
    all.reserve(N);
    for (int i=1; i<=m; ++i) {
        ll u, pen; cin >> u >> pen;
        rec[i].pre = v[u];
        v[u] += D - pen; // 答對一題 +D
        rec[i].now = v[u];
        one[i] = v[1];
        all.push_back(v[u]);
    }

    Hash(all); 

    for (int i=1; i<=n; ++i) update(1, 1); // initial

    for (int i=1; i<=m; ++i) {
        update(rec[i].pre, -1);
        update(rec[i].now, 1);
        cout << n - query(one[i]) + 1 << '\n';
    }

    return 0;
}