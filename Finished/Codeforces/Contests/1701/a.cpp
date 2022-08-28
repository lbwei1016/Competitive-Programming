#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    vector<int> G(4);
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            int x; cin >> x;
            G[2*i+j] = x;
        }
    }

    if (G == vector<int>{0, 0, 0, 0}) cout << "0\n";
    else if (G == vector<int>{1, 1, 1, 1}) cout << "2\n";
    else cout << "1\n";
}

int main() {
    // io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}