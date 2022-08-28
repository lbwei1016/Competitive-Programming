#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }

    int i;
    for (i=n-1; i>=0; --i) {
        if (mp.count(v[i])) break;
        mp[v[i]]++;
    }
    cout << i+1 << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}