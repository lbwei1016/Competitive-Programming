#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve() {
    int x; cin >> x;
    int a[4];
    for (int i=1; i<=3; ++i) {
        cin >> a[i];
        // if (a[x] == 0) return false;
    }
    for (int i=1; i<=3; ++i) {
        if (a[i] == i) return false;
    }
    if (a[x] == 0) return false;
    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        bool res = solve();
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}