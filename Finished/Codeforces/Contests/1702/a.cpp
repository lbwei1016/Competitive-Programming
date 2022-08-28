#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    ll m; cin >> m;
    ll k = 1;
    if (m == 1) {
        cout << "0\n";
        return;
    }
    while (k < m) k *= 10;
    if (k != m)
        k /= 10;
    cout << m-k << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}