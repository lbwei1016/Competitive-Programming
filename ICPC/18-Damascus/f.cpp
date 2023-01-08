#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MOD = 7901, N = 1005;
ll dic[N];

void precalc() {
    dic[0] = 1;
    for (int i=1; i<N; ++i) {
        dic[i] = dic[i-1] * i;
        dic[i] %= MOD;
    }
}

int main() {
    io;
    precalc();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        map<int, ll> mp;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            mp[v[i]]++;
        }
        ll res = 1;
        for (auto p : mp) {
            res *= dic[p.second];
            res %= MOD;
        }
        cout << res << '\n';
    }
    return 0;
}