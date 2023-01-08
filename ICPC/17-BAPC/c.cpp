#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    vector<ll> GCD(n);
    map<ll, ll> mp;
    int len = 0;
    for (int i=0; i<n; ++i) {
        ll val; cin >> val;
        for (int j=0; j<len; ++j) {
            GCD[j] = __gcd(GCD[j], val);
            mp[GCD[j]]++;
        }
        GCD[len++] = val; mp[val]++;
        sort(GCD.begin(), GCD.begin() + len);
        len = unique(GCD.begin(), GCD.begin() + len) - GCD.begin();
    }
    cout << mp.size() << '\n';
    return 0;
}