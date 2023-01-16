#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    freopen("little.in", "r", stdin);
    freopen("little.out", "w", stdout);
    ll n;
    cin >> n;
    if (n == 1 || ((n & (-n)) == n)) {
        puts("-1");
        return 0;
    }

    vector<vector<ll>> ans(1, vector<ll>(n));
    ll n2 = pow(n + 0.5, 1.0/2);
    if (n2 * n2 == n) ans.push_back(vector<ll>{n2, n2});
    if (n2 * (n2 + 1) == n) ans.push_back(vector<ll>{n2, n2 + 1});
    if ((n2 + 1) * (n2 + 1) == n) ans.push_back(vector<ll>{n2 + 1, n2 + 1});

    // k and k+1
    ll bd = min(n, 1000000LL);
    for (ll k=2; k<=bd; ++k) {
        if (n % k) continue;
        vector<ll> res;
            
    }

    return 0;
}