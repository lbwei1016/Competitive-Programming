#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

// remove trailing zeros
int del0(int x) {
    while (!(x & 1)) x >>= 1;
    return x;
}

bool solve() {
    int n; cin >> n;
    map<int, int> a, b;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        x = del0(x);
        a[x]++;
    }
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        x = del0(x);
        if (a.count(x)) {
            if (--a[x] == 0) a.erase(x);
        }
        else b[x]++;
    }

    for (auto p: b) {
        int t = p.second;
        while (t--) {
            bool good = false;
            int x = p.first;
            while (x > 0) {
                x >>= 1;
                if (a.count(x)) {
                    if (--a[x] == 0) a.erase(x);
                    good = true;
                    break;
                }
            }
            if (!good) return false;
        }
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