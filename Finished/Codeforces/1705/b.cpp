#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    vector<pair<ll, ll>> u;
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        if (i == n-1) break;
        if (v[i] != 0) {
            u.push_back({v[i], i});
        }
    }

    u.push_back({0, n-1});
    for (int i=u.size()-2; i>=0; --i) {
        auto &p1 = u[i], &p2 = u[i+1];
        ll zero = p2.second - p1.second - 1;
        sum += p1.first + zero;
        zero -= (p2.first - 1);
        p2.second += max(0LL, zero);
    }
    cout << sum << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
/*
2 1 2 1 3 6
0 1 2 1 3 8 /+2
0 0 2 1 3 8
0 0 0 

2 0 0 0 2 0
1 1 0 0 1 1
0 2 0 0 1 1
0 1 1 0 1 1
0 0 2 0 1 1
0 0 1 1 1 1
0 0 0 1 1 2
0 0 0 0 1 3
0 0 0 0 0 4

1 1 0 0 1 1
0 1 1 0 1 1
0 0 1 1 1 1
0 0 0 1 1 2
0 0 0 0 1 3
0 0 0 0 0 4
*/