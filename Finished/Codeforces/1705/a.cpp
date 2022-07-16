#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve() {
    int n, x;
    cin >> n >> x;
    multiset<int> S, SS;
    for (int i=0; i<2*n; ++i) {
        int k; cin >> k;
        S.insert(k);
    }

    auto it = S.begin();
    for (int i=0; i<n; ++i) {
        SS.insert(*it);
        it = S.erase(it);
    }

    it = SS.begin();
    for (int i=0; i<n; ++i) {
        auto itt = S.lower_bound((*it)+x);
        if (itt == S.end()) {
            return false;
        }
        S.erase(itt);
        ++it;
    }
    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        bool ans = solve();
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}