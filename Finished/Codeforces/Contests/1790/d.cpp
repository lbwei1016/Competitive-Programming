#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        mp[x]++;
    }

    int res = 0;
    while (mp.size()) {
        auto it = mp.begin(), itt = next(it, 1);
        // cout << it->first << '\n';
        while (itt != mp.end() && itt->first - it->first == 1) {
            if (--it->second == 0) mp.erase(it);
            it = itt;
            itt = next(itt, 1);
        }
        if (--it->second == 0) mp.erase(it);
        ++res;
    }
    cout << res << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}