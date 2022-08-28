#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int calc(int a, int b, int c) {
    return (a^b) + (b^c) + (c^a);
}

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "-1\n";
    }
    else {
        int k = n / 2, tmp = k;
        int r = 1;
        while (!(tmp & 1)) {
            r <<= 1;
            tmp >>= 1;
        }
        r >>= 1;
        k |= r;
        cout << k << ' ' << k << ' ' << r << '\n';
        // cout << "GOOD:" << calc(k, k, r) << '\n';
    }
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    // cout << calc(1023, 1023, 0);
    return 0;
}