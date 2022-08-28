/*
***Tree*** --buttom-up
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    ll l, r, val;
};

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n+1), deg(n+1);
        vector<P> range(n+1);
        for (int i=2; i<=n; ++i) {
            int px; cin >> px;
            p[i] = px;
            deg[px]++;
        }
        for (int i=1; i<=n; ++i) {
            ll l, r;
            cin >> l >> r;
            range[i] = {l, r, 0};
        }

        queue<int> que;
        for (int i=1; i<=n; ++i) {
            if (deg[i] == 0) que.push(i);
        }

        ll res = 0;
        while (que.size()) {
            int v = que.front(); que.pop();
            if (range[v].val < range[v].l) {
                ++res;
                range[v].val = range[v].r;
            }
            range[v].val = min(range[v].val, range[v].r);
            range[p[v]].val += range[v].val;
            if (--deg[p[v]] == 0) que.push(p[v]);
        }
        cout << res << '\n';
    }
    return 0;
}