#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    map<char, int> mp;
    for (int i=0; i<n; ++i) {
        char c; cin >> c;
        mp[c]++;
    }
    ll sum = 0;
    for (auto p: mp) {
        sum += 2 + p.second - 1;
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
