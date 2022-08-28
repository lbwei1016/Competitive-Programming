#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    string bb(++b.begin(), b.end());
    string aa(a.begin()+(n-m+1), a.end());
    if (aa != bb) return false;
    if (a.find(b[0]) > n-m) return false;
    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        bool ans = solve();
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}