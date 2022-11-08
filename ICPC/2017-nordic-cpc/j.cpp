#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int l, r; cin >> l >> r;
    if (l == 0 && r == 0) {
        cout << "Not a moose";
    }
    else if (l == r) {
        cout << "Even " << 2*l << '\n';
    }
    else {
        cout << "Odd " << max(l, r)*2 << '\n';
    }
    return 0;
}