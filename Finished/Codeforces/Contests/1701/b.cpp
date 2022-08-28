#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int d = 2;
    cout << d << '\n';
    int k = 0, i = 1;
    while (k < n) {
        for (int x=i; x<=n && k<n; x*=2, ++k) {
            cout << x << ' ';
        }
        i += 2;
    }
    cout << '\n';
}

int main() {
    // io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}