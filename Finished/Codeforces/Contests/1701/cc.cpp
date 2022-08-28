#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool calc(int t, map<int, int> &mp, const int n) {
    ll can = 0;
    for (int i=1; i<=n; ++i) {
        ll r = min(t, mp[i]); // do 1-hour tasks
        can += (t - r) / 2; // help others
        can -= mp[i] - r; // too many tasks (cannot finish in time; proficient ones)
    }
    return can >= 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i=1; i<=m; ++i) {
        int x; cin >> x;
        mp[x]++;
    }

    int lb = 0, ub = 1e6;
    while (ub-lb > 1) {
        int mid = (lb + ub) / 2;
        if (calc(mid, mp, n)) 
            ub = mid;
        else lb = mid;
    }
    cout << ub << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}