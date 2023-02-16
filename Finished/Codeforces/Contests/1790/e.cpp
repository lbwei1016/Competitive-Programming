#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int x; cin >> x;
    if (x & 1) {
        cout << "-1\n";
        return;
    }
    int a = x, b = x / 2;
    bitset<32> aa = a, bb = b;
    for (int i=0; i<32; ++i) {
        if (aa[i] && bb[i]) {
            cout << "-1\n";
            return;
        } 
    }
    cout << a + b << ' ' << b << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}