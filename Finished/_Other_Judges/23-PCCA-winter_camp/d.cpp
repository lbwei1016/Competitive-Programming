#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1), pos(n + 1);
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    // for (auto x: pos) cout << x << ' ';

    vector<pair<int, int>> res;
    for (int i=1; i<=n; ++i) {
        int a = pos[i];
        if (a == i) continue;
        // cout << i << ' ' << a << '\n';
        res.push_back({i, a});
        swap(v[i], v[pos[i]]);
        int tmp = v[pos[i]];
        pos[i] = i;
        pos[tmp] = a;
        // cout << v[i] << ' ' << v[pos[i]] << '\n'; 
        // cout << v[i] << '\n';
        // for (auto x: v) cout << x << ' ';
        // cout << '\n';
    }
    cout << res.size() << '\n';
    for (auto x: res) {
        if (x.first > x.second) swap(x.first, x.second);
        cout << x.first << ' ' << x.second << '\n';
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